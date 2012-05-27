#ifndef GENRESINFOEDITOR_H
#define GENRESINFOEDITOR_H

#include <QDialog>
#include "ui_forms_genre_editor.h"

class genresInfoEditor : public QDialog
{
    Q_OBJECT

public:
    explicit genresInfoEditor(QWidget *parent = 0);
    ~genresInfoEditor();

private:
    Ui::GenresInfoEditorForm *ui;
};

#endif // GENRESINFOEDITOR_H
