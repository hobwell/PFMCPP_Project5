#include "Person.h"

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

void Person::feedCat (float amountOfFoodKg, const Cat& cat) const
{
    cat.eat (amountOfFoodKg);
}
