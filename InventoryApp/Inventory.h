#pragma once
#include <vector>
#include "IItem.h"
#include "Weapon.h"


class Inventory
{
public:
	Inventory();
	~Inventory();
private:
	std::vector<IItem*> ItemList;
public:
	IItem& operator[](int id);
	void AddItem(IItem*);
	void AddItemsFromDB(std::string player);
	void MoveItem(int from, int to);
	IItem* GetItem(int);
};