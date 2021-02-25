#include "ItemFrame.h"

ItemFrame::ItemFrame(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
	: wxFrame(parent, wxID_ANY, title, pos, size, wxFRAME_TOOL_WINDOW)
{
	this->size = size;
	this->pos = pos;
	content = new wxPanel(this, wxID_ANY, wxDefaultPosition, size);
}

ItemFrame::~ItemFrame() {
	delete title;
}

void ItemFrame::SetBgColor(wxColor color) {
	this->content->SetBackgroundColour(color);
}

void ItemFrame::SetBorder(int size, wxColor color) {
	this->SetBackgroundColour(color);
	this->SetBgColor(wxColour(100,100,200));
	this->content->SetSize(wxSize(this->size.x - size, this->size.y - size));
}

void ItemFrame::ShowData(IItem* item) {
	sizer = new wxBoxSizer(wxVERTICAL);
	wxStaticText* name = new wxStaticText(this, wxID_ANY, item->getName(), wxPoint(10, 10), wxSize(80, 20));
	name->SetForegroundColour(wxColour(255, 255, 255));
	sizer->Add(name, wxALL, 5);
	wxStaticText* price = new wxStaticText(this, wxID_ANY, (L"Cena: " + std::to_wstring(item->getPrice())), wxPoint(10, 10), wxSize(80, 20));
	price->SetForegroundColour(wxColour(255, 255, 255));
	sizer->Add(price, wxALL, 5);
	this->content->SetSizerAndFit(sizer);
}