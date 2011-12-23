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
	connect(ui.actionMenuFileList, SIGNAL(triggered()),xmlWrap, SLOT(loadUserReadingList()));
	connect(ui.actionMenuFileData, SIGNAL(triggered()),xmlWrap, SLOT(loadApplicationData()));
	connect(ui.actionMenuFileQuit, SIGNAL(triggered()),this, SLOT(quit()));
	timer->start(10000);
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
	ui.readingListTableView->setModel(db->getUserReadingList(ui.actionMenuSettingsDisplayFinished->isChecked()));
	ui.readingListTableView->horizontalHeader()->setResizeMode(0,QHeaderView::Stretch);
	ui.readingListTableView->setColumnWidth(1,60);
	ui.readingListTableView->setColumnWidth(2,60);
	ui.readingListTableView->horizontalHeader()->setResizeMode(3,QHeaderView::Stretch);
	ui.readingListTableView->setColumnWidth(4,80);
	if(ui.actionMenuSettingsDisplayFinished->isChecked())
		ui.readingListTableView->setColumnWidth(5,60);
	connect(ui.readingListTableView->selectionModel(), SIGNAL(selectionChanged(const QItemSelection &, const QItemSelection &)), this,SLOT(handleSelectionChanged(const QItemSelection &)));
}

void mcra::handleSelectionChanged(const QItemSelection &selected)
{
	QModelIndexList selectedIndexes = selected.indexes();
	QString mangaTitle = selectedIndexes.takeFirst().data(Qt::DisplayRole).toString();
	scene->clear();
	scene->addPixmap(db->getMangaCover(mangaTitle));
	ui.coverView->setScene(scene);
	ui.coverView->show();
	ui.textBrowser->setText(db->getMangaDescription(mangaTitle));
	ui.noteTextBrowser->setText(db->getMangaNote(mangaTitle));
	ui.wikipediaWebView->load("http://en.wikipedia.org/wiki/Special:Search?search="+mangaTitle.replace(" ","%20"));
}

void mcra::quit()
{
	QMessageBox quitMessageBox;
	quitMessageBox.setWindowTitle(tr("Manga & Comic Reading Assistant"));
	quitMessageBox.setText(tr("Do you really want to quit?"));
	quitMessageBox.setIcon(QMessageBox::Question);
	quitMessageBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
	quitMessageBox.setDefaultButton(QMessageBox::No);
	if(quitMessageBox.exec() == QMessageBox::Yes)
	qApp->quit();
}
