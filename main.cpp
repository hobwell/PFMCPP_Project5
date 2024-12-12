/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

7) If you were using any UDTs as function arguments like this:
*/
#if false
void someMemberFunction(Axe axe);
#endif
/*
  Pass those arguments by Reference now that you know what references are (Project 6 Part 2).
*/
#if false
void someMemberFunction(Axe& axe);
#endif
/*
If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
Additionally, you can mark class member functions as 'const'
If you do this, you are promising that the member function will not modify any member variables.

Mark every member function that is not modifying any member variables as 'const'
*/
#if false
//a function where the argument is passed by const-ref
void someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 Clear any warnings about exit-time-destructors.
 Suppress them by adding -Wno-exit-time-destructors to the .replit file with the other warning suppression flags
 */




/*

 Ignore the Atomic.h and LeakedObjectDetector.h files for now.
 You will use those in Part 3 of this project.
*/

#include <iostream>
/*
 copied UDT 1:
 */

struct Treadmill
{
    Treadmill (float weightAllowance = 150.0f);
    ~Treadmill();

    float currentSpeedKph = 0.0f;
    float currentInclinationDegrees = 0.0f;
    float totalDistanceSimulatedKm = 0.0f;
    float sessionDistanceSimulatedKm = 0.0f;
    float maximumWeightAllowanceKg;

    struct ValueDisplay
    {
        ValueDisplay (float val, std::string valName, std::string valUnit);
        ~ValueDisplay();

        std::string name = "";
        std::string unit = "";
        float value = 0.0f;
        std::string colour = "green";
        std::string font = "Arial";
        int fontSize = 12;

        void updateValue (float newValue);
        void changeFont (std::string newFont = "Arial", int newFontSize = 18);
        void changeColour (std::string newColor = "green");
        int growFontSize (int numSteps = 1);
        void growFontSizeAndReportNewFontSize (int numSteps = 1);
        int shrinkFontSize (int numSteps = 1);
        void shrinkFontSizeAndReportNewFontSize (int numSteps = 1);
        void printFontInfo();
    };

    ValueDisplay speedDisplay{ 0.0f, "speed", "km/h" };
    ValueDisplay inclineDisplay{ 0.0f, "incline", "degrees" };

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (ValueDisplay displayValue);
    float run (int numSteps, float strideLength = 0.00065f);
    void printMembers();
};

Treadmill::Treadmill (float weightAllowance)
{
    maximumWeightAllowanceKg = weightAllowance;
    inclineDisplay.colour = "red";
    std::cout << "A Treadmill has been constructed!" << std::endl;
}

Treadmill::~Treadmill()
{
    std::cout << "A treadmill has been destructed." << std::endl;
}

void Treadmill::rotateBelt (float speedKph)
{
    std::cout << "Current Session distance: " << sessionDistanceSimulatedKm << " km!" << std::endl;
    currentSpeedKph = speedKph;
    speedDisplay.updateValue (currentSpeedKph);
    std::cout << "Away we go (at " << currentSpeedKph << " km/h)!" << std::endl;
}

void Treadmill::incline (float inclinationDegrees)
{
    currentInclinationDegrees = inclinationDegrees;
    inclineDisplay.updateValue (currentInclinationDegrees);
    std::cout << "Prepare to climb!" << std::endl;
}

void Treadmill::display (ValueDisplay displayValue)
{
    std::cout << displayValue.name << ": " << displayValue.value << " " << displayValue.unit << std::endl;
}

float Treadmill::run (int numSteps, float strideLength)
{
    for (int i = 0; i < numSteps; ++i)
    {
        if (i % 2 == 0)
            std::cout << "Huff"<< std::endl;
        else
            std::cout << "Puff" << std::endl;
        sessionDistanceSimulatedKm += strideLength;
    }
    
    return sessionDistanceSimulatedKm;
}

void Treadmill::printMembers()
{
    std::cout << "Treadmill: maximumWeightAllowanceKg: " << this->maximumWeightAllowanceKg << std::endl;
    std::cout << "Treadmill: currentSpeedKph: " << this->currentSpeedKph << std::endl;
    std::cout << "Treadmill: currentInclinationDegrees: " << this->currentInclinationDegrees << std::endl;
    std::cout << "Treadmill: totalDistanceSimulatedKm: " << this->totalDistanceSimulatedKm << std::endl;
    std::cout << "Treadmill: sessionDistanceSimulatedKm: " << this->sessionDistanceSimulatedKm << std::endl;    
}


Treadmill::ValueDisplay::ValueDisplay (float val, std::string valName, std::string valUnit)
{
    value = val;
    name = valName;
    unit = valUnit;
    std::cout << "A ValueDisplay has been constructed!" << std::endl;
}

Treadmill::ValueDisplay::~ValueDisplay()
{
    std::cout << "A ValueDisplay has been destructed!" << std::endl;
}

void Treadmill::ValueDisplay::updateValue (float newValue)
{
    std::cout << "Changing " << name << " from " << value << " to " << newValue << " " << unit << std::endl;
    value = newValue;    
}

void Treadmill::ValueDisplay::changeFont (std::string newFont, int newFontSize)
{
    std::cout << "Changing font from " << font << " " << fontSize << "pt to " << newFont << " " << newFontSize << "pt" << std::endl;
    font = newFont;
    fontSize = newFontSize;
}

void Treadmill::ValueDisplay::changeColour (std::string newColor)
{
    colour = newColor;
}

int Treadmill::ValueDisplay::growFontSize (int numSteps)
{   
    if (numSteps > 0)
    {
        std::cout << "Growing font size ";
        
        for (int i = 0; i < numSteps; ++i)
        {
            fontSize += 1;
            std::cout << ".";
        }
        
        std::cout << std::endl;
    }
    else 
    {
        std::cout << "numSteps must be greater than 0 for growFontSize to work." << std::endl;
    }
        
    return fontSize;
}

int Treadmill::ValueDisplay::shrinkFontSize (int numSteps)
{   
    if (numSteps > 0)
    {
        std::cout << "Shrinking font size ";
        int i = 0;
        
        while (i < numSteps && fontSize > 0)
        {
            fontSize -= 1;
            std::cout << ".";
            
            if (fontSize < 1)
            {
                std::cout << std::endl << "Font size can't shrink any further!";
            }
            
            i += 1;
        }
        
        std::cout << std::endl;
    }
    else 
    {
        std::cout << "numSteps must be greater than 0 for shrinkFontSize to work." << std::endl;
    }
        
    return fontSize;
}

void Treadmill::ValueDisplay::growFontSizeAndReportNewFontSize (int numSteps)
{
    std::cout << "New font size: " << this->growFontSize (numSteps) << std::endl;
}

void Treadmill::ValueDisplay::shrinkFontSizeAndReportNewFontSize (int numSteps)
{
    std::cout << "New font size: " << this->shrinkFontSize (numSteps) << std::endl;
}

void Treadmill::ValueDisplay::printFontInfo()
{
    std::cout << this->name << " (" << this->font << ", " << this->fontSize << "pt, " << this->colour << "): " << this->value << " " << this->unit << std::endl;
}

/*
 copied UDT 2:
 */

struct Cat
{
    Cat (std::string pattern, std::string colour);
    ~Cat();

    std::string furPattern = "tabby";
    std::string furColour = "orange";
    std::string eyeColour = "green";
    char sex = 'F';
    int age = 3;

    bool hunt (std::string creature);
    void eat (float amountOfFoodKg);
    void purr (float volumeDb);
    int unrollToiletPaper (int numSwipes = 4, int squaresRemaining = 400);
    void printMembers();
};

Cat::Cat (std::string pattern, std::string colour)
{
    furPattern = pattern;
    furColour = colour;
    std::cout << "A Cat has been constructed!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "A Cat has been destructed." << std::endl;
}

bool Cat::hunt (std::string creature)
{
    std::cout << "The " << eyeColour << "-eyed cat is hunting a " << creature << "!" << std::endl;

    if (creature == "mouse")
    {
        std::cout << "The cat pounces and catches a mouse!" << std::endl;
        return true;
    }

    if (creature == "bird")
    {
        std::cout << "The cat leaps into the air, snagging a bird with its paw." << std::endl;
        return true;
    }

    std::cout << "The cat chases the " << creature << ", but is unable to catch it." << std::endl;

    return false;
}

void Cat::eat (float amountOfFoodKg)
{
    if (amountOfFoodKg > 0.0f)
        std::cout << "nom nom nom" << std::endl;
    else
        std::cout << "meow" << std::endl;
}

void Cat::purr (float volumeDb)
{
    if (volumeDb <= 0.0f)
    {
        std::cout << std::endl;
    }
    else if (volumeDb <= 50.0f)
    {
        std::cout << "purrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr" << std::endl;
    }
    else
    {
        std::cout << "PURRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRRR" << std::endl;
    }
}

int Cat::unrollToiletPaper (int numSwipes, int squaresRemaining)
{
    if (numSwipes > 0)
    {
        while (numSwipes > 0 && squaresRemaining > 0)
        {
            std::cout << "*bat* ";
            numSwipes -= 1;
            squaresRemaining -= 10;
        }
        
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Luckily, cats haven't figured out how to take negatve swipes yet." << std::endl;
    }
    
    return squaresRemaining;
}

void Cat::printMembers()
{
    std::cout << "Cat: furPattern: " << this->furPattern << std::endl;
    std::cout << "Cat: furColour: " << this->furColour << std::endl;
    std::cout << "Cat: eyeColour: " << this->eyeColour << std::endl;
    std::cout << "Cat: age: " << this->age << std::endl;
    std::cout << "Cat: sex: " << this->sex << std::endl;
}

/*
 copied UDT 3:
 */
struct Fruit
{
    Fruit();
    ~Fruit();
    
    float endospermLevel = 0.05f;
    float hydrationLevel = 0.05f;
    float epicarpThicknessCm = 0.05f;
    float mesocarpThicknessCm = 0.05f;

    struct Seed
    {
        Seed(int germinationDays);
        ~Seed();

        float weightGrams = 0.05f;
        float coatIntegrity = 1.0f;
        int daysToGerminate = 15;
        float storedEnergy = 0.0f;
        int daysDormant = 0;
        int totalLeaves = 0;

        bool growRoot (bool germinated = false);
        bool growStem (bool germinated = false);
        int growLeaves (bool germinated = false, int numLeaves = 2);
        bool germinate (int days);
        void printMembers();
    };

    Seed seed{15};

    void protectSeed (float increment);
    Seed disperseSeed (float distanceKm);
    float feedSeed (float energy);
    float decay (int days);
    void feedSeedAndPrintSeedEnergy (float energy);
    void printMembers();
};

Fruit::Fruit()
{
    std::cout << "A Fruit has been constructed!" << std::endl;
}

Fruit::~Fruit()
{
    std::cout << "A Fruit has been destructed." << std::endl;
}

void Fruit::protectSeed (float increment)
{
    std::cout << "Hydration level: " << hydrationLevel << std::endl;
    epicarpThicknessCm += increment;
    mesocarpThicknessCm += increment / 2.0f;
    seed.weightGrams += increment / 10.0f;
}

Fruit::Seed Fruit::disperseSeed (float distanceKm)
{
    seed.daysDormant = 0;
    seed.coatIntegrity -= distanceKm / 100.0f;

    return seed;
}

float Fruit::feedSeed (float energy)
{
    seed.storedEnergy += energy;

    return seed.storedEnergy;
}

void Fruit::feedSeedAndPrintSeedEnergy (float energy)
{
    std::cout << std::endl << this->feedSeed (energy) << " total energy stored." << std::endl;
}

float Fruit::decay (int days)
{
    float integrity = (endospermLevel + hydrationLevel + epicarpThicknessCm + mesocarpThicknessCm) / 4.0f;
    
    for (int i = 0; i < days; ++i)
    {
        endospermLevel *= 0.95f;
        hydrationLevel *= 0.95f;
        epicarpThicknessCm *= 0.95f;
        mesocarpThicknessCm *= 0.95f;
        feedSeed(0.005f);

        if (integrity < 0.5f)
        {
            std::cout << "Fruit has decayed." << std::endl;
            return integrity;
        }
    }
    
    return integrity;
}

void Fruit::printMembers()
{
    std::cout << "Fruit: endospermLevel: " << this->endospermLevel << std::endl;
    std::cout << "Fruit: hydrationLevel: " << this->hydrationLevel << std::endl;
    std::cout << "Fruit: epicarpThicknessCm: " << this->epicarpThicknessCm << std::endl;
    std::cout << "Fruit: mesocarpThicknessCm: " << this->mesocarpThicknessCm << std::endl; }

Fruit::Seed::Seed(int germinationDays)
{
    daysToGerminate = germinationDays;
    std::cout << "A Seed has been constructed!" << std::endl;
}

Fruit::Seed::~Seed()
{
    std::cout << "A Seed has been destructed." << std::endl;
}

bool Fruit::Seed::growRoot (bool germinated)
{
    if (germinated)
    {
        std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
        if (coatIntegrity < 0.75f)
        {
            storedEnergy -= 0.04f;
            coatIntegrity -= 0.05f;
            std::cout << "Root grows!" << std::endl;

            return true;
        }

        coatIntegrity -= 0.03f;
    }

    return false;
}

bool Fruit::Seed::growStem (bool germinated)
{
    if (germinated)
    {
         std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
        if (coatIntegrity < 0.5f)
        {
            storedEnergy -= 0.07f;
            coatIntegrity -= 0.075f;
            std::cout << "Stem grows!" << std::endl;

            return true;
        }

        coatIntegrity -= 0.04f;
    }

    return false;
}

int Fruit::Seed::growLeaves (bool germinated, int numLeaves)
{
    if (germinated)
    {
        std::cout << "Coat Integrity: " << coatIntegrity << std::endl;
        
        if (coatIntegrity < 0.25f)
        {
            storedEnergy -= 0.04f;
            coatIntegrity = 0;
            totalLeaves += numLeaves;
            std::cout << totalLeaves << " leaves are growing!" << std::endl;
        }

        coatIntegrity -= 0.02f;
    }

    return totalLeaves;
}

bool Fruit::Seed::germinate (int days)
{
    bool germinated = false;
    bool enoughEnergy = true;

    if (days > 0)
    {
        for (int i = 0; i < days; ++i)
        {
            storedEnergy -= 0.001f;
            daysDormant += days;
            std::cout << "Germinating..." << std::endl;
            
            if (storedEnergy < 0.75f)
            {
                std::cout << "Seed is no longer viable.  Not enough energy." << std::endl;
                i = days;
                enoughEnergy = false;
            }
        }

        germinated = enoughEnergy && daysDormant > daysToGerminate;
    }
    else
    {
        std::cout << "Days must be positive." << std::endl;
    }

    if (germinated)
        std::cout << "Seed germinated!" << std::endl;
    
    return germinated;
}

void Fruit::Seed::printMembers()
{
    std::cout << "Seed: weightGrams: " << this->weightGrams << std::endl;
    std::cout << "Seed: coatIntegrity: " << this->coatIntegrity << std::endl;
    std::cout << "Seed: daysToGerminate: " << this->daysToGerminate << std::endl;
    std::cout << "Seed: storedEnergy: " << this->storedEnergy << std::endl;
    std::cout << "Seed: daysDormant: " << this->daysDormant << std::endl;
    std::cout << "Seed: totalLeaves: " << this->totalLeaves << std::endl;
}

/*
 new UDT 4:
 with 2 member functions
 */
struct Person
{
    Person();
    ~Person();

    Cat dali{"tabby", "orange"};
    Cat geisha{"tabby", "grey"};
    Treadmill treadmill{300.0f};
    Treadmill::ValueDisplay temperatureDisplay{23.0f, "temperature", "C"};

    void feedCat (float amountOfFoodKg, Cat cat);
    float excercise (int timeInMinutes, float strideLength = 0.65f);
};

Person::Person()
{
    geisha.eyeColour = "blue";
    std::cout << std::endl << "A person appears!" << std::endl;
    std::cout << "Cats haven't ever been fed!" << std::endl;
    feedCat (0.125f, dali);
    feedCat (0.125f, geisha);
    std::cout << "Cats are now fed! (not really)" << std::endl;
}

Person::~Person()
{
    std::cout << std::endl << "As their last act, the cats have a bit of fun." << std::endl;
    geisha.hunt("mouse");
    dali.unrollToiletPaper(11, 400);
}

void Person::feedCat (float amountOfFoodKg, Cat cat) // not using pointers yet...
{
    cat.eat (amountOfFoodKg);
}

float Person::excercise (int timeInMinutes, float strideLength)
{
    std::cout << std::endl << "Let's cool things off before we excersise!" << std::endl;
    temperatureDisplay.updateValue (20.5f);
    int numSteps = timeInMinutes * 27;
    treadmill.rotateBelt (2.0f);
    treadmill.display (treadmill.speedDisplay);
    float distance = treadmill.run (numSteps, strideLength);
    std::cout << "Great job!  Time to excercise the cats!" << std::endl;
    dali.hunt ("red dot");
    geisha.hunt ("colorful feather");
    
    return distance;
}
/*
 new UDT 5:
 with 2 member functions
 */
struct TrashBin
{
    TrashBin();
    ~TrashBin();

    Cat niceCat{"calico", "white-orange-black"};
    Cat alleyCat{"solid", "black"};
    Cat smellyCat{"bi-color", "white-black"};
    Treadmill treadmill{100.0f};
    Fruit avocado;
    Fruit watermelon;
    Fruit::Seed seed;

    bool attractCat (float smellIntensity, Cat cat);
    float fester();
};

TrashBin::TrashBin() : seed{15}
{
    std::cout << std::endl << "A TrashBin has popped into existence, complete with trash (and cats)!" << std::endl;
    std::cout << "The smell is attacting some cats!" << std::endl;

    Cat randoCat{"tabby", "white"};
    attractCat (10.0f, randoCat);
}

TrashBin::~TrashBin()
{
    std::cout << std::endl << "The cats feast!" << std::endl;
    niceCat.eat (0.125f);
    alleyCat.eat (0.125f);
    smellyCat.eat (0.125f);
    std::cout << "A trash collector comes to reap a TrashBin." << std::endl;
    std::cout << "The trash collector takes the cats with them." << std::endl;
}

bool TrashBin::attractCat (float smellIntensity, Cat cat)
{
    std::cout << std::endl;
    
    if (smellIntensity >= 100.0f)
    {
        std::cout << "The smell has become too intense for the " << smellyCat.furColour << " " << smellyCat.furPattern << " cat!" << std::endl;
        smellyCat = cat;
    } 
    else if (smellIntensity >= 10.0f)
    {
        std::cout << "The smell has become too intense for the " << alleyCat.furColour << " " << alleyCat.furPattern << " cat!" << std::endl;
        alleyCat = cat;
    }
    else if (smellIntensity >= 1.0f)
    {
        std::cout << "The smell has become too intense for the " << niceCat.furColour << " " << niceCat.furPattern << " cat!" << std::endl;
        niceCat = cat;
    }
    else
    {
        std::cout << "The smell was not interesting enough to retain or repel any cats.";
        return false;
    }

    std::cout << "A " << cat.furColour << " " << cat.furPattern << " cat takes their place." << std::endl;
    
    return true; // a cat was attracted
}

float TrashBin::fester()
{
    float smellIntensity = 0.0f;
    smellIntensity += 10.0f / avocado.decay(1);
    smellIntensity += 10.0f / watermelon.decay(1);
    
    return smellIntensity;
}
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */


int main()
{
    Treadmill::ValueDisplay maxWeightDisplay{ 200.0f, "max weight", "kg" };
    maxWeightDisplay.changeFont ("Times New Roman", 24);
    maxWeightDisplay.changeColour ("Blue");
    
    std::cout << maxWeightDisplay.name << " (" << maxWeightDisplay.font << ", " << maxWeightDisplay.fontSize << "pt, " << maxWeightDisplay.colour << "): " << maxWeightDisplay.value << " " << maxWeightDisplay.unit << std::endl;
    maxWeightDisplay.printFontInfo();
    
    std::cout << std::endl;

    maxWeightDisplay.changeColour ("Orange");
    maxWeightDisplay.updateValue (250.0f);
    maxWeightDisplay.changeFont ("Helvetica", 18);

    std::cout << std::endl;

    std::cout << "New font size: " << maxWeightDisplay.shrinkFontSize (-1) << std::endl;
    maxWeightDisplay.shrinkFontSizeAndReportNewFontSize (-1);

    std::cout << "New font size: " << maxWeightDisplay.shrinkFontSize (maxWeightDisplay.fontSize) << std::endl;
    maxWeightDisplay.shrinkFontSizeAndReportNewFontSize (maxWeightDisplay.fontSize);
    
    std::cout << "New font size: " << maxWeightDisplay.growFontSize (12) << std::endl;
    maxWeightDisplay.growFontSizeAndReportNewFontSize (12);
    
    std::cout << "New font size: " << maxWeightDisplay.growFontSize (-6) << std::endl;
    maxWeightDisplay.growFontSizeAndReportNewFontSize (-6);
    
    std::cout << std::endl;
    
    Treadmill treadmill{ maxWeightDisplay.value };
    std::cout << "treadmill: maximumWeightAllowanceKg: " << treadmill.maximumWeightAllowanceKg << std::endl;
    std::cout << "treadmill: currentSpeedKph: " << treadmill.currentSpeedKph << std::endl;
    std::cout << "treadmill: currentInclinationDegrees: " << treadmill.currentInclinationDegrees << std::endl;
    std::cout << "treadmill: totalDistanceSimulatedKm: " << treadmill.totalDistanceSimulatedKm << std::endl;
    std::cout << "treadmill: sessionDistanceSimulatedKm: " << treadmill.sessionDistanceSimulatedKm << std::endl;
    treadmill.printMembers();
    
    std::cout << std::endl;

    treadmill.rotateBelt (10.0f);
    treadmill.incline (5.0f);
    treadmill.display (treadmill.speedDisplay);
    treadmill.display (treadmill.inclineDisplay);
    treadmill.display (maxWeightDisplay);

    std::cout << std::endl;

    auto distanceRun = treadmill.run (4);
    std::cout << "Distance run: " << distanceRun << std::endl << std::endl;
    distanceRun = treadmill.run (10);
    std::cout << "Distance run: " << distanceRun << std::endl;

    std::cout << std::endl;
    
    Cat tuxedoCat{ "tuxedo", "black" };
    std::cout << "tuxedoCat: furPattern: " << tuxedoCat.furPattern << std::endl;
    std::cout << "tuxedoCat: furColour: " << tuxedoCat.furColour << std::endl;
    std::cout << "tuxedoCat: eyeColour: " << tuxedoCat.eyeColour << std::endl;
    std::cout << "tuxedoCat: age: " << tuxedoCat.age << std::endl;
    std::cout << "tuxedoCat: sex: " << tuxedoCat.sex << std::endl;
    tuxedoCat.printMembers();
    
    std::cout << std::endl;

    if (tuxedoCat.hunt ("mouse"))
        std::cout << "The cat caught the mouse!" << std::endl;

    if (!tuxedoCat.hunt ("red dot"))
        std::cout << "The cat is still chasing the red dot." << std::endl;

    tuxedoCat.eat (0.5f);
    tuxedoCat.purr (50.0f);

    std::cout << std::endl;

    std::cout << "The cat has found a roll of toilet paper." << std::endl;
    int squaresLeft = tuxedoCat.unrollToiletPaper (3);
    std::cout << "Squares left: " << squaresLeft << std::endl;
    squaresLeft = tuxedoCat.unrollToiletPaper (5, squaresLeft);
    std::cout << "Squares left: " << squaresLeft << std::endl;
    
    std::cout << std::endl;

    Fruit fruit;
    std::cout << "fruit: endospermLevel: " << fruit.endospermLevel << std::endl;
    std::cout << "fruit: hydrationLevel: " << fruit.hydrationLevel << std::endl;
    std::cout << "fruit: epicarpThicknessCm: " << fruit.epicarpThicknessCm << std::endl;
    std::cout << "fruit: mesocarpThicknessCm: " << fruit.mesocarpThicknessCm << std::endl;
    fruit.printMembers();
    
    std::cout << std::endl;

    fruit.hydrationLevel = 2.0f;
    fruit.protectSeed (1.0f);
    std::cout << std::endl << fruit.feedSeed (1.5f) << " total energy stored." << std::endl;
    fruit.feedSeedAndPrintSeedEnergy (1.5f);
    
    std::cout << std::endl;

    float fruitIntegrity = fruit.decay (5);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruit.decay (10);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruit.decay (7);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    
    std::cout << std::endl;
    
    Fruit::Seed newSeed = fruit.disperseSeed (10.0f);
    std::cout << "newSeed: weightGrams: " << newSeed.weightGrams << std::endl;
    std::cout << "newSeed: coatIntegrity: " << newSeed.coatIntegrity << std::endl;
    std::cout << "newSeed: daysToGerminate: " << newSeed.daysToGerminate << std::endl;
    std::cout << "newSeed: storedEnergy: " << newSeed.storedEnergy << std::endl;
    std::cout << "newSeed: daysDormant: " << newSeed.daysDormant << std::endl;
    std::cout << "newSeed: totalLeaves: " << newSeed.totalLeaves << std::endl;
    newSeed.printMembers();
    
    std::cout << std::endl;
    
    Fruit::Seed seed{20};
    seed.storedEnergy = 1.0f;
    std::cout << "seed: weightGrams: " << seed.weightGrams << std::endl;
    std::cout << "seed: coatIntegrity: " << seed.coatIntegrity << std::endl;
    std::cout << "seed: daysToGerminate: " << seed.daysToGerminate << std::endl;
    std::cout << "seed: storedEnergy: " << seed.storedEnergy << std::endl;
    std::cout << "seed: daysDormant: " << seed.daysDormant << std::endl;
    std::cout << "seed: totalLeaves: " << seed.totalLeaves << std::endl;
    seed.printMembers();
    
    std::cout << std::endl;

    auto germinated = seed.germinate (25.0f);
    
    std::cout << std::endl;

    while (germinated && !seed.growRoot (germinated))
    {
        std::cout << "Seed root is not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    while (germinated && !seed.growStem (germinated))
    {
        std::cout << "Seed stem is not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    while (germinated && seed.growLeaves (germinated, 10) < 10)
    {
        std::cout << "Seed leaves are not yet ready." << std::endl;
        std::cout << "Time passes..." << std::endl;
    }

    seed.growLeaves (germinated, 10);

    std::cout << std::endl;

    Person someone;
    float distance = someone.excercise (10, 0.00124f);
    std::cout << "someone ran " << distance << " km." << std::endl;
    std::cout << "someone feeds the neighborhood stray." << std::endl;
    someone.feedCat (0.125f, tuxedoCat);
    
    std::cout << std::endl;

    TrashBin trashBin;

    float smellIntensity = trashBin.fester();
    bool catAttracted = trashBin.attractCat (smellIntensity, tuxedoCat);
    
    while (! catAttracted)
    {
        smellIntensity = trashBin.fester();
        catAttracted = trashBin.attractCat (smellIntensity, tuxedoCat);
    }
    
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
