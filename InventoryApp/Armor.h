#pragma once
#include "IItem.h"
#include <ctime>

class Armor :
    public IItem
{
public:
    Armor(std::wstring name);
public:
    std::wstring getName();
    int getWeight();
    int getPrice();
    int getAmount();
    int getMaxAmount();
    std::string getImagePath();
};

