#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QDialog>
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
    DataWrapperS *wrap;
    QGraphicsScene* scene;
    DbWrapper *db;

private slots:
    void openGenresEdit();
    void handleMangaComboIndexChanged(QString text);
	void browserAllManga();
};

#endif // DATABASEEDITOR_H
