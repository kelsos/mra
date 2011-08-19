#ifndef MYGRID_H_INCLUDED
#define MYGRID_H_INCLUDED
#include <wx/notebook.h>
#include <wx/grid.h>

class MyGrid: public wxGrid {
public:
	MyGrid(wxNotebook *parent);

};

#endif // MYGRID_H_INCLUDED
