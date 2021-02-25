#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/wxchar.h>
#include "InventoryGrid.h"
#include "equippedItemsPanel.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
private:
	equippedItemsPanel* equippedItems = nullptr;
	wxBoxSizer* sizer = nullptr;
	InventoryGrid* inventory = nullptr;
};


