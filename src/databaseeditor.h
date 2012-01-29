#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QDialog>
#include <QDebug>
#include <QStringListModel>
#include <QFileDialog>
#include "genresinfoeditor.h"
#include "datawrappers.h"
#include "DbWrapper.h"
#include "MangaInfo.h"

namespace Ui
{
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
    void updateMangaGenreData(QString selection);
    void updatePublisherData(QString selection);
    DataWrapperS *wrap;
    QGraphicsScene* scene;
    DbWrapper *db;
    QStringListModel *qModel;
    QStringListModel *genresModel;
    bool isNewMangaEntryInProgress;
	bool isNewAuthorEntryInProgress;
	bool isNewPublisherEntryInProgress;
    QByteArray coverArray;

private slots:
    void openGenresEdit();
    void handleMangaComboIndexChanged(QString text);
    void handleAuthorComboIndexChanged(QString text);
    void handlePublisherComboIndexChanged(QString text);
    void listAllManga();
	void listAllAuthors();
	void listAllPublishers();
    void addSelectAuthorToManga();
    void addSelectPublisherToManga();
    void addSelecteGenreToManga();
    void removeSelectedAuthorFromManga();
    void removeSelectedGenreFromManga();
    void removeSelectedPublisherFromManga();
    void openImageSelectionDialog();
    void newManga();
    void saveManga();
    void deleteManga();
    void newAuthor();
    void saveAuthor();
    void deleteAuthor();
    void newPublisher();
    void savePublisher();
    void deletePublisher();
};

#endif // DATABASEEDITOR_H
