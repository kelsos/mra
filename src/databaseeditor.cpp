#include "databaseeditor.h"
#include "ui_databaseeditor.h"

DatabaseEditor::DatabaseEditor(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::DatabaseEditor)
{
  ui->setupUi(this);
  connect(ui->openGenreInfoEditButton, SIGNAL(clicked()),this,SLOT(openGenresEdit()));
  connect(ui->mangaInfoAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleMangaComboIndexChanged(QString)));
  scene = new QGraphicsScene;
  wrap = new DataWrapperS;
  db = new DbWrapper;
}

DatabaseEditor::~DatabaseEditor()
{
  delete ui;
}

void DatabaseEditor::openGenresEdit()
{
	genresInfoEditor edit;
	edit.exec();
    ui->mangaInfoAllComboBox->addItems(wrap->getAllMangaInfoTitles());
}

void DatabaseEditor::retrieveCover(QString selectionTitle)
{
    scene->clear();
    scene->addPixmap(db->getMangaCover(selectionTitle));
    ui->mangaCoverGraphicView->setScene(scene);
    ui->mangaCoverGraphicView->show();
}

void  DatabaseEditor::handleMangaComboIndexChanged(QString text)
{
    retrieveCover(text);
}
