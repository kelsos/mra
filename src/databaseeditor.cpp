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
	connect(ui->mangaAuthorsAddButton, SIGNAL(clicked()), this, SLOT(addSelectAuthorToManga()));
	connect(ui->mangaGenreAddButton, SIGNAL(clicked()), this, SLOT(addSelecteGenreToManga()));
	connect(ui->mangaAddPublisherButton, SIGNAL(clicked()), this, SLOT(addSelectPublisherToManga()));
	connect(ui->mangaAuthorsRemoveButton, SIGNAL(clicked()), this, SLOT(removeSelectedAuthorFromManga()));
	connect(ui->mangaRemovePublisherButton, SIGNAL(clicked()),this,SLOT(removeSelectedPublisherFromManga()));
	connect(ui->mangaGenreRemoveButton, SIGNAL(clicked()), this, SLOT(removeSelectedGenreFromManga()));
	connect(ui->mangaCoverAddButton, SIGNAL(clicked()), this, SLOT(openImageSelectionDialog()));
	connect(ui->mangaInfoNewButton,SIGNAL(clicked()),this,SLOT(newData()));
	connect(ui->mangaInfoSaveButton, SIGNAL(clicked()), this, SLOT(saveData()));
	connect(ui->mangaInfoDeleteButton,SIGNAL(clicked()), this, SLOT(deleteData()));

	//Populate the status combobox
	ui->mangaPublicationStatusCombobox->addItem("Ongoing");
	ui->mangaPublicationStatusCombobox->addItem("Complete");
	ui->mangaPublicationStatusCombobox->addItem("Hiatus");

	ui->mangaInfoAllComboBox->addItems(wrap->getAllMangaInfoTitles());
	isNewEntryInProgress=false;
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
	updateMangaAuthorData(text);
	updateMangaGenreData(text);
	updatePublisherData(text);
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

void DatabaseEditor::addSelecteGenreToManga()
{
	wrap->addGenreForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaGenresComboBox->currentText());
	updateMangaGenreData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::addSelectAuthorToManga()
{
	wrap->addAuthorForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaAuthorsComboBox->currentText());
	updateMangaAuthorData(ui->mangaInfoAllComboBox->currentText());
}
	 
void DatabaseEditor::addSelectPublisherToManga()
{
	if(isNewEntryInProgress)
	{
		ui->mangaPublisherLineEdit->setText(ui->mangaPublishersComboBox->currentText());
		ui->mangaPublishersComboBox->removeItem(ui->mangaPublishersComboBox->currentIndex());
	}
	else
	{
		wrap->addPublisherForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaPublishersComboBox->currentText());
		updatePublisherData(ui->mangaInfoAllComboBox->currentText());
	}
}

void DatabaseEditor::updateMangaAuthorData(QString selection)
{
	ui->mangaAuthorsComboBox->clear();
	ui->mangaAuthorsComboBox->addItems(wrap->getNonSelectedAuthorsForManga(selection));
	qModel->setStringList(wrap->getAuthorsForManga(selection));
	ui->mangaAuthorsListView->setModel(qModel);
}

void DatabaseEditor::removeSelectedAuthorFromManga()
{
	wrap->removeAuthorForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaAuthorsListView->currentIndex().data
		(Qt::DisplayRole).toString());
	updateMangaAuthorData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::updateMangaGenreData(QString selection)
{
	ui->mangaGenresComboBox->clear();
	ui->mangaGenresComboBox->addItems(wrap->getNonSelectedGenresForManga(selection));
	genresModel->setStringList(wrap->getGenresForManga(selection));
	ui->mangaGenresListView->setModel(genresModel);
}

void DatabaseEditor::removeSelectedGenreFromManga()
{
	wrap->removeGenreFromManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaGenresListView->currentIndex().data
		(Qt::DisplayRole).toString());
	updateMangaGenreData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::openImageSelectionDialog()
{
	QFileDialog dialog(this);
	dialog.setFileMode(QFileDialog::ExistingFile);
	dialog.setNameFilter(tr("Images (*.png *.jpg)"));
	QString fileName;
	if (dialog.exec())
	{
		fileName=dialog.selectedFiles().first();
	}
	scene->clear();
	QImage image(fileName);
	QPixmap pix = QPixmap::fromImage(image);
	float aspectRatio;
	aspectRatio = pix.height()/pix.width();
	//resizing
	if ((230/160)==aspectRatio)
	{
		pix = pix.scaled(QSize(160,230),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
	}
	else if ((230/160)>aspectRatio)
	{
		pix = pix.scaled(QSize(160,(pix.height())*160/pix.width()),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
	}
	if ((230/160)<aspectRatio)
	{
		pix = pix.scaled(QSize((pix.width()*230)/pix.height(),230),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
	}
	scene->addPixmap(pix);
	ui->mangaCoverGraphicView->setScene(scene);
	ui->mangaCoverGraphicView->show();
	QByteArray ba;
	QBuffer buffer(&ba);
	buffer.open(QIODevice::WriteOnly);
	pix.save(&buffer,"PNG");
	if (isNewEntryInProgress)
	{
		coverArray = ba;
	} 
	else
	{
		wrap->updateCoverForManga(ui->mangaInfoAllComboBox->currentText(),ba);
	}
	
}

void DatabaseEditor::updatePublisherData(QString selection)
{
	ui->mangaPublisherLineEdit->setText(wrap->getPublisherForManga(selection));
	ui->mangaPublishersComboBox->clear();
	ui->mangaPublishersComboBox->addItems(wrap->getNonSelectedPublishersForManga(selection));
}

void DatabaseEditor::removeSelectedPublisherFromManga()
{
	wrap->removePublisherFromManga(ui->mangaInfoAllComboBox->currentText());
	updatePublisherData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::newData()
{
	ui->mangaInfoAllComboBox->setCurrentIndex(-1);
	ui->mangaInfoAllComboBox->setEnabled(false);
	ui->mangaGenreAddButton->setEnabled(false);
	ui->mangaGenreRemoveButton->setEnabled(false);
	ui->mangaGenresComboBox->setEnabled(false);
	ui->mangaGenresComboBox->setCurrentIndex(-1);
	ui->mangaAuthorsAddButton->setEnabled(false);
	ui->mangaAuthorsRemoveButton->setEnabled(false);
	ui->mangaAuthorsComboBox->setEnabled(false);
	ui->mangaAuthorsComboBox->setCurrentIndex(-1);
	isNewEntryInProgress=true;
}

void DatabaseEditor::saveData()
{
	if (isNewEntryInProgress)
	{
		if(ui->mangaTitleLineEdit->text().isNull()||ui->mangaTitleLineEdit->text().isEmpty())
			return;
		QDateTime datetime;
		if(ui->mangaPublicationDateEdit->date()!=QDate::fromString("01/01/1800","dd/MM/yyyy"))
			datetime=ui->mangaPublicationDateEdit->dateTime();
		wrap->insertNewMangaInfo(ui->mangaTitleLineEdit->text(),ui->mangaDescriptionTextEdit->toPlainText(),ui->mangaPublisherLineEdit->text(),datetime,ui->mangaPublicationStatusCombobox->currentText(),coverArray);
		
		coverArray.clear();
		browserAllManga();
		ui->mangaInfoAllComboBox->setCurrentIndex(0);
		ui->mangaInfoAllComboBox->setEnabled(true);
		ui->mangaGenreAddButton->setEnabled(true);
		ui->mangaGenreRemoveButton->setEnabled(true);
		ui->mangaGenresComboBox->setEnabled(true);
		ui->mangaGenresComboBox->setCurrentIndex(0);
		ui->mangaAuthorsAddButton->setEnabled(true);
		ui->mangaAuthorsRemoveButton->setEnabled(true);
		ui->mangaAuthorsComboBox->setEnabled(true);
		ui->mangaAuthorsComboBox->setCurrentIndex(0);
		isNewEntryInProgress=false;
	}
}

void DatabaseEditor::deleteData()
{
	if(isNewEntryInProgress)
	{
		ui->mangaInfoAllComboBox->setCurrentIndex(0);
		ui->mangaInfoAllComboBox->setEnabled(true);
		ui->mangaGenreAddButton->setEnabled(true);
		ui->mangaGenreRemoveButton->setEnabled(true);
		ui->mangaGenresComboBox->setEnabled(true);
		ui->mangaGenresComboBox->setCurrentIndex(0);
		ui->mangaAuthorsAddButton->setEnabled(true);
		ui->mangaAuthorsRemoveButton->setEnabled(true);
		ui->mangaAuthorsComboBox->setEnabled(true);
		ui->mangaAuthorsComboBox->setCurrentIndex(0);
		isNewEntryInProgress=false;
	}
}