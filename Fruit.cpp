#include "Fruit.h"

Fruit::Fruit()
{
    std::cout << "A Fruit has been constructed!" << std::endl;
}

Fruit::~Fruit()
{
    std::cout << "A Fruit has been destructed." << std::endl;
}

float Fruit::decay (const int days)
{
    float integrity = (endospermLevel + hydrationLevel + epicarpThicknessCm + mesocarpThicknessCm) / 4.0f;
    
    for (int i = 0; i < days; ++i)
    {
        endospermLevel *= 0.95f;
        hydrationLevel *= 0.95f;
        epicarpThicknessCm *= 0.95f;
        mesocarpThicknessCm *= 0.95f;
        feedSeed(0.005f);

        if (integrity < 0.5f)
        {
            std::cout << "Fruit has decayed." << std::endl;
            return integrity;
        }
    }
    
    return integrity;
}

Seed Fruit::disperseSeed (const float distanceKm)
{
    seed.daysDormant = 0;
    seed.coatIntegrity -= distanceKm / 100.0f;

    return seed;
}

float Fruit::feedSeed (const float energy)
{
    seed.storedEnergy += energy;

    return seed.storedEnergy;
}

void Fruit::feedSeedAndPrintSeedEnergy (const float energy)
{
    std::cout << std::endl << this->feedSeed (energy) << " total energy stored." << std::endl;
}

void Fruit::printMembers() const
{
    std::cout << "Fruit: endospermLevel: " << this->endospermLevel << std::endl;
    std::cout << "Fruit: hydrationLevel: " << this->hydrationLevel << std::endl;
    std::cout << "Fruit: epicarpThicknessCm: " << this->epicarpThicknessCm << std::endl;
    std::cout << "Fruit: mesocarpThicknessCm: " << this->mesocarpThicknessCm << std::endl;
}

void Fruit::protectSeed (const float increment)
{
    std::cout << "Hydration level: " << hydrationLevel << std::endl;
    epicarpThicknessCm += increment;
    mesocarpThicknessCm += increment / 2.0f;
    seed.weightGrams += increment / 10.0f;
}
