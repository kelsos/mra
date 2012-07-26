#include "genresinfoeditor.h"
#include "ui_forms_genre_editor.h"

GenresInfoEditor::GenresInfoEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenresInfoEditorForm)
{
    ui->setupUi(this);
}

GenresInfoEditor::~GenresInfoEditor()
{
    delete ui;
}
