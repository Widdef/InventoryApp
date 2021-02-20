#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/wxchar.h>
#include "InventoryGrid.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();
private:
	wxPanel* equippedItems = nullptr;
	wxBoxSizer* sizer = nullptr;
	InventoryGrid* inventory = nullptr;
};


