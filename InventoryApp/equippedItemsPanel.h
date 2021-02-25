#pragma once
#include  <wx/wx.h>


class equippedItemsPanel :
	public wxPanel
{
private:
	wxBoxSizer* wrapper = nullptr;

public:
	equippedItemsPanel(wxWindow* parent);
	~equippedItemsPanel();
};

