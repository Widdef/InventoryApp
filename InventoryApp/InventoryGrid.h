#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/wxchar.h>
#include "definedValues.h"
#include "Inventory.h"
#include "Weapon.h"
#include "ItemFrame.h"


class InventoryGrid : public wxPanel
{
public:
	InventoryGrid(wxWindow* parent, int x = 10, int y = 10);
	~InventoryGrid();

public:
	wxButton** itemArray = nullptr;
	Inventory* inv = new Inventory();
	ItemFrame* popUpWindow;

	void OnButtonClicked(wxCommandEvent& evt);
	void OnEnterPanel(wxMouseEvent& evt);
	void OnLeavePanel(wxMouseEvent& evt);

private:
	int idClickedElement;
	bool wasClicked = false;
};

