#pragma once
#include <wx/wx.h>
#include "Weapon.h"

class weaponEqCell :
    public wxButton
{
private:
    Weapon* item = nullptr;
public:
    weaponEqCell(wxWindow* parent, wxWindowID id);
    ~weaponEqCell();
};

