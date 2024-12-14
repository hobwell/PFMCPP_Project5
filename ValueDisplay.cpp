#include "ValueDisplay.h"

ValueDisplay::ValueDisplay (float val, std::string valName, std::string valUnit)
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

void ValueDisplay::changeColour (std::string newColor)
{
    colour = newColor;
}

void ValueDisplay::changeFont (std::string newFont, int newFontSize)
{
    std::cout << "Changing font from " << font << " " << fontSize << "pt to " << newFont << " " << newFontSize << "pt" << std::endl;
    font = newFont;
    fontSize = newFontSize;
}

int ValueDisplay::growFontSize (int numSteps)
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

int ValueDisplay::shrinkFontSize (int numSteps)
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

void ValueDisplay::growFontSizeAndReportNewFontSize (int numSteps)
{
    std::cout << "New font size: " << this->growFontSize (numSteps) << std::endl;
}

void ValueDisplay::printFontInfo() const
{
    std::cout << this->name << " (" << this->font << ", " << this->fontSize << "pt, " << this->colour << "): " << this->value << " " << this->unit << std::endl;
}

void ValueDisplay::shrinkFontSizeAndReportNewFontSize (int numSteps)
{
    std::cout << "New font size: " << this->shrinkFontSize (numSteps) << std::endl;
}

void ValueDisplay::updateValue (float newValue)
{
    std::cout << "Changing " << name << " from " << value << " to " << newValue << " " << unit << std::endl;
    value = newValue;    
}
