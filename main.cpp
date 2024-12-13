/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
         Don't forget the '#pragma once'
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp, which goes along with instruction 5): 
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
        Chances are extremely high that you implemented your 
        wrapper class functions in-class, because that is what 
        everyone does after watching the video where I implemented 
        them in-class.
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.

 7) When you add the #include statements for your refactored source files into main.cpp: 
        '#include "Wrappers.h"' should be the first file that you include after LeakedObjectDetector.h
 
 8) Go through every cpp file and header file. check all function implementations for the following:
        Can this function argument be declared as 'const'? 
        Can this function be declared as 'const'?
        You learned about 'const' function arguments and 'const' functions in Project 5 Part 3
        As a refresher:
            If you aren't modifying the passed-in object inside the function, pass by 'const reference'.
            Marking a function parameter as 'const' means that you are promising that the parameter will not be modified.
            Additionally, you can mark class member functions as 'const'
            If you do this, you are promising that the member function will not modify any member variables.

        Mark every member function that is not modifying any member variables as 'const'
        Mark every function parameter that is not modified inside the function as 'const'
*/
#if false
//a function where the argument is passed by const-ref.
void Foo::someMemberFunction(const Axe& axe);

//a member function that is marked const, meaning it will not modify any member variables of the 'Axe' class.
void Axe::aConstMemberFunction() const { }
#endif
/*
 9) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
         tip: you cannot forward-declare nested types!  
         The file that a nested type is defined in MUST be included wherever that nested type is written.
 */




#include <iostream>
#include "LeakedObjectDetector.h"
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
        void printFontInfo() const;

        JUCE_LEAK_DETECTOR (ValueDisplay)
    };

    ValueDisplay speedDisplay{ 0.0f, "speed", "km/h" };
    ValueDisplay inclineDisplay{ 0.0f, "incline", "degrees" };

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (const ValueDisplay& displayValue) const;
    float run (int numSteps, float strideLength = 0.00065f);
    void printMembers() const;

    JUCE_LEAK_DETECTOR (Treadmill)
};

struct TreadmillWrapper
{
    TreadmillWrapper (Treadmill* t) : treadmill (t) {}

    ~TreadmillWrapper()
    {
		delete treadmill;
    }

    Treadmill* treadmill = nullptr;
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

void Treadmill::display (const ValueDisplay& displayValue) const
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

void Treadmill::printMembers() const
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

void Treadmill::ValueDisplay::printFontInfo() const
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

    bool hunt (std::string creature) const;
    void eat (float amountOfFoodKg) const;
    void purr (float volumeDb) const;
    int unrollToiletPaper (int numSwipes = 4, int squaresRemaining = 400) const;
    void printMembers() const;

    JUCE_LEAK_DETECTOR (Cat)
};

struct CatWrapper
{
    CatWrapper (Cat* c) : cat (c) {}

    ~CatWrapper()
    {
		delete cat;
    }

    Cat* cat = nullptr;
};

Cat::Cat (std::string pattern, std::string colour)
{
    furPattern = pattern;
    furColour = colour;
    std::cout << "A Cat has been constructed!" << std::endl;
}

Cat::~Cat()
{
    std::cout << "A " << this->furColour << " " << this->furPattern << " Cat has been destructed." << std::endl;
}

bool Cat::hunt (std::string creature) const
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

void Cat::eat (float amountOfFoodKg) const
{
    if (amountOfFoodKg > 0.0f)
        std::cout << "nom nom nom" << std::endl;
    else
        std::cout << "meow" << std::endl;
}

void Cat::purr (float volumeDb) const
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

int Cat::unrollToiletPaper (int numSwipes, int squaresRemaining) const
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

void Cat::printMembers() const
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
        void printMembers() const;

        JUCE_LEAK_DETECTOR (Seed)
    };

    Seed seed{15};

    void protectSeed (float increment);
    Seed disperseSeed (float distanceKm);
    float feedSeed (float energy);
    float decay (int days);
    void feedSeedAndPrintSeedEnergy (float energy);
    void printMembers() const;

    JUCE_LEAK_DETECTOR (Fruit)
};

struct FruitWrapper
{
    FruitWrapper (Fruit* f) : fruit (f) {}

    ~FruitWrapper()
    {
		delete fruit;
    }

    Fruit* fruit = nullptr;
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

void Fruit::printMembers() const
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

void Fruit::Seed::printMembers() const
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

    void feedCat (float amountOfFoodKg, const Cat& cat) const;
    float excercise (int timeInMinutes, float strideLength = 0.65f);

   JUCE_LEAK_DETECTOR (Person)
};

struct PersonWrapper
{
    PersonWrapper (Person* p) : person (p) {}

    ~PersonWrapper()
    {
		delete person;
    }

    Person* person = nullptr;
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

void Person::feedCat (float amountOfFoodKg, const Cat& cat) const
{
    cat.eat (amountOfFoodKg);
}

float Person::excercise (int timeInMinutes, float strideLength)
{
    std::cout << std::endl << "Let's cool things off before we excercise!" << std::endl;
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
    TrashBin (Cat& nearbyCat);
    ~TrashBin();

    Cat niceCat{"calico", "white-orange-black"};
    Cat alleyCat{"solid", "black"};
    Cat smellyCat{"bi-color", "white-black"};
    Treadmill treadmill{100.0f};
    Fruit avocado;
    Fruit watermelon;
    Fruit::Seed seed;

    bool attractCat (float smellIntensity, const Cat& cat);
    float fester();

    JUCE_LEAK_DETECTOR (TrashBin)
};

struct TrashBinWrapper
{
    TrashBinWrapper (TrashBin* tb) : trashBin (tb) {}

    ~TrashBinWrapper()
    {
		delete trashBin;
    }

    TrashBin* trashBin = nullptr;
};

TrashBin::TrashBin (Cat& nearbyCat) : seed{15}
{
    std::cout << std::endl << "A TrashBin has popped into existence, complete with trash (and cats)!" << std::endl;
    std::cout << "The smell is attacting some cats!" << std::endl;

    attractCat (10.0f, nearbyCat);
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

bool TrashBin::attractCat (float smellIntensity, const Cat& cat)
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
    
    TreadmillWrapper treadmillWrapper (new Treadmill{ maxWeightDisplay.value });
    std::cout << "treadmill: maximumWeightAllowanceKg: " << treadmillWrapper.treadmill->maximumWeightAllowanceKg << std::endl;
    std::cout << "treadmill: currentSpeedKph: " << treadmillWrapper.treadmill->currentSpeedKph << std::endl;
    std::cout << "treadmill: currentInclinationDegrees: " << treadmillWrapper.treadmill->currentInclinationDegrees << std::endl;
    std::cout << "treadmill: totalDistanceSimulatedKm: " << treadmillWrapper.treadmill->totalDistanceSimulatedKm << std::endl;
    std::cout << "treadmill: sessionDistanceSimulatedKm: " << treadmillWrapper.treadmill->sessionDistanceSimulatedKm << std::endl;
    treadmillWrapper.treadmill->printMembers();
    
    std::cout << std::endl;

    treadmillWrapper.treadmill->rotateBelt (10.0f);
    treadmillWrapper.treadmill->incline (5.0f);
    treadmillWrapper.treadmill->display (treadmillWrapper.treadmill->speedDisplay);
    treadmillWrapper.treadmill->display (treadmillWrapper.treadmill->inclineDisplay);
    treadmillWrapper.treadmill->display (maxWeightDisplay);

    std::cout << std::endl;

    auto distanceRun = treadmillWrapper.treadmill->run (4);
    std::cout << "Distance run: " << distanceRun << std::endl << std::endl;
    distanceRun = treadmillWrapper.treadmill->run (10);
    std::cout << "Distance run: " << distanceRun << std::endl;

    std::cout << std::endl;
    
    CatWrapper catWrapper (new Cat{ "tuxedo", "black" });
    std::cout << "tuxedoCat: furPattern: " << catWrapper.cat->furPattern << std::endl;
    std::cout << "tuxedoCat: furColour: " << catWrapper.cat->furColour << std::endl;
    std::cout << "tuxedoCat: eyeColour: " << catWrapper.cat->eyeColour << std::endl;
    std::cout << "tuxedoCat: age: " << catWrapper.cat->age << std::endl;
    std::cout << "tuxedoCat: sex: " << catWrapper.cat->sex << std::endl;
    catWrapper.cat->printMembers();
    
    std::cout << std::endl;

    if (catWrapper.cat->hunt ("mouse"))
        std::cout << "The cat caught the mouse!" << std::endl;

    if (!catWrapper.cat->hunt ("red dot"))
        std::cout << "The cat is still chasing the red dot." << std::endl;

    catWrapper.cat->eat (0.5f);
    catWrapper.cat->purr (50.0f);

    std::cout << std::endl;

    std::cout << "The cat has found a roll of toilet paper." << std::endl;
    int squaresLeft = catWrapper.cat->unrollToiletPaper (3);
    std::cout << "Squares left: " << squaresLeft << std::endl;
    squaresLeft = catWrapper.cat->unrollToiletPaper (5, squaresLeft);
    std::cout << "Squares left: " << squaresLeft << std::endl;
    
    std::cout << std::endl;

    FruitWrapper fruitWrapper(new Fruit);
    std::cout << "fruit: endospermLevel: " << fruitWrapper.fruit->endospermLevel << std::endl;
    std::cout << "fruit: hydrationLevel: " << fruitWrapper.fruit->hydrationLevel << std::endl;
    std::cout << "fruit: epicarpThicknessCm: " << fruitWrapper.fruit->epicarpThicknessCm << std::endl;
    std::cout << "fruit: mesocarpThicknessCm: " << fruitWrapper.fruit->mesocarpThicknessCm << std::endl;
    fruitWrapper.fruit->printMembers();
    
    std::cout << std::endl;

    fruitWrapper.fruit->hydrationLevel = 2.0f;
    fruitWrapper.fruit->protectSeed (1.0f);
    std::cout << std::endl << fruitWrapper.fruit->feedSeed (1.5f) << " total energy stored." << std::endl;
    fruitWrapper.fruit->feedSeedAndPrintSeedEnergy (1.5f);
    
    std::cout << std::endl;

    float fruitIntegrity = fruitWrapper.fruit->decay (5);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruitWrapper.fruit->decay (10);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruitWrapper.fruit->decay (7);
    std::cout << "fruit integrity: " << fruitIntegrity << std::endl;
    
    std::cout << std::endl;
    
    Fruit::Seed newSeed = fruitWrapper.fruit->disperseSeed (10.0f);
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

    PersonWrapper someoneWrapper (new Person);
    float distance = someoneWrapper.person->excercise (10, 0.00124f);
    std::cout << "someone ran " << distance << " km." << std::endl;
    std::cout << "someone feeds the neighborhood stray." << std::endl;
    someoneWrapper.person->feedCat (0.125f, *(catWrapper.cat));
    
    std::cout << std::endl;

    CatWrapper randoCatWrapper (new Cat{"tabby", "white"});
    
    TrashBinWrapper trashBinWrapper (new TrashBin(*(randoCatWrapper.cat)));

    float smellIntensity = trashBinWrapper.trashBin->fester();
    bool catAttracted = trashBinWrapper.trashBin->attractCat (smellIntensity, *(catWrapper.cat));
    
    while (! catAttracted)
    {
        smellIntensity = trashBinWrapper.trashBin->fester();
        catAttracted = trashBinWrapper.trashBin->attractCat (smellIntensity, *(catWrapper.cat));
    }
    
    std::cout << std::endl;
    
    std::cout << "good to go!" << std::endl;
}
