#include "cApp.h"

wxIMPLEMENT_APP(cApp);

cApp::cApp() {

}

cApp::~cApp() {

}

bool cApp::OnInit() {
	mainFrame = new cMain(10, 10);
	mainFrame->Show();

	return true;
}

