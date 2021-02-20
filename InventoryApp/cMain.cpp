#include "cMain.h"


cMain::cMain() : wxFrame(nullptr, wxID_ANY, "Inventory", wxPoint(50, 50), wxSize(600, 800)) {

	equippedItems = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxSize(200,100));
	equippedItems->SetBackgroundColour(wxColor(100, 100, 200));
	sizer = new wxBoxSizer(wxVERTICAL);
	inventory = new InventoryGrid((wxWindow*) this, 15, 10);
	sizer->Add(equippedItems, 1, wxEXPAND);
	sizer->Add(inventory, 1, wxEXPAND);

	this->SetSizerAndFit(sizer);

}

cMain::~cMain() {
	delete equippedItems;
	delete inventory;
}