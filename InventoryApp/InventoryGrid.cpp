#include "InventoryGrid.h"

InventoryGrid::InventoryGrid(wxWindow* parent, int nFieldsX, int nFieldsY) : wxPanel(parent, wxID_ANY) {
	itemArray = new wxButton* [nFieldsX * nFieldsY];
	wxGridSizer* grid = new wxGridSizer(nFieldsX, nFieldsY, MARGIN_ROW, MARGIN_COL);
	this->amount = nFieldsX * nFieldsY;
	for (int y = 0; y < nFieldsY; y++) {
		for (int x = 0; x < nFieldsX; x++) {
			int id = y * nFieldsX + x;
			itemArray[id] = new wxButton(this, INVENTORY_GRID_START_ID + (id));
			grid->Add(itemArray[id], 1, wxEXPAND | wxALL);

			itemArray[id]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &InventoryGrid::OnButtonClicked, this);
			itemArray[id]->Bind(wxEVT_ENTER_WINDOW, &InventoryGrid::OnEnterPanel, this);
			itemArray[id]->Bind(wxEVT_LEAVE_WINDOW, &InventoryGrid::OnLeavePanel, this);

			IItem* item;
			if ((y * nFieldsX + x) % 2)
				item = new Weapon(L"Position (weapon): " + std::to_wstring(id) + L"\n", x, y, "physical");
			else
				item = new Armor(L"Position (armor): " + std::to_wstring(id) + L"\n");

			inv->AddItem(static_cast<IItem*>(item));
			itemArray[id]->SetLabelText(inv->GetItem(id)->getName());
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}


//TODO: Fix memory leaks
InventoryGrid::~InventoryGrid() {
	for (int i = 0; i < this->amount; i++)
		delete itemArray[i];
	delete[] itemArray;
	delete inv;
}

void InventoryGrid::OnButtonClicked(wxCommandEvent& evt) {
	int id = evt.GetId() - INVENTORY_GRID_START_ID;
	if (wasClicked) {
		inv->MoveItem(idClickedElement, id);
		wasClicked = false;
		itemArray[id]->SetLabelText(inv->GetItem(id)->getName());
		itemArray[idClickedElement]->SetLabelText(inv->GetItem(idClickedElement)->getName());
	}
	else {
		wasClicked = true;
		idClickedElement = id;
		//OutputDebugStringW(inv->GetItem(id)->getName().c_str());
	}
	evt.Skip();
}

void InventoryGrid::OnEnterPanel(wxMouseEvent& evt) {
	int id = evt.GetId() - INVENTORY_GRID_START_ID;
	const wxPoint pt = wxGetMousePosition();
	//OutputDebugStringW("Position: " + std::to_wstring(pt.x) + L", " + std::to_wstring(pt.y) + L"\n");
	//popUpWindow = new ItemFrame(this, inv->GetItem(id)->getName(), wxPoint(pt.x + 40, pt.y - 40), wxSize(100, 200));
	popUpWindow = new ItemFrame(this, inv->GetItem(id)->getName(), wxPoint(pt.x + 40, pt.y - 40), wxSize(100, 200));
	popUpWindow->ShowData(inv->GetItem(id));
	popUpWindow->SetBorder();
	popUpWindow->Show();
}

void InventoryGrid::OnLeavePanel(wxMouseEvent& evt) {
	delete popUpWindow;
}
