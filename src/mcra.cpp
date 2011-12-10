#include <QTimer>
#include "mcra.h"

mcra::mcra(QWidget *parent)
    : QMainWindow(parent)
{
	QTimer *timer= new QTimer(this);

	ui.setupUi(this);
	db = new DbWrapper();
	xmlWrap = new XmlWrapper;
	xmlWrap->connectWithDatabase(db);
	ui.tableView->setModel(db->getUserReadingList());
	     connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	     timer->start(10000);
	     connect(ui.actionTestHere, SIGNAL(triggered()),xmlWrap, SLOT(loadUserReadingList()));
	 	QThread* readingThread = new QThread;
	 	xmlWrap->moveToThread(readingThread);
	 	readingThread->start();
}

mcra::~mcra()
{

}

void mcra::update()
{
	ui.tableView->setModel(db->getUserReadingList());
}
