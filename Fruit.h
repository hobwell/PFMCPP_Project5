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

    float decay (int days);    
    Seed disperseSeed (float distanceKm);
    float feedSeed (float energy);
    void feedSeedAndPrintSeedEnergy (float energy);
    void printMembers() const;
    void protectSeed (float increment);

    JUCE_LEAK_DETECTOR (Fruit)
};
