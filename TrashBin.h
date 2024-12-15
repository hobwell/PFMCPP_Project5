#pragma once

#include "Cat.h"
#include "Fruit.h"
#include "LeakedObjectDetector.h"
#include "Treadmill.h"

struct TrashBin
{
    TrashBin (const Cat& nearbyCat);
    ~TrashBin();

    Cat alleyCat{"solid", "black"};    
    Fruit avocado;
    Cat niceCat{"calico", "white-orange-black"};
    Seed seed;    
    Cat smellyCat{"bi-color", "white-black"};
    Treadmill treadmill{100.0f};
    Fruit watermelon;
    
    bool attractCat (const float smellIntensity, const Cat& cat);
    float fester();

    JUCE_LEAK_DETECTOR (TrashBin)
};
