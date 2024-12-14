#pragma once

#include "LeakedObjectDetector.h"

struct Seed
{
    Seed (int germinationDays);
    ~Seed();
    
    float coatIntegrity = 1.0f;
    int daysDormant = 0;
    int daysToGerminate = 15;
    float storedEnergy = 0.0f;
    int totalLeaves = 0;
    float weightGrams = 0.05f;

    bool germinate (const int days);    
    int growLeaves (const bool germinated = false, const int numLeaves = 2);    
    bool growRoot (const bool germinated = false);
    bool growStem (const bool germinated = false);
    void printMembers() const;

    JUCE_LEAK_DETECTOR (Seed)
};
