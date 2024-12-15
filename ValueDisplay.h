#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct ValueDisplay
{
    ValueDisplay (const float val, const std::string valName, const std::string valUnit);
    ~ValueDisplay();

    std::string colour = "green";    
    std::string font = "Arial";
    int fontSize = 12;    
    std::string name = "";
    std::string unit = "";
    float value = 0.0f;

    void changeColour (const std::string newColor = "green");    
    void changeFont (const std::string newFont = "Arial", const int newFontSize = 18);
    int growFontSize (const int numSteps = 1);
    void growFontSizeAndReportNewFontSize (const int numSteps = 1);
    void printFontInfo() const;    
    int shrinkFontSize (const int numSteps = 1);
    void shrinkFontSizeAndReportNewFontSize (const int numSteps = 1);
    void updateValue (const float newValue);

    JUCE_LEAK_DETECTOR (ValueDisplay)
};
