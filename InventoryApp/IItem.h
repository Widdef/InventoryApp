#pragma once
#include <string>

class IItem
{
public:
	~IItem() {};
protected:
	std::wstring name;
	std::string imagePath;
	int weight;
	int price;
	int amount;
	int maxAmount;
public:
	virtual std::wstring getName() = 0;
	virtual int getWeight() = 0;
	virtual int getPrice() = 0;
	virtual int getAmount() = 0;
	virtual int getMaxAmount() = 0;
	virtual std::string getImagePath() = 0;
};

