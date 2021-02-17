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
    const wxPoint pos;
    const wxSize size;
    wxTextCtrl* name = nullptr;
    wxTextCtrl* price = nullptr;
public:
    ItemFrame(wxWindow* parent, const wxString& title, const wxPoint& pos, const wxSize& size);
    ~ItemFrame();
public:
    void ShowData(IItem* item);
};

