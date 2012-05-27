#include "genresinfoeditor.h"

genresInfoEditor::genresInfoEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenresInfoEditorForm)
{
    ui->setupUi(this);
}

genresInfoEditor::~genresInfoEditor()
{
    delete ui;
}
