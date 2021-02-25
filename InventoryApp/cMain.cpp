#include "cMain.h"


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Inventory", wxDefaultPosition) {

	equippedItems = new equippedItemsPanel(this);
	equippedItems->SetBackgroundColour(wxColor(100, 100, 200));
	sizer = new wxBoxSizer(wxVERTICAL);
	inventory = new InventoryGrid((wxWindow*) this, 10, 10);
	inventory->SetBackgroundColour(wxColor(100, 100, 200));
	sizer->Add(equippedItems, 1, wxEXPAND);
	sizer->Add(inventory, 1, wxEXPAND);

	this->SetSizerAndFit(sizer);

}

cMain::~cMain() {
	delete equippedItems;
	delete inventory;
}