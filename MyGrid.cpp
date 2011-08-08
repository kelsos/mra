#include "MyGrid.h"
MyGrid::MyGrid(wxNotebook * parent)
  : wxGrid(parent, wxID_ANY)
{
  CreateGrid(6, 5);
  SetRowLabelSize(20);
  SetColLabelSize(25);
  SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
  SetLabelFont(wxFont(9, wxFONTFAMILY_DEFAULT,
                      wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD));
  AutoSizeRows();
  for (int i = 0; i < 6 ; i++)
    {
      this->SetRowSize(i, 25);
    }

}
