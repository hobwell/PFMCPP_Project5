#include "TrashBin.h"

TrashBin::TrashBin (const Cat& nearbyCat) : seed{15}
{
    std::cout << std::endl << "A TrashBin has popped into existence, complete with trash (and cats)!" << std::endl;
    std::cout << "The smell is attacting some cats!" << std::endl;

    attractCat (10.0f, nearbyCat);
}

TrashBin::~TrashBin()
{
    std::cout << std::endl << "The cats feast!" << std::endl;
    niceCat.eat (0.125f);
    alleyCat.eat (0.125f);
    smellyCat.eat (0.125f);
    std::cout << "A trash collector comes to reap a TrashBin." << std::endl;
    std::cout << "The trash collector takes the cats with them." << std::endl;
}

bool TrashBin::attractCat (const float smellIntensity, const Cat& cat)
{
    std::cout << std::endl;
    
    if (smellIntensity >= 100.0f)
    {
        std::cout << "The smell has become too intense for the " << smellyCat.furColour << " " << smellyCat.furPattern << " cat!" << std::endl;
        smellyCat = cat;
    } 
    else if (smellIntensity >= 10.0f)
    {
        std::cout << "The smell has become too intense for the " << alleyCat.furColour << " " << alleyCat.furPattern << " cat!" << std::endl;
        alleyCat = cat;
    }
    else if (smellIntensity >= 1.0f)
    {
        std::cout << "The smell has become too intense for the " << niceCat.furColour << " " << niceCat.furPattern << " cat!" << std::endl;
        niceCat = cat;
    }
    else
    {
        std::cout << "The smell was not interesting enough to retain or repel any cats.";
        return false;
    }

    std::cout << "A " << cat.furColour << " " << cat.furPattern << " cat takes their place." << std::endl;
    
    return true; // a cat was attracted
}

float TrashBin::fester()
{
    float smellIntensity = 0.0f;
    smellIntensity += 10.0f / avocado.decay(1);
    smellIntensity += 10.0f / watermelon.decay(1);
    
    return smellIntensity;
}
