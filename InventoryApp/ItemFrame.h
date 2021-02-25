#pragma once
#include <wx/wx.h>
#include <wx/frame.h>
#include "IItem.h"
#include <string>

class ItemFrame :
    public wxFrame
{
private:
    const wxChar* title;
    wxPoint pos;
    wxSize size;
    wxPanel* content = nullptr;
    wxBoxSizer* sizer = nullptr;
public:
    ItemFrame(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
    ~ItemFrame();
public:
    void SetBgColor(wxColor color);
    void SetBorder(int size = 1, wxColor color = wxColor(0, 0, 0));
    void ShowData(IItem* item);
};

