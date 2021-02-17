#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include <wx/wxchar.h>
#include "definedValues.h"
#include "Inventory.h"
#include "Weapon.h"
#include "ItemFrame.h"


class cMain : public wxFrame
{
public:
	cMain(int x = 10, int y = 10);
	~cMain();

public:
	int nFieldsX;
	int nFieldsY;
	wxButton** itemArray = nullptr;
	Inventory* inv = new Inventory();
	ItemFrame* popUpWindow;

	void OnButtonClicked(wxCommandEvent& evt);
	void OnEnterPanel(wxMouseEvent& evt);
	void OnLeavePanel(wxMouseEvent& evt);
	wxDECLARE_EVENT_TABLE();

private:
	int idClickedElement;
	int wasClicked = false;
};


