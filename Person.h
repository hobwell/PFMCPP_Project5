#pragma once

#include "Cat.h"
#include "LeakedObjectDetector.h"
#include "Treadmill.h"
#include "ValueDisplay.h"
    
struct Person
{
    Person();
    ~Person();

    Cat dali{"tabby", "orange"};
    Cat geisha{"tabby", "grey"};
    ValueDisplay temperatureDisplay{23.0f, "temperature", "C"};
    Treadmill treadmill{300.0f};

    float excercise (const int timeInMinutes, const float strideLength = 0.65f);
    void feedCat (const float amountOfFoodKg, const Cat& cat) const;

   JUCE_LEAK_DETECTOR (Person)
};
