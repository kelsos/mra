#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QDialog>
#include <QDebug>
#include <QStringListModel>
#include "genresinfoeditor.h"
#include "datawrappers.h"
#include "DbWrapper.h"

namespace Ui {
class DatabaseEditor;
}

class DatabaseEditor : public QDialog
{
    Q_OBJECT

public:
    explicit DatabaseEditor(QWidget *parent = 0);
    ~DatabaseEditor();

private:
    Ui::DatabaseEditor *ui;
    void retrieveCover(QString selectionTitle);
	void updateStatusCombobox(QString status);
	void updateMangaAuthorData(QString selection);
    DataWrapperS *wrap;
    QGraphicsScene* scene;
    DbWrapper *db;
	QStringListModel *qModel;
	QStringListModel *genresModel;

private slots:
    void openGenresEdit();
    void handleMangaComboIndexChanged(QString text);
	void browserAllManga();
	void addSelectAuthorToManga();
	void addSelectPublisherToManga();
	void addSelecteGenreToManga();
	void removeSelectedAuthorFromManga();
};

#endif // DATABASEEDITOR_H
