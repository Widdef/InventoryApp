#pragma once
#include "IItem.h"
#include <ctime>


class Weapon :
    public IItem
{
public:
    Weapon(std::wstring name, int dmgMin, int dmgMax, std::string dmgType, std::string imagePath = ".\\ItemIcon\\sword.png");
    Weapon(std::wstring name);
    ~Weapon();
private: 
    int dmgMax;
    int dmgMin;
    std::string dmgType;
public:
    std::wstring getName();
    int getWeight();
    int getPrice();
    int getAmount();
    int getMaxAmount();
    std::string getImagePath();
};

