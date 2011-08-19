#ifndef ABOUTBOX_H
#define ABOUTBOX_H

#include <wx/bitmap.h>
#include <wx/statline.h>
#include <wx/mstream.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum {
	ID_ABOUT_WXBUTTONOK = 4101, ID_ABOUT_WXBUTTONREGISTER = 4102,
};

//AboutBox class
class AboutBox: public wxDialog {
public:
	/** AboutBox constuctor
	 *   \param id the window ID.
	 */
	AboutBox(wxWindowID id);
	/** OnClose function handles the close event of the AboutBox dialog.
	 *   \param event
	 */
	void OnClose(wxCommandEvent& event);
	/** OnButtonOK function handles the OK button press event.
	 *   \param event
	 */
	void OnButtonOK(wxCommandEvent& event);
private:
DECLARE_EVENT_TABLE()
	;
};

#endif // ABOUTBOX_H
