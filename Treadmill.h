#pragma once

#include "LeakedObjectDetector.h"
#include "ValueDisplay.h"

struct Treadmill
{
    Treadmill (float weightAllowance = 150.0f);
    ~Treadmill();

    float currentSpeedKph = 0.0f;
    float currentInclinationDegrees = 0.0f;
    float totalDistanceSimulatedKm = 0.0f;
    float sessionDistanceSimulatedKm = 0.0f;
    float maximumWeightAllowanceKg;

    ValueDisplay inclineDisplay{ 0.0f, "incline", "degrees" };    
    ValueDisplay speedDisplay{ 0.0f, "speed", "km/h" };    

    void display (const ValueDisplay& displayValue) const;
    void incline (const float inclinationDegrees);
    void printMembers() const;
    void rotateBelt (const float speeedKph);
    float run (const int numSteps, const float strideLength = 0.00065f);

    JUCE_LEAK_DETECTOR (Treadmill)
};
