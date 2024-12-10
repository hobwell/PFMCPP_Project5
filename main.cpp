/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 

NOTE: there are 2 sets of instructions:
       One for if you completed project 3
       One for if you skipped project 3.

 Destructors

===============================================================     
 If you completed Project 3:
 
 1) Copy 3 of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
    Choose the classes that contained nested classes.  Include the nested classes when you copy them over.

 2) move all of your implementations of all functions to OUTSIDE of the class.

 3) add destructors
        make the destructors do something like print out the name of the class.
===============================================================
If you skipped Project 3:
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
===============================================================

 4) add 2 new UDTs that use only the types you copied above as member variables.

 5) add 2 member functions that use your member variables to each of these new UDTs

 6) Add constructors and destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 7) copy over your main() from the end of Project3 
        get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 8) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
       call their member functions.
 
 9) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.

 you can resolve any [-Wdeprecated] warnings by adding -Wno-deprecated to list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.
 You can resolve any [-Wpadded] warnings by adding -Wno-padded to the list of compiler arguments in the .replit file. all of the "-Wno" in that file are compiler arguments.

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
        int shrinkFontSize (int numSteps = 1);
    };

    ValueDisplay speedDisplay{ 0.0f, "speed", "km/h" };
    ValueDisplay inclineDisplay{ 0.0f, "incline", "degrees" };

    void rotateBelt (float speeedKph);
    void incline (float inclinationDegrees);
    void display (ValueDisplay displayValue);
    float run (int numSteps, float strideLength = 0.00065f);
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
    };

    Seed seed{15};

    void protectSeed (float increment);
    Seed disperseSeed (float distanceKm);
    float feedSeed (float energy);
    float decay (int days);
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

    std::cout << std::endl;

    maxWeightDisplay.changeColour ("Orange");
    maxWeightDisplay.updateValue (250.0f);
    maxWeightDisplay.changeFont ("Helvetica", 18);

    std::cout << std::endl;
        
    auto newFontSize = maxWeightDisplay.shrinkFontSize (-1);
    std::cout << "New font size: " << maxWeightDisplay.fontSize << std::endl;
    newFontSize = maxWeightDisplay.shrinkFontSize (maxWeightDisplay.fontSize);
    std::cout << "New font size: " << maxWeightDisplay.fontSize << std::endl;
    newFontSize = maxWeightDisplay.growFontSize (12);
    std::cout << "New font size: " << maxWeightDisplay.fontSize << std::endl;
    newFontSize = maxWeightDisplay.growFontSize (-6);
    std::cout << "New font size: " << maxWeightDisplay.fontSize << std::endl;
    
    std::cout << std::endl;
    
    Treadmill treadmill{ maxWeightDisplay.value };
    std::cout << "Treadmill: maximumWeightAllowanceKg: " << treadmill.maximumWeightAllowanceKg << std::endl;
    std::cout << "Treadmill: currentSpeedKph: " << treadmill.currentSpeedKph << std::endl;
    std::cout << "Treadmill: currentInclinationDegrees: " << treadmill.currentInclinationDegrees << std::endl;
    std::cout << "Treadmill: totalDistanceSimulatedKm: " << treadmill.totalDistanceSimulatedKm << std::endl;
    std::cout << "Treadmill: sessionDistanceSimulatedKm: " << treadmill.sessionDistanceSimulatedKm << std::endl;

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
    std::cout << "Cat: furPattern: " << tuxedoCat.furPattern << std::endl;
    std::cout << "Cat: furColour: " << tuxedoCat.furColour << std::endl;
    std::cout << "Cat: eyeColour: " << tuxedoCat.eyeColour << std::endl;
    std::cout << "Cat: age: " << tuxedoCat.age << std::endl;
    std::cout << "Cat: sex: " << tuxedoCat.sex << std::endl;

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
    std::cout << "Fruit: endospermLevel: " << fruit.endospermLevel << std::endl;
    std::cout << "Fruit: hydrationLevel: " << fruit.hydrationLevel << std::endl;
    std::cout << "Fruit: epicarpThicknessCm: " << fruit.epicarpThicknessCm << std::endl;
    std::cout << "Fruit: mesocarpThicknessCm: " << fruit.mesocarpThicknessCm << std::endl;

    std::cout << std::endl;

    fruit.hydrationLevel = 2.0f;
    fruit.protectSeed (1.0f);
    std::cout << std::endl << fruit.feedSeed (1.5f) << " total energy stored." << std::endl;

    std::cout << std::endl;

    float fruitIntegrity = fruit.decay (5);
    std::cout << "Fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruit.decay (10);
    std::cout << "Fruit integrity: " << fruitIntegrity << std::endl;
    fruitIntegrity = fruit.decay (7);
    std::cout << "Fruit integrity: " << fruitIntegrity << std::endl;
    
    std::cout << std::endl;
    
    Fruit::Seed newSeed = fruit.disperseSeed (10.0f);
    std::cout << "Seed: weightGrams: " << newSeed.weightGrams << std::endl;
    std::cout << "Seed: coatIntegrity: " << newSeed.coatIntegrity << std::endl;
    std::cout << "Seed: daysToGerminate: " << newSeed.daysToGerminate << std::endl;
    std::cout << "Seed: storedEnergy: " << newSeed.storedEnergy << std::endl;
    std::cout << "Seed: daysDormant: " << newSeed.daysDormant << std::endl;
    std::cout << "Seed: totalLeaves: " << newSeed.totalLeaves << std::endl;

    std::cout << std::endl;
        
    Fruit::Seed seed{20};
    seed.storedEnergy = 1.0f;
    std::cout << "Seed: weightGrams: " << seed.weightGrams << std::endl;
    std::cout << "Seed: coatIntegrity: " << seed.coatIntegrity << std::endl;
    std::cout << "Seed: daysToGerminate: " << seed.daysToGerminate << std::endl;
    std::cout << "Seed: storedEnergy: " << seed.storedEnergy << std::endl;
    std::cout << "Seed: daysDormant: " << seed.daysDormant << std::endl;
    std::cout << "Seed: totalLeaves: " << seed.totalLeaves << std::endl;

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
