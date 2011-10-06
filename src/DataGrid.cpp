#include "DataGrid.h"
DataGrid::DataGrid(wxNotebook * parent) :
		wxGrid(parent, wxID_ANY) {
}

void DataGrid::createGrid(){
	CreateGrid(0, 6);
	SetRowLabelSize(20);
	SetColLabelSize(25);
	SetRowLabelAlignment(wxALIGN_RIGHT, wxALIGN_CENTRE);
	SetLabelFont(
			wxFont(9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL,
					wxFONTWEIGHT_BOLD));
	AutoSizeRows();
}
void DataGrid::populateGrid(ReadItem* read, int lineNumber){
	int col = 0;
	wxString debugData = read->getMangaTitle();
	wxLogDebug(_(debugData));
	SetCellValue(read->getMangaTitle(),lineNumber,col++);
	SetCellAlignment(wxALIGN_RIGHT,lineNumber,col);
	SetCellValue(wxString::Format(wxT("%i"),read->getStartingChapter()), lineNumber, col++);
	SetCellAlignment(wxALIGN_RIGHT,lineNumber,col);
	SetCellValue(wxString::Format(wxT("%i"),read->getCurrentChapter()), lineNumber, col++);
	SetCellValue(read->getOnlineUrl(),lineNumber, col++);
	SetCellAlignment(wxALIGN_RIGHT,lineNumber,col);
	SetCellValue(read->getLastRead().FormatDate(),lineNumber, col++);
	SetColFormatBool(col);
	SetCellAlignment(wxALIGN_CENTER,lineNumber,col);
	if(read->getReadFinished()){
	SetCellValue(_("1"),lineNumber, col++);
	}else{
		SetCellValue(_("0"),lineNumber, col++);
	}

}
void DataGrid::addNewLine(){
	InsertRows(GetNumberRows(),1,true);
}

