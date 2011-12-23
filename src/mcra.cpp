#include <QTimer>
#include <QGraphicsScene>
#include "mcra.h"

mcra::mcra(QWidget *parent)
	: QMainWindow(parent)
{
	QTimer *timer= new QTimer(this);

	ui.setupUi(this);
	db = new DbWrapper();
	xmlWrap = new XmlWrapper;
	xmlWrap->connectWithDatabase(db);
	connect(timer, SIGNAL(timeout()), this, SLOT(update()));
	timer->start(10000);
	connect(ui.actionTestHere, SIGNAL(triggered()),xmlWrap, SLOT(loadUserReadingList()));
	connect(ui.actionData, SIGNAL(triggered()),xmlWrap, SLOT(loadApplicationData()));
	scene = new QGraphicsScene;
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
		ui.tableView->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
	ui.tableView->setColumnWidth(1,60);
	ui.tableView->setColumnWidth(2,60);
	ui.tableView->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);
	ui.tableView->setColumnWidth(4,80);
	ui.tableView->setColumnWidth(5,60);
		connect(ui.tableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this,SLOT(handleSelectionChanged(const QItemSelection &)));

		//horizontalHeader->setResizeMode(QHeaderView::Stretch);
}

void mcra::handleSelectionChanged(const QItemSelection &selected)
{
	QModelIndexList selectedIndexes = selected.indexes();
	scene->addPixmap(db->getMangaCover(selectedIndexes.takeFirst().data(Qt::DisplayRole).toString()));
	ui.graphicsView->setScene(scene);
	ui.graphicsView->show();
}
