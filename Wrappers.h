#pragma once

#include "Cat.h"
#include "Fruit.h"
#include "Person.h"
#include "TrashBin.h"
#include "Treadmill.h"

struct CatWrapper
{
    CatWrapper (Cat* c);
    ~CatWrapper();

    Cat* cat = nullptr;
};

struct FruitWrapper
{
    FruitWrapper (Fruit* f);
    ~FruitWrapper();

    Fruit* fruit = nullptr;
};

struct PersonWrapper
{
    PersonWrapper (Person* p);
    ~PersonWrapper();

    Person* person = nullptr;
};

struct TrashBinWrapper
{
    TrashBinWrapper (TrashBin* tb);

    ~TrashBinWrapper();

    TrashBin* trashBin = nullptr;
};

struct TreadmillWrapper
{
    TreadmillWrapper (Treadmill* t);
    ~TreadmillWrapper();

    Treadmill* treadmill = nullptr;
};
