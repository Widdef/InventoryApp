#include "equippedItemsPanel.h"

equippedItemsPanel::equippedItemsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize)
{ 
	wxPanel* weaponsPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	mainWeapon = new weaponEqCell(weaponsPanel, wxID_ANY);
	mainWeapon->SetLabelText("_empty_(main Weapon)");
	secondWeapon = new weaponEqCell(weaponsPanel, wxID_ANY);
	secondWeapon->SetLabelText("_empty_(second Weapon)");
	wxBoxSizer* weaponsSizer = new wxBoxSizer(wxVERTICAL);

	weaponsSizer->Add(mainWeapon, wxALIGN_CENTER);
	weaponsSizer->Add(secondWeapon, wxALIGN_CENTER);
	weaponsPanel->SetSizerAndFit(weaponsSizer);



	wxPanel* armorPanel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize);
	bodyArmor = new wxButton(armorPanel, wxID_ANY);
	bodyArmor->SetLabelText("_empty_(body Armor)");
	legArmor = new wxButton(armorPanel, wxID_ANY);
	legArmor->SetLabelText("_empty_(leg Armor)");

	wxBoxSizer* armorSizer = new wxBoxSizer(wxVERTICAL);
	armorSizer->Add(bodyArmor, wxALIGN_CENTER);
	armorSizer->Add(legArmor, wxALIGN_CENTER);
	armorPanel->SetSizerAndFit(armorSizer);



	wrapper = new wxBoxSizer(wxHORIZONTAL);
	wrapper->Add(weaponsPanel, wxALIGN_CENTER);
	wrapper->Add(armorPanel, wxALIGN_CENTER);
	this->SetSizerAndFit(wrapper);
}

equippedItemsPanel::~equippedItemsPanel() {

}