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
	genresModel = new QStringListModel;

	//Connect the signals
	connect(ui->openGenreInfoEditButton, SIGNAL(clicked()),this,SLOT(openGenresEdit()));
	connect(ui->mangaInfoAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleMangaComboIndexChanged(QString)));
	connect(ui->listAllMangaButton, SIGNAL(clicked()),this,SLOT(browserAllManga()));

	//Populate the status combobox
	ui->mangaPublicationStatusCombobox->addItem("Ongoing");
	ui->mangaPublicationStatusCombobox->addItem("Complete");
	ui->mangaPublicationStatusCombobox->addItem("Hiatus");

	ui->mangaInfoAllComboBox->addItems(wrap->getAllMangaInfoTitles());
}

DatabaseEditor::~DatabaseEditor()
{
	delete ui;
	//extra-deletes
	delete qModel;
	delete genresModel;
	delete scene;
	delete wrap;
	delete db;
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
	genresModel->setStringList(wrap->getGenresForManga(text));
	ui->mangaGenresListView->setModel(genresModel);
	ui->mangaPublisherLineEdit->setText(wrap->getPublisherForManga(text));
	ui->mangaAuthorsComboBox->clear();
	ui->mangaAuthorsComboBox->addItems(wrap->getNonSelectedAuthorsForManga(text));
	ui->mangaGenresComboBox->clear();
	ui->mangaGenresComboBox->addItems(wrap->getNonSelectedGenresForManga(text));
	ui->mangaPublishersComboBox->clear();
	ui->mangaPublishersComboBox->addItems(wrap->getNonSelectedPublishersForManga(text));
	ui->mangaPublicationDateEdit->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
	ui->mangaPublicationDateEdit->setDateTime(wrap->getPublicationDateForManga(text));
}

void DatabaseEditor::browserAllManga()
{
	ui->mangaInfoAllComboBox->clear();
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
	 
