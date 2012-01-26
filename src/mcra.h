#ifndef SRCMCRA_H
#define SRCMCRA_H

#include <QtGui/QMainWindow>
#include <QtConcurrentRun>
#include <QFuture>
#include <QSqlTableModel>
#include <QMessageBox>
#include "DbWrapper.h"
#include "XmlWrapper.h"
#include "RssFetcher.h"
#include "ui_mcra.h"
#include "About.h"
#include "webBrowser.h"
#include "databaseeditor.h"

class mcra : public QMainWindow
{
    Q_OBJECT

public:
    mcra(QWidget *parent = 0);
    ~mcra();

private:
    Ui::mcraClass ui;
    DbWrapper* db;
    XmlWrapper* xmlWrap;
	QGraphicsScene* scene;
	RssFetcher *rss;
	webBrowser *browserWindow;
	QString selectedMangaTitle;

public slots:
	void update();
	void handleSelectionChanged(const QItemSelection & selected);

private slots:
	void quit();
	void showAbout();
	void updateOnToggle(bool toggle);
	void showWebBrowser();
	void openDatabaseEditor();

signals:
	void navigateToUrl(QString url);

};

#endif // SRCMCRA_H
