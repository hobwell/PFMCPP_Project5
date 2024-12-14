#include "Wrappers.h"

CatWrapper::CatWrapper (Cat* c) : cat (c) {}

CatWrapper::~CatWrapper()
{
    delete cat;
}

FruitWrapper::FruitWrapper (Fruit* f) : fruit (f) {}

FruitWrapper::~FruitWrapper()
{
    delete fruit;
}

PersonWrapper::PersonWrapper (Person* p) : person (p) {}

PersonWrapper::~PersonWrapper()
{
    delete person;
}

TrashBinWrapper::TrashBinWrapper (TrashBin* tb) : trashBin (tb) {}

TrashBinWrapper::~TrashBinWrapper()
{
    delete trashBin;
}

TreadmillWrapper::TreadmillWrapper (Treadmill* t) : treadmill (t) {}

TreadmillWrapper::~TreadmillWrapper()
{
    delete treadmill;
}
