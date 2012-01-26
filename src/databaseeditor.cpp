#include "databaseeditor.h"
#include "ui_databaseeditor.h"

DatabaseEditor::DatabaseEditor(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DatabaseEditor)
{
  ui->setupUi(this);
}

DatabaseEditor::~DatabaseEditor()
{
  delete ui;
}
