#ifndef MYGRID_H_INCLUDED
#define MYGRID_H_INCLUDED
#include <wx/notebook.h>
#include <wx/grid.h>

/**Represents a grid that will be used to display the user's current reading list
 *
 */
class MyGrid: public wxGrid {
public:
	/**Default constructor
	 *
	 * @param parent
	 */
	MyGrid(wxNotebook *parent);

};

#endif // MYGRID_H_INCLUDED
