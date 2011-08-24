#include "main.h"
#include "applicationFrame.h"

IMPLEMENT_APP(MRApp)

bool MRApp::OnInit() {
	bool wxsOK = true;
	wxInitAllImageHandlers();

	if(wxsOK)
	{
	ApplicationFrame* appFrame = new ApplicationFrame(0);
	appFrame->Show(true);
	SetTopWindow(appFrame);
	}

	return wxsOK;
}
