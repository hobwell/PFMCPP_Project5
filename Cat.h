#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct Cat
{
    Cat (std::string pattern, std::string colour);
    ~Cat();

    int age = 3;    
    std::string eyeColour = "green";    
    std::string furColour = "orange";    
    std::string furPattern = "tabby";
    char sex = 'F';

    void eat (float amountOfFoodKg) const;    
    bool hunt (std::string creature) const;    
    void printMembers() const;    
    void purr (float volumeDb) const;
    int unrollToiletPaper (int numSwipes = 4, int squaresRemaining = 400) const;
    
    JUCE_LEAK_DETECTOR (Cat)
};
