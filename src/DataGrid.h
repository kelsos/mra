#ifndef DATAGRID_H_INCLUDED
#define DATAGRID_H_INCLUDED
#include <wx/notebook.h>
#include <wx/grid.h>
#include "ReadItem.h"

/**Represents a grid that will be used to display the user's current reading list
 *
 */
class DataGrid: public wxGrid {
public:
	/**Default constructor
	 *
	 * @param parent
	 */
	DataGrid(wxNotebook *parent);
	/**Adds ReadItems data to the Grid
	 *
	 * @param read
	 */
	void populateGrid(ReadItem *read, int lineNumber);
	void createGrid();
	void addNewLine();

private:


};

#endif // MYGRID_H_INCLUDED
