#include <QTimer>
#include <QGraphicsScene>
#include "mcra.h"

mcra::mcra(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    //Database Init

    appData=QSqlDatabase::addDatabase("QSQLITE");
    appData.setHostName("localhost");
    appData.setDatabaseName("mdb.db3");

    //New Objects
    db = new DbWrapper;
    xmlWrap = new XmlWrapper;
    scene = new QGraphicsScene;
    rss = new RssFetcher;
    sortModel = new QSortFilterProxyModel(this);
    QThread* readingThread = new QThread;

    xmlWrap->connectWithDatabase(db);
    //Connect the Singals-Slots
    connect(ui.actionToolbarRefresh, SIGNAL(triggered()), this, SLOT(update()));
    connect(ui.actionMenuSettingsDisplayFinished, SIGNAL(toggled(bool)), this, SLOT(updateOnToggle(bool)));
    connect(ui.actionMenuFileList, SIGNAL(triggered()),xmlWrap, SLOT(loadUserReadingList()));
    connect(ui.actionMenuFileData, SIGNAL(triggered()),xmlWrap, SLOT(loadApplicationData()));
    connect(ui.actionMenuFileQuit, SIGNAL(triggered()),this, SLOT(quit()));
    connect(ui.actionMenuHelpAbout, SIGNAL(triggered()),this, SLOT(showAbout()));
    connect(ui.actionToolbarOpenToRead, SIGNAL(triggered()),this,SLOT(showWebBrowser()));
    connect(ui.actionDatabase_Editor, SIGNAL(triggered()),this,SLOT(openDatabaseEditor()));

    xmlWrap->moveToThread(readingThread);
    readingThread->start();
    update();
}

mcra::~mcra()
{

}

void mcra::update()
{
    sortModel->setSourceModel(db->getUserReadingList(ui.actionMenuSettingsDisplayFinished->isChecked()));
    ui.readingListTableView->setModel(sortModel);
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
    QString selectionTitle = selectedMangaTitle = selectedIndexes.takeFirst().data(Qt::DisplayRole).toString();
    scene->clear();
    scene->addPixmap(db->getMangaCover(selectionTitle));
    ui.coverView->setScene(scene);
    ui.coverView->show();
    ui.textBrowser->setText(db->getMangaDescription(selectionTitle));
    ui.noteTextBrowser->setText(db->getMangaNote(selectionTitle));
    ui.wikipediaWebView->load("http://en.wikipedia.org/wiki/Special:Search?search="+selectionTitle.replace(" ","%20"));
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

void mcra::showAbout()
{
    About abDial;
    abDial.exec();
    //rss->fetch("http://feeds.feedburner.com/mstream?format=xml");
}

void mcra::updateOnToggle(bool toggle)
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

void mcra::showWebBrowser()
{

    browserWindow = new webBrowser();
    connect(this,SIGNAL(navigateToUrl(QString)),browserWindow,SLOT(navigateToUrl(QString)));

    browserWindow->show();
    qDebug() << selectedMangaTitle;
    emit navigateToUrl(db->getMangaUrl(selectedMangaTitle));
}

void mcra::openDatabaseEditor()
{
    DatabaseEditor dbEdit;
    dbEdit.exec();
}
