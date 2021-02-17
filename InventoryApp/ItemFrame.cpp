#include "ItemFrame.h"

ItemFrame::ItemFrame(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size)
: wxFrame(parent, wxID_ANY, title, pos, size) 
{
}

ItemFrame::~ItemFrame() {

}

void ItemFrame::ShowData(IItem* item) {
	name = new wxTextCtrl(this, wxID_ANY, item->getName(), wxPoint(10,10), wxSize(80,20));
	/*price = new wxTextCtrl(this, wxID_ANY, to_string(item->getPrice()), wxPoint(40,10), wxSize(80,20));
	dmg = new wxTextCtrl(this, wxID_ANY, this->dmgMax, wxPoint(70,10), wxSize(80,20));*/
}