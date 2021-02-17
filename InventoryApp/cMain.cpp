#include "cMain.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
	EVT_BUTTON(MENU_PLAY_BUTTON, OnButtonClicked)
wxEND_EVENT_TABLE()

cMain::cMain(int x, int y) : wxFrame(nullptr, wxID_ANY, "Inventory", wxPoint(50, 50), wxSize(600, 800)) {
	this->nFieldsX = x;
	this->nFieldsY = y;
	itemArray = new wxButton * [nFieldsX * nFieldsY];
	wxGridSizer* grid = new wxGridSizer(nFieldsX, nFieldsY, 10, 10);

	for (int x = 0; x < nFieldsX; x++) {
		for (int y = 0; y < nFieldsY; y++) {
			int id = x * 10 + y;
			itemArray[id] = new wxButton(this, 10000 + (id));
			grid->Add(itemArray[id], 1, wxEXPAND | wxALL);

			itemArray[id]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &cMain::OnButtonClicked, this);
			itemArray[id]->Bind(wxEVT_ENTER_WINDOW, &cMain::OnEnterPanel, this);
			itemArray[id]->Bind(wxEVT_LEAVE_WINDOW, &cMain::OnLeavePanel, this);

			Weapon* weapon = new Weapon(L"Position: " + std::to_wstring(id) + L"\n", x, y, "physical");
			inv->AddItem(static_cast<IItem*>(weapon));
			itemArray[id]->SetLabelText(inv->GetItem(id)->getName());
		}
	}

	this->SetSizer(grid);
	grid->Layout();
}

cMain::~cMain() {
	delete[] itemArray;
	delete  inv;
}

void cMain::OnButtonClicked(wxCommandEvent& evt) {
	int id = evt.GetId() - 10000;
	if (wasClicked) {
		inv->MoveItem(idClickedElement, id);
		wasClicked = false;
		itemArray[id]->SetLabelText(inv->GetItem(id)->getName());
		itemArray[idClickedElement]->SetLabelText(inv->GetItem(idClickedElement)->getName());
	}
	else {
		wasClicked = true;
		idClickedElement = (id);
		//OutputDebugStringW(inv->GetItem(id)->getName().c_str());
	}
	evt.Skip();
}

void cMain::OnEnterPanel(wxMouseEvent& evt) {
	int id = evt.GetId() - 10000;
	const wxPoint pt = wxGetMousePosition();
	//OutputDebugStringW("Position: " + std::to_wstring(pt.x) + L", " + std::to_wstring(pt.y) + L"\n");
	popUpWindow = new ItemFrame(this, "Cos", wxPoint(pt.x + 40, pt.y - 40), wxSize(100, 200));
	popUpWindow->ShowData(inv->GetItem(id));
	popUpWindow->Show();
}

void cMain::OnLeavePanel(wxMouseEvent& evt) {
	delete popUpWindow;
}
