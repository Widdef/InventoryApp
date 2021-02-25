#include "equippedItemsPanel.h"

equippedItemsPanel::equippedItemsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{
	wrapper = new wxBoxSizer(wxHORIZONTAL);
	wxPanel* weapons = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	wxBoxSizer* weaponsSizer = new wxBoxSizer(wxVERTICAL);
	wxButton* mainWeapon = new wxButton(this, wxID_ANY);
	weaponsSizer->Add(mainWeapon);
	weapons->SetSizerAndFit(weaponsSizer);
	wrapper->Add(weapons);
	this->SetSizerAndFit(wrapper);
}

equippedItemsPanel::~equippedItemsPanel() {

}