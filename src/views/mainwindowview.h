#ifndef MAINWINDOWVIEW_H
#define MAINWINDOWVIEW_H

#include <QtWidgets/QMainWindow>
#include <QSortFilterProxyModel>
#include <QSqlTableModel>

#include "ui_mainwindowview.h"

class MainWindowView : public QMainWindow
{
    Q_OBJECT
public:
    MainWindowView(QWidget *parent = 0);
    ~MainWindowView();

private:
    Ui::MainWindowView *ui;

public slots:
	void updateReadingListData(QSqlTableModel *readingListModel);


signals:
    void quitApplication();
	void showInternalWebBrowser(QString selectedMangaTitle);
	void openDatabaseEditor();
	void selectionChanged(const QItemSelection &selected);

};

#endif // MAINWINDOWVIEW_H
