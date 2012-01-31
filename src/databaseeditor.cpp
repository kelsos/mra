#include "databaseeditor.h"
#include "ui_databaseeditor.h"

DatabaseEditor::DatabaseEditor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DatabaseEditor)
{
    ui->setupUi(this);

    //Initialize the Objects
    scene = new QGraphicsScene;
    qModel = new QStringListModel;
    genresModel = new QStringListModel;

    //Connect the signals
    connect(ui->openGenreInfoEditButton, SIGNAL(clicked()),this,SLOT(openGenresEdit()));
    connect(ui->mangaInfoAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleMangaComboIndexChanged(QString)));
    connect(ui->authorsAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handleAuthorComboIndexChanged(QString)));
    connect(ui->publishersAllComboBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(handlePublisherComboIndexChanged(QString)));
    connect(ui->listAllMangaButton, SIGNAL(clicked()),this,SLOT(listAllManga()));
    connect(ui->mangaAuthorsAddButton, SIGNAL(clicked()), this, SLOT(addSelectAuthorToManga()));
    connect(ui->mangaGenreAddButton, SIGNAL(clicked()), this, SLOT(addSelecteGenreToManga()));
    connect(ui->mangaAddPublisherButton, SIGNAL(clicked()), this, SLOT(addSelectPublisherToManga()));
    connect(ui->mangaAuthorsRemoveButton, SIGNAL(clicked()), this, SLOT(removeSelectedAuthorFromManga()));
    connect(ui->mangaRemovePublisherButton, SIGNAL(clicked()),this,SLOT(removeSelectedPublisherFromManga()));
    connect(ui->mangaGenreRemoveButton, SIGNAL(clicked()), this, SLOT(removeSelectedGenreFromManga()));
    connect(ui->mangaCoverAddButton, SIGNAL(clicked()), this, SLOT(openImageSelectionDialog()));
    connect(ui->mangaInfoNewButton, SIGNAL(clicked()), this, SLOT(newManga()));
    connect(ui->mangaInfoSaveButton, SIGNAL(clicked()), this, SLOT(saveManga()));
    connect(ui->mangaInfoDeleteButton, SIGNAL(clicked()), this, SLOT(deleteManga()));
    connect(ui->authorNewButton, SIGNAL(clicked()), this, SLOT(newAuthor()));
    connect(ui->authorDeleteButton, SIGNAL(clicked()), this, SLOT(deleteAuthor()));
    connect(ui->authorSaveButton, SIGNAL(clicked()), this, SLOT(saveAuthor()));
    connect(ui->publisherNewButton, SIGNAL(clicked()), this, SLOT(newPublisher()));
    connect(ui->publisherSaveButton, SIGNAL(clicked()), this, SLOT(savePublisher()));
    connect(ui->publisherDeleteButton, SIGNAL(clicked()), this, SLOT(deletePublisher()));
	connect(ui->listAllAuthorsButton, SIGNAL(clicked()), this, SLOT(listAllAuthors()));
	connect(ui->listAllMangaPublishers, SIGNAL(clicked()), this, SLOT(listAllPublishers()));

    //Populate the status combobox
    ui->mangaPublicationStatusCombobox->addItem("Ongoing");
    ui->mangaPublicationStatusCombobox->addItem("Complete");
    ui->mangaPublicationStatusCombobox->addItem("Hiatus");

	//Populate all the comboboxes with the available data
    ui->mangaInfoAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllMangaInfoTitles());
	ui->authorsAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllAuthorNames());
	ui->publishersAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllPublisherNames());

	//Initialize the new entry lock variable
    isNewMangaEntryInProgress=false;
	isNewAuthorEntryInProgress=false;
	isNewPublisherEntryInProgress=false;

	//Load the totals
    ui->totalMangaLabel->setText(QString::number(DatabaseManager::Instance()->getOperator()->getMangaCount()) + " Total");
	ui->authorsTotaLabel->setText(QString::number(DatabaseManager::Instance()->getOperator()->getAuthorCount()) + " Total");
	ui->publishersTotalLabel->setText(QString::number(DatabaseManager::Instance()->getOperator()->getPublisherCount()) + " Total");
}

DatabaseEditor::~DatabaseEditor()
{
    delete ui;
    //extra-deletes
    delete qModel;
    delete genresModel;
    delete scene;
}

void DatabaseEditor::openGenresEdit()
{
    genresInfoEditor edit;
    edit.exec();

}

void DatabaseEditor::retrieveCover(QString selectionTitle)
{
    scene->clear();
    scene->addPixmap(DatabaseManager::Instance()->getReadDataController()->getMangaCover(selectionTitle));
    ui->mangaCoverGraphicView->setScene(scene);
    ui->mangaCoverGraphicView->show();
}

void  DatabaseEditor::handleMangaComboIndexChanged(QString text)
{
    retrieveCover(text);
    ui->mangaDescriptionTextEdit->setText(DatabaseManager::Instance()->getReadDataController()->getMangaDescription(text));
    ui->mangaTitleLineEdit->setText(text);
    updateStatusCombobox(DatabaseManager::Instance()->getOperator()->getMangaStatus(text));
    updateMangaAuthorData(text);
    updateMangaGenreData(text);
    updatePublisherData(text);
    ui->mangaPublicationDateEdit->setDate(QDate::fromString("01/01/1800","dd/MM/yyyy"));
    ui->mangaPublicationDateEdit->setDateTime(DatabaseManager::Instance()->getOperator()->getPublicationDateForManga(text));
}

void DatabaseEditor::listAllManga()
{
    ui->totalMangaLabel->setText(QString::number(DatabaseManager::Instance()->getOperator()->getMangaCount()) + " Total");
    ui->mangaInfoAllComboBox->clear();
    ui->mangaInfoAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllMangaInfoTitles());
    ui->mangaTitleLineEdit->setText(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::updateStatusCombobox(QString status)
{
    if(status.isNull()||status.isEmpty())
    {
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
    DatabaseManager::Instance()->getOperator()->addGenreForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaGenresComboBox->currentText());
    updateMangaGenreData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::addSelectAuthorToManga()
{
    DatabaseManager::Instance()->getOperator()->addAuthorForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaAuthorsComboBox->currentText());
    updateMangaAuthorData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::addSelectPublisherToManga()
{
    if(isNewMangaEntryInProgress)
    {
        ui->mangaPublisherLineEdit->setText(ui->mangaPublishersComboBox->currentText());
        ui->mangaPublishersComboBox->removeItem(ui->mangaPublishersComboBox->currentIndex());
    }
    else
    {
        DatabaseManager::Instance()->getOperator()->addPublisherForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaPublishersComboBox->currentText());
        updatePublisherData(ui->mangaInfoAllComboBox->currentText());
    }
}

void DatabaseEditor::updateMangaAuthorData(QString selection)
{
    ui->mangaAuthorsComboBox->clear();
    ui->mangaAuthorsComboBox->addItems(DatabaseManager::Instance()->getOperator()->getNonSelectedAuthorsForManga(selection));
    qModel->setStringList(DatabaseManager::Instance()->getOperator()->getAuthorsForManga(selection));
    ui->mangaAuthorsListView->setModel(qModel);
}

void DatabaseEditor::removeSelectedAuthorFromManga()
{
    DatabaseManager::Instance()->getOperator()->removeAuthorForManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaAuthorsListView->currentIndex().data
                               (Qt::DisplayRole).toString());
    updateMangaAuthorData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::updateMangaGenreData(QString selection)
{
    ui->mangaGenresComboBox->clear();
    ui->mangaGenresComboBox->addItems(DatabaseManager::Instance()->getOperator()->getNonSelectedGenresForManga(selection));
    genresModel->setStringList(DatabaseManager::Instance()->getOperator()->getGenresForManga(selection));
    ui->mangaGenresListView->setModel(genresModel);
}

void DatabaseEditor::removeSelectedGenreFromManga()
{
    DatabaseManager::Instance()->getOperator()->removeGenreFromManga(ui->mangaInfoAllComboBox->currentText(),ui->mangaGenresListView->currentIndex().data
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
    if(ba.isEmpty()||ba.isNull())
        return;
    if (isNewMangaEntryInProgress)
    {
        coverArray = ba;
    }
    else
    {
        DatabaseManager::Instance()->getOperator()->updateCoverForManga(ui->mangaInfoAllComboBox->currentText(),ba);
    }

}

void DatabaseEditor::updatePublisherData(QString selection)
{
    ui->mangaPublisherLineEdit->setText(DatabaseManager::Instance()->getOperator()->getPublisherForManga(selection));
    ui->mangaPublishersComboBox->clear();
    ui->mangaPublishersComboBox->addItems(DatabaseManager::Instance()->getOperator()->getNonSelectedPublishersForManga(selection));
}

void DatabaseEditor::removeSelectedPublisherFromManga()
{
    DatabaseManager::Instance()->getOperator()->removePublisherFromManga(ui->mangaInfoAllComboBox->currentText());
    updatePublisherData(ui->mangaInfoAllComboBox->currentText());
}

void DatabaseEditor::newManga()
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
    isNewMangaEntryInProgress=true;
}

void DatabaseEditor::saveManga()
{
    if (isNewMangaEntryInProgress)
    {
        if(ui->mangaTitleLineEdit->text().isNull()||ui->mangaTitleLineEdit->text().isEmpty())
            return;
        QDateTime datetime;
        if(ui->mangaPublicationDateEdit->date()!=QDate::fromString("01/01/1800","dd/MM/yyyy"))
            datetime=ui->mangaPublicationDateEdit->dateTime();
        DatabaseManager::Instance()->getOperator()->insertNewMangaInfo(ui->mangaTitleLineEdit->text(),ui->mangaDescriptionTextEdit->toPlainText(),ui->mangaPublisherLineEdit->text(),datetime,ui->mangaPublicationStatusCombobox->currentText(),coverArray);

        coverArray.clear();
        listAllManga();
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
        isNewMangaEntryInProgress=false;
    }
    else
    {
        QDateTime datetime;
        if(ui->mangaPublicationDateEdit->date()!=QDate::fromString("01/01/1800","dd/MM/yyyy"))
            datetime=ui->mangaPublicationDateEdit->dateTime();
        DatabaseManager::Instance()->getOperator()->updateNewMangaInfo(ui->mangaInfoAllComboBox->currentText(),ui->mangaTitleLineEdit->text(),ui->mangaDescriptionTextEdit->toPlainText(),datetime,ui->mangaPublicationStatusCombobox->currentText());
    }
}

void DatabaseEditor::deleteManga()
{
    if(isNewMangaEntryInProgress)
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
        isNewMangaEntryInProgress=false;
    }
    else
    {
        if(ui->mangaInfoAllComboBox->currentText().isNull()||ui->mangaInfoAllComboBox->currentText().isEmpty())
            return;
        DatabaseManager::Instance()->getOperator()->deleteManga(ui->mangaInfoAllComboBox->currentText());
    }

}

void DatabaseEditor::newAuthor() 
{

}

void DatabaseEditor::saveAuthor() 
{

}

void DatabaseEditor::deleteAuthor() 
{

}

void DatabaseEditor::newPublisher() 
{

}

void DatabaseEditor::savePublisher() 
{

}

void DatabaseEditor::deletePublisher() 
{

}

void DatabaseEditor::handleAuthorComboIndexChanged(QString text) 
{
	ui->authorFullNameTextEdit->setText(text);
	ui->authorBirthDateEdit->setDate(QDate::fromString("01/01/2000","dd/MM/yyyy"));
	ui->authorBirthDateEdit->setDateTime(DatabaseManager::Instance()->getOperator()->getAuthorBirthday(text));
	ui->authorCountryTextEdit->setText(DatabaseManager::Instance()->getOperator()->getAuthorCountryOfBirth(text));
	ui->authorWebsiteTextEdit->setText(DatabaseManager::Instance()->getOperator()->getAuthorWebsite(text));
}

void DatabaseEditor::handlePublisherComboIndexChanged(QString text) 
{
	ui->publisherNameTextEdit->setText(text);
	ui->publisherCountryTextEdit->setText(DatabaseManager::Instance()->getOperator()->getPublisherCountry(text));
	ui->publisherWebsiteTextEdit->setText(DatabaseManager::Instance()->getOperator()->getPublisherWebsite(text));
	ui->publisherNoteTextEdit->setText(DatabaseManager::Instance()->getOperator()->getPublisherNote(text));
}

void DatabaseEditor::listAllAuthors()
{
	ui->authorsAllComboBox->clear();
	ui->authorsAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllAuthorNames());	
}

void DatabaseEditor::listAllPublishers()
{
	ui->publishersAllComboBox->clear();
	ui->publishersAllComboBox->addItems(DatabaseManager::Instance()->getOperator()->getAllPublisherNames());
}