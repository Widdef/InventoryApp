#include "Armor.h"


Armor::Armor(std::wstring name) {
	srand(time(NULL));
	this->name = name;
	this->imagePath = "D:\\Programy\\PO_project\\PO_project\\Debug\\ItemIcon\\test.bmp";
}
std::wstring Armor::getName() {
	return this->name;
}
int Armor::getWeight(){
	return this->weight;
}
int Armor::getPrice() {
	return this->price;
}
int Armor::getAmount() {
	return this->amount;
}
int Armor::getMaxAmount() {
	return this->maxAmount;
}
std::string Armor::getImagePath() {
	return this->imagePath;
}
