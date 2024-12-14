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
#include "Wrappers.h"
#include "Cat.h"
#include "Fruit.h"
#include "Person.h"
#include "Seed.h"
#include "TrashBin.h"
#include "Treadmill.h"
#include "ValueDisplay.h"


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
    ValueDisplay maxWeightDisplay{ 200.0f, "max weight", "kg" };
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
    
    Seed newSeed = fruitWrapper.fruit->disperseSeed (10.0f);
    std::cout << "newSeed: weightGrams: " << newSeed.weightGrams << std::endl;
    std::cout << "newSeed: coatIntegrity: " << newSeed.coatIntegrity << std::endl;
    std::cout << "newSeed: daysToGerminate: " << newSeed.daysToGerminate << std::endl;
    std::cout << "newSeed: storedEnergy: " << newSeed.storedEnergy << std::endl;
    std::cout << "newSeed: daysDormant: " << newSeed.daysDormant << std::endl;
    std::cout << "newSeed: totalLeaves: " << newSeed.totalLeaves << std::endl;
    newSeed.printMembers();
    
    std::cout << std::endl;
    
    Seed seed{20};
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
