#pragma once
#include  <wx/wx.h>
#include "weaponEqCell.h"


class equippedItemsPanel :
	public wxPanel
{
private:
	wxBoxSizer* wrapper = nullptr;
	wxButton* mainWeapon = nullptr;
	wxButton* secondWeapon = nullptr;
	wxButton* bodyArmor = nullptr;
	wxButton* legArmor = nullptr;
public:
	equippedItemsPanel(wxWindow* parent);
	~equippedItemsPanel();
};

