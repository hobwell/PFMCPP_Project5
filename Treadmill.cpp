#include "Treadmill.h"

Treadmill::Treadmill (float weightAllowance)
{
    maximumWeightAllowanceKg = weightAllowance;
    inclineDisplay.colour = "red";
    std::cout << "A Treadmill has been constructed!" << std::endl;
}

Treadmill::~Treadmill()
{
    std::cout << "A treadmill has been destructed." << std::endl;
}

void Treadmill::display (const ValueDisplay& displayValue) const
{
    std::cout << displayValue.name << ": " << displayValue.value << " " << displayValue.unit << std::endl;
}

void Treadmill::incline (float inclinationDegrees)
{
    currentInclinationDegrees = inclinationDegrees;
    inclineDisplay.updateValue (currentInclinationDegrees);
    std::cout << "Prepare to climb!" << std::endl;
}

void Treadmill::printMembers() const
{
    std::cout << "Treadmill: maximumWeightAllowanceKg: " << this->maximumWeightAllowanceKg << std::endl;
    std::cout << "Treadmill: currentSpeedKph: " << this->currentSpeedKph << std::endl;
    std::cout << "Treadmill: currentInclinationDegrees: " << this->currentInclinationDegrees << std::endl;
    std::cout << "Treadmill: totalDistanceSimulatedKm: " << this->totalDistanceSimulatedKm << std::endl;
    std::cout << "Treadmill: sessionDistanceSimulatedKm: " << this->sessionDistanceSimulatedKm << std::endl;    
}

void Treadmill::rotateBelt (float speedKph)
{
    std::cout << "Current Session distance: " << sessionDistanceSimulatedKm << " km!" << std::endl;
    currentSpeedKph = speedKph;
    speedDisplay.updateValue (currentSpeedKph);
    std::cout << "Away we go (at " << currentSpeedKph << " km/h)!" << std::endl;
}

float Treadmill::run (int numSteps, float strideLength)
{
    for (int i = 0; i < numSteps; ++i)
    {
        if (i % 2 == 0)
            std::cout << "Huff"<< std::endl;
        else
            std::cout << "Puff" << std::endl;
        sessionDistanceSimulatedKm += strideLength;
    }
    
    return sessionDistanceSimulatedKm;
}
