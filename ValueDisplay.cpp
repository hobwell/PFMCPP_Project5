#include "ValueDisplay.h"

ValueDisplay::ValueDisplay (const float val, const std::string valName, const std::string valUnit)
{
    value = val;
    name = valName;
    unit = valUnit;
    std::cout << "A ValueDisplay has been constructed!" << std::endl;
}

ValueDisplay::~ValueDisplay()
{
    std::cout << "A ValueDisplay has been destructed!" << std::endl;
}

void ValueDisplay::changeColour (const std::string newColor)
{
    colour = newColor;
}

void ValueDisplay::changeFont (const std::string newFont, const int newFontSize)
{
    std::cout << "Changing font from " << font << " " << fontSize << "pt to " << newFont << " " << newFontSize << "pt" << std::endl;
    font = newFont;
    fontSize = newFontSize;
}

int ValueDisplay::growFontSize (const int numSteps)
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

void ValueDisplay::growFontSizeAndReportNewFontSize (const int numSteps)
{
    std::cout << "New font size: " << this->growFontSize (numSteps) << std::endl;
}

void ValueDisplay::printFontInfo() const
{
    std::cout << this->name << " (" << this->font << ", " << this->fontSize << "pt, " << this->colour << "): " << this->value << " " << this->unit << std::endl;
}

int ValueDisplay::shrinkFontSize (const int numSteps)
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

void ValueDisplay::shrinkFontSizeAndReportNewFontSize (const int numSteps)
{
    std::cout << "New font size: " << this->shrinkFontSize (numSteps) << std::endl;
}

void ValueDisplay::updateValue (const float newValue)
{
    std::cout << "Changing " << name << " from " << value << " to " << newValue << " " << unit << std::endl;
    value = newValue;    
}
