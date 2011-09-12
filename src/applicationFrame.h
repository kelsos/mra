#ifndef APPLICATIONFRAME_H_INCLUDED
#define APPLICATIONFRAME_H_INCLUDED
#include <wx/wx.h>
#include <wx/notebook.h>
#include <wx/grid.h>
#include <wx/toolbar.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include "MyGrid.h"
#include "DbWrapper.h"
#include "AboutBox.h"
#include "XmlWrapper.h"

/**The Application main Frame
 *
 */
class ApplicationFrame: public wxFrame {
public:
	/** Default constructor of the Application Main Frame.
	 *
	 * @param title
	 */
	ApplicationFrame(wxWindow* parent,wxWindowID id=-1);
	/**Represents the call of the Application Quit action.
	 *
	 * @param event
	 */
	void OnQuit(wxCommandEvent& event);
	/**Represents the call of the application about menu call.
	 *
	 * @param event
	 */
	void OnAbout(wxCommandEvent& event);
	/**Represents the application close event
	 *
	 * @param event
	 */
	void OnClose(wxCommandEvent& event);
	/**Represents the call of a test event
	 *
	 * @param event
	 */
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
