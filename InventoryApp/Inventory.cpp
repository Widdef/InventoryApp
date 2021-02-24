#include "Inventory.h"


Inventory::Inventory() {}
Inventory::~Inventory() {
	for (auto i : ItemList)
	{
		delete i;
	}
}

IItem& Inventory::operator[](int index) {
	return *this->ItemList[index];
}

void Inventory::AddItem(IItem* item) {
	this->ItemList.push_back(item);
}

void Inventory::AddItemsFromDB(std::string player) {

}

void Inventory::MoveItem(int from, int to) {
	void* var = this->ItemList[to];
	this->ItemList[to] = this->ItemList[from];
	this->ItemList[from] = static_cast<IItem*>(var);
}

IItem* Inventory::GetItem(int id) {
	return ItemList[id];
}