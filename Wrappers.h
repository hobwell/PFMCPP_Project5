#pragma once

struct Cat;

struct CatWrapper
{
    CatWrapper (Cat* c);
    ~CatWrapper();

    Cat* cat = nullptr;
};

struct Fruit;

struct FruitWrapper
{
    FruitWrapper (Fruit* f);
    ~FruitWrapper();

    Fruit* fruit = nullptr;
};

struct Person;

struct PersonWrapper
{
    PersonWrapper (Person* p);
    ~PersonWrapper();

    Person* person = nullptr;
};

struct TrashBin;

struct TrashBinWrapper
{
    TrashBinWrapper (TrashBin* tb);

    ~TrashBinWrapper();

    TrashBin* trashBin = nullptr;
};

struct Treadmill;

struct TreadmillWrapper
{
    TreadmillWrapper (Treadmill* t);
    ~TreadmillWrapper();

    Treadmill* treadmill = nullptr;
};
