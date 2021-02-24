#include "Weapon.h"


Weapon::Weapon(std::wstring name, int dmgMin, int dmgMax, std::string dmgType, std::string imagePath) {
	this->name = name;
	this->dmgMin = dmgMin;
	this->dmgMax = dmgMax;
	this->dmgType = dmgType;
	this->imagePath = imagePath;
}

Weapon::Weapon(std::wstring name) {
	srand(time(NULL));
	this->name = name;
	this->dmgMin = rand() % 100 + 1;
	this->dmgMax = this->dmgMin + rand() % 10 + 1;
	this->dmgType = "physical";
	this->imagePath = "D:\\Programy\\PO_project\\PO_project\\Debug\\ItemIcon\\test.bmp";
}

Weapon::~Weapon() {}

std::wstring Weapon::getName()  {
	return this->name;
}

int Weapon::getWeight() {
	return this->weight;
}

int Weapon::getPrice() {
	return this->price;
}

int Weapon::getAmount() {
	return this->amount;
}

int Weapon::getMaxAmount() {
	return this->maxAmount;
}

std::string Weapon::getImagePath()
{
	return this->imagePath;
}

