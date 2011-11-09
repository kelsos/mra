#include "mcra.h"

mcra::mcra(QWidget *parent)
    : QMainWindow(parent)
{
	ui.setupUi(this);
	db = new DbWrapper();
	ui.tableView->setModel(db->getUserReadingList());
}

mcra::~mcra()
{

}
