#include "applicationFrame.h"

ApplicationFrame::ApplicationFrame(wxWindow* parent, wxWindowID id) {
	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize,
			wxDEFAULT_FRAME_STYLE, _T("id"));
	SetClientSize(wxSize(920, 470));
	//The application size cannot grow lower than the specified size
	SetMinSize(wxSize(920, 740));

	menubar = new wxMenuBar;

	file = new wxMenu;
	options = new wxMenu;
	tools = new wxMenu;
	about = new wxMenu;

	file->Append(wxID_ANY, wxT("&Backup Reading List"));
	file->Append(wxID_ANY, wxT("&Restore Reading List"));
	file->AppendSeparator();
	file->Append(wxID_ANY, wxT("&Clear Reading List"));
	file->AppendSeparator();
	file->Append(wxID_EXIT, wxT("&Quit"));

	options->Append(wxID_ANY, wxT("&Display Finished"));
	options->Append(wxID_ANY, wxT("&Subcription Manager"));
	options->Append(wxID_ANY, wxT("S&ettings"));

	tools->Append(wxID_ANY, wxT("&Statistics"));
	tools->Append(wxID_ANY, wxT("&Reading List Mananger"));

	about->Append(wxID_ANY, wxT("&Help"));
	about->Append(wxID_FILE, wxT("&Change Log"));
	about->AppendSeparator();
	about->Append(wxID_ABOUT, wxT("&About"));

	menubar->Append(file, wxT("&File"));
	menubar->Append(options, wxT("&Options"));
	menubar->Append(tools, wxT("&Tools"));
	menubar->Append(about, wxT("&About"));

	SetMenuBar(menubar);

	wxBitmap webBrowser(wxT("icons\\globe.png"), wxBITMAP_TYPE_PNG);
	wxBitmap dataReload(wxT("icons\\reload.png"), wxBITMAP_TYPE_PNG);
	wxBitmap justReadIt(wxT("icons\\calendar.png"), wxBITMAP_TYPE_PNG);

	toolbar = new wxToolBar(this, wxID_ANY, wxDefaultPosition, wxDefaultSize,
			wxTB_HORIZONTAL | wxNO_BORDER, _T("ID_TOOLBAR1"));

	wxToolBarToolBase* ToolBarItem1 = toolbar->AddTool(wxID_ANY,
			wxT("Web Browser"), wxBitmap(webBrowser));
	wxToolBarToolBase* ToolBarItem2 = toolbar->AddTool(wxID_ANY,
			wxT("I Just Read It"), wxBitmap(justReadIt));
	wxToolBarToolBase* ToolBarItem3 = toolbar->AddTool(wxID_ANY,
			wxT("Reload the List"), wxBitmap(dataReload));
	toolbar->Realize();
	SetToolBar(toolbar);

//Panel Layout
	mainPanel = new wxPanel(this, wxID_ANY, wxPoint(80, 88), wxSize(400, 400),
			wxTAB_TRAVERSAL, _T("PANEL"));

	topSizer = new wxBoxSizer(wxVERTICAL);
	mainPanel->SetSizer(topSizer);

	upperSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(upperSizer, 2, wxGROW | wxALL | wxFIXED_MINSIZE, 2);

	upperLeftSizer = new wxBoxSizer(wxVERTICAL);
	upperSizer->Add(upperLeftSizer, 1, wxGROW | wxALL, 5);

	imagePanel = new wxPanel(mainPanel, wxID_ANY, wxDefaultPosition,
			wxSize(230, 160), wxTAB_TRAVERSAL, wxT("imagePanel"));
	upperLeftSizer->Add(imagePanel, 2, wxGROW | wxALL, 5);

	noteStaticBox = new wxStaticBox(mainPanel, wxID_STATIC, wxT("Note"),
			wxDefaultPosition, wxDefaultSize, 0);
	upperLeftSizer->Add(noteStaticBox, 2, wxGROW | wxALL, 4);

	mangaNoteBook = new wxNotebook(mainPanel, -1, wxPoint(-1, -1),
			wxSize(-1, -1), wxNB_TOP);

	mangaListGrid = new MyGrid(mangaNoteBook);
	mangaNoteBook->AddPage(mangaListGrid, wxT("MangaList"));

	upperSizer->Add(mangaNoteBook, 4, wxGROW | wxALL | wxFIXED_MINSIZE, 5);

	lowerSizer = new wxBoxSizer(wxHORIZONTAL);
	topSizer->Add(lowerSizer, 1, wxGROW | wxALL | wxFIXED_MINSIZE, 5);

	rssTickerStaticBox = new wxStaticBox(mainPanel, wxID_STATIC,
			wxT("RSS Ticker"), wxDefaultPosition, wxDefaultSize, 0);
	lowerSizer->Add(rssTickerStaticBox, 2, wxGROW | wxALL, 5);

	descriptionStaticBox = new wxStaticBox(mainPanel, wxID_STATIC,
			wxT("Description"), wxDefaultPosition, wxDefaultSize, 0);
	lowerSizer->Add(descriptionStaticBox, 4, wxGROW | wxALL, 5);

	Connect(wxID_EXIT, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(ApplicationFrame::OnQuit));
	Connect(wxID_ABOUT, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(ApplicationFrame::OnAbout));
	Connect(wxID_FILE, wxEVT_COMMAND_MENU_SELECTED,
			wxCommandEventHandler(ApplicationFrame::OnTest));
	sqlData = new DbWrapper();
	xml = new XmlWrapper(sqlData);

	Centre();

	//logging and debugging
	wxLogWindow *w = new wxLogWindow(this, wxT("Logger"));
	w->Show();
}
void ApplicationFrame::OnQuit(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void ApplicationFrame::OnAbout(wxCommandEvent& event) {
	aboutBox = new AboutBox(-1);
	if (aboutBox->ShowModal() == wxID_OK) {
		aboutBox->Destroy();
	}
}

void ApplicationFrame::OnClose(wxCommandEvent& WXUNUSED(event)) {
	Close(true);
}

void ApplicationFrame::OnTest(wxCommandEvent& WXUNUSED(event)) {
	xml->loadApplicationData();
	sqlData->getMangaData();
//    if(xml->openXmlFile(wxT("test.xml")))
//    {
//        wxMessageBox( _("Load Is Ok"),
//                      _("Load Is Ok"),
//                      wxOK | wxICON_INFORMATION, this );
//    }
//    else
//    {
//        wxMessageBox( _("Load Failed"),
//                      _("Load not OK"),
//                      wxOK | wxICON_INFORMATION, this );
//    }
}
