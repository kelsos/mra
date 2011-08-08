#ifndef APPLICATIONFRAME_H_INCLUDED
#define APPLICATIONFRAME_H_INCLUDED
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include "MyGrid.h"
#include "DbWrapper.h"
#include "AboutBox.h"
#include "XmlWrapper.h"

class ApplicationFrame : public wxFrame
{
public:
  ApplicationFrame(const wxString& title);

  void OnQuit(wxCommandEvent& event);
  void OnAbout(wxCommandEvent& event);
  void OnClose(wxCommandEvent& event);
  void OnTest(wxCommandEvent& event);
private:
  wxMenuBar *menubar;

  wxMenu *file;
  wxMenu *options;
  wxMenu *tools;
  wxMenu *about;

  wxToolBar *toolbar;
  wxPanel *mainPanel;

  wxBoxSizer* topSizer;
  wxBoxSizer* upperSizer;
  wxBoxSizer* upperLeftSizer;

  wxPanel *imagePanel;

  wxStaticBox* noteStaticBox;
  wxNotebook* mangaNoteBook;

  MyGrid *mangaListGrid;

  wxBoxSizer* lowerSizer;
  wxStaticBox* rssTickerStaticBox;
  wxStaticBox* descriptionStaticBox;
  AboutBox* aboutBox;

  DbWrapper* sqlData;
  XmlWrapper* xml;
};

#endif // APPLICATIONFRAME_H_INCLUDED
