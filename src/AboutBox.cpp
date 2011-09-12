#include "AboutBox.h"
#include "version.h"
BEGIN_EVENT_TABLE(AboutBox, wxDialog) EVT_BUTTON (ID_ABOUT_WXBUTTONOK, AboutBox::OnButtonOK)
END_EVENT_TABLE()

AboutBox::AboutBox(wxWindowID id) :
		wxDialog(NULL, id, wxT("About"), wxDefaultPosition, wxSize(480, 450),
				wxDEFAULT_DIALOG_STYLE) {

	//Writes the application name
	wxStaticText *myAppName = new wxStaticText(this, -1,
			wxT("Manga Reading Assistant"), wxPoint(10, 10),
			wxSize(200, 40), 0);
	myAppName->SetFont(
			wxFont(28, wxSWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false,
					wxT("Arial")));
	myAppName->SetForegroundColour(wxColour(220, 0, 0));

	//Writes the application version
	wxString versionString;
	versionString << AutoVersion::FULLVERSION_STRING;
	wxStaticText *myAppVersion = new wxStaticText(this, -1, versionString,
			wxPoint(10, myAppName->GetPosition().y + 35), wxSize(200, 40), 0);
	myAppVersion->SetFont(
			wxFont(8, wxSWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false,
					wxT("Arial")));

	myAppVersion->SetForegroundColour(wxColour(120, 120, 120));

	//Writes the Copyright String
	wxString copyrightString;

	copyrightString << _T("© ")<< _T("2010-2011 ") << _T("Kelsos");

	wxStaticText *myAppCopyright = new wxStaticText(this, -1, copyrightString,
			wxPoint(10, this->GetSize().y - 100), wxSize(200, 100), 0,
			wxT("myAppCopyright"));

	myAppCopyright->SetFont(
			wxFont(8, wxSWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false,
					wxT("Arial")));
	myAppCopyright->Wrap((int) (this->GetSize().x - 2 * 15));
	myAppCopyright->SetForegroundColour(wxColour(0, 0, 0));

	// Retrieve OS and version info:
	wxString wxBuild;
#if defined(__WXMSW__)
	wxBuild << _T("Windows");
#elif defined(__WXMAC__)
	wxBuild << _T("Mac");
#elif defined(__UNIX__)
	wxBuild << _T("Linux");
#endif

#if wxUSE_UNICODE
	wxBuild << _T("; Unicode build");
#else
	wxBuild << _T("; ANSI build");
#endif // wxUSE_UNICODE
	wxBuild << _T("; ") << wxGetOsDescription() << _T("; ")<< wxVERSION_STRING;

	//Writes build info
	wxStaticText *myAppInfo = new wxStaticText(this, -1, wxBuild,
			wxPoint(10, this->GetSize().y - 70), wxSize(20, 100), 0);
	myAppInfo->SetFont(
			wxFont(8, wxSWISS, wxFONTSTYLE_NORMAL, wxNORMAL, false,
					wxT("Arial")));
	myAppInfo->Wrap((int) (this->GetSize().x - 2 * 35));
	myAppInfo->SetForegroundColour(wxColour(0, 0, 0));

	//Static line
	wxStaticLine *myStaticLine = new wxStaticLine(this, -1,
			wxPoint(0, this->GetSize().y - 80), wxSize(this->GetSize().x, 2),
			wxLI_HORIZONTAL, wxT("staticLine"));

	//Button 'OK'
	wxButton *myButtonOK = new wxButton(this, ID_ABOUT_WXBUTTONOK, _("OK"),
			wxPoint(this->GetSize().x - 70 - 15, this->GetSize().y - 50 - 15),
			wxSize(70, 23), 0, wxDefaultValidator, wxT("myBOK"));
	myButtonOK->SetFont(
			wxFont(8, wxSWISS, wxNORMAL, wxNORMAL, false, wxT("Tahoma")));

}
//---------------------------------------------------------------------------------------------------------
void AboutBox::OnClose(wxCommandEvent& WXUNUSED(event)) {
	EndModal(wxID_OK);
}

//---------------------------------------------------------------------------------------------------------
void AboutBox::OnButtonOK(wxCommandEvent& WXUNUSED(event)) {
	EndModal(wxID_OK);
}
