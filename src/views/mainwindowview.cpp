#include "mainwindowview.h"

MainWindowView::MainWindowView(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowView)
{
    ui->setupUi(this);

    connect(ui->actionMenuFileQuit, SIGNAL(triggered()),this, SIGNAL(quitApplication()));
}

MainWindowView::~MainWindowView()
{

}

void MainWindowView::updateReadingListData( QSqlTableModel *readingListModel )
{
	QSortFilterProxyModel *readingListSortingFilter = new QSortFilterProxyModel;
	readingListSortingFilter->setSourceModel(readingListSortingFilter);
	ui->readingListTableView->setModel(readingListSortingFilter);
}


