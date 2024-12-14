#pragma once

#include "LeakedObjectDetector.h"

struct Seed
{
    Seed(int germinationDays);
    ~Seed();
    
    float coatIntegrity = 1.0f;
    int daysDormant = 0;
    int daysToGerminate = 15;
    float storedEnergy = 0.0f;
    int totalLeaves = 0;
    float weightGrams = 0.05f;

    bool germinate (int days);    
    int growLeaves (bool germinated = false, int numLeaves = 2);    
    bool growRoot (bool germinated = false);
    bool growStem (bool germinated = false);
    void printMembers() const;

    JUCE_LEAK_DETECTOR (Seed)
};
