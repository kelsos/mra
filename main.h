#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED
#include <wx/wx.h>
#include <wx/app.h>
/**Represents the application.
 *
 */
class MRApp: public wxApp {
public:
	/**Represents the Initialization process of the application? (I Guess???)
	 *
	 * @return
	 */
	virtual bool OnInit();
};

#endif // MAIN_H_INCLUDED
