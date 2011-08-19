#include "main.h"
#include "applicationFrame.h"

IMPLEMENT_APP(MRApp)

bool MRApp::OnInit() {
	wxInitAllImageHandlers();

	ApplicationFrame *appFrame = new ApplicationFrame(
			wxT("Manga Reading Assistant"));
	appFrame->Show(true);

	return true;
}
