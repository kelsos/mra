#include "genresinfoeditor.h"
#include "ui_genresinfoeditor.h"

genresInfoEditor::genresInfoEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::genresInfoEditor)
{
    ui->setupUi(this);
}

genresInfoEditor::~genresInfoEditor()
{
    delete ui;
}
