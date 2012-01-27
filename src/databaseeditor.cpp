#include "databaseeditor.h"
#include "ui_databaseeditor.h"

DatabaseEditor::DatabaseEditor(QWidget *parent) :
QDialog(parent),
	ui(new Ui::DatabaseEditor)
{
	ui->setupUi(this);

	//Initialize the Objects
	scene = new QGraphicsScene;
	wrap = new DataWrapperS;
	db = new DbWrapper;
	qModel = new QStringListModel;

	//Connect the signals
	connect(ui->openGenreInfoEditButton, SIGNAL(clicked()),this,SLOT(openGenresEdit()));
	connect(ui->mangaInfoAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleMangaComboIndexChanged(QString)));
	connect(ui->listAllMangaButton, SIGNAL(clicked()),this,SLOT(browserAllManga()));
	
	//Populate the mangaCombobox
	ui->mangaInfoAllComboBox->addItems(wrap->getAllMangaInfoTitles());
	ui->mangaTitleLineEdit->setText(ui->mangaInfoAllComboBox->currentText());

	//Populate the status combobox
	ui->mangaPublicationStatusCombobox->addItem("Ongoing");
	ui->mangaPublicationStatusCombobox->addItem("Complete");
	ui->mangaPublicationStatusCombobox->addItem("Hiatus");
}

DatabaseEditor::~DatabaseEditor()
{
	delete ui;
}

void DatabaseEditor::openGenresEdit()
{
	genresInfoEditor edit;
	edit.exec();

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
	ui->mangaDescriptionTextEdit->setText(db->getMangaDescription(text));
	ui->mangaTitleLineEdit->setText(text);
	updateStatusCombobox(wrap->getMangaStatus(text));
	qModel->setStringList(wrap->getAuthorsForManga(text));
	ui->mangaAuthorsListView->setModel(qModel);
}

void DatabaseEditor::browserAllManga()
{
	ui->mangaInfoAllComboBox->addItems(wrap->getAllMangaInfoTitles());
	ui->mangaTitleLineEdit->setText(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::updateStatusCombobox(QString status)
{
	if(status.isNull()||status.isEmpty()){
		ui->mangaPublicationStatusCombobox->setCurrentIndex(-1);
		return;
	}
	if(status.contains("Ongoing"))
		ui->mangaPublicationStatusCombobox->setCurrentIndex(0);
	else if (status.contains("Complete"))
		ui->mangaPublicationStatusCombobox->setCurrentIndex(1);
	else if (status.contains("Hiatus"))
		ui->mangaPublicationStatusCombobox->setCurrentIndex(2);
}
	 
