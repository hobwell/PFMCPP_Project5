#pragma once

#include "Seed.h"
#include "LeakedObjectDetector.h"

struct Fruit
{
    Fruit();
    ~Fruit();
    
    float endospermLevel = 0.05f;
    float epicarpThicknessCm = 0.05f;
    float hydrationLevel = 0.05f;
    float mesocarpThicknessCm = 0.05f;
    Seed seed{15};

    float decay (const int days);    
    Seed disperseSeed (const float distanceKm);
    float feedSeed (const float energy);
    void feedSeedAndPrintSeedEnergy (const float energy);
    void printMembers() const;
    void protectSeed (const float increment);

    JUCE_LEAK_DETECTOR (Fruit)
};
