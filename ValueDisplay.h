#pragma once

#include <iostream>
#include "LeakedObjectDetector.h"

struct ValueDisplay
{
    ValueDisplay (float val, std::string valName, std::string valUnit);
    ~ValueDisplay();

    std::string colour = "green";    
    std::string font = "Arial";
    int fontSize = 12;    
    std::string name = "";
    std::string unit = "";
    float value = 0.0f;

    void changeColour (std::string newColor = "green");    
    void changeFont (std::string newFont = "Arial", int newFontSize = 18);
    int growFontSize (int numSteps = 1);
    void growFontSizeAndReportNewFontSize (int numSteps = 1);
    void printFontInfo() const;    
    int shrinkFontSize (int numSteps = 1);
    void shrinkFontSizeAndReportNewFontSize (int numSteps = 1);
    void updateValue (float newValue);

    JUCE_LEAK_DETECTOR (ValueDisplay)
};
