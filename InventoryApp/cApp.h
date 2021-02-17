#pragma once

#include "wx/wx.h"
#include "cMain.h"

class cApp : public wxApp
{
public:
	cApp();
	~cApp();
private:
	cMain* mainFrame = nullptr;
public:
	virtual bool OnInit();
};

