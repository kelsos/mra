#ifndef SRCMCRA_H
#define SRCMCRA_H

#include <QtGui/QMainWindow>
#include <QtConcurrentRun>
#include <QFuture>
#include <QSqlTableModel>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "Data\databasemanager.h"
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
    Ui::mainForm ui;
    XmlWrapper* xmlWrap;
    QGraphicsScene* scene;
    RssFetcher *rss;
    webBrowser *browserWindow;
    QString selectedMangaTitle;
    QSortFilterProxyModel *sortModel;

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
