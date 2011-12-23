#include "DbWrapper.h"

DbWrapper::DbWrapper() {
	//Set database driver to QSQLITE
	mangaData = QSqlDatabase::addDatabase("QSQLITE");
	mangaData.setHostName("localhost");
	mangaData.setDatabaseName("mdb.db3");
	if(!mangaData.isOpen())
	{
		mangaData.open();
	}
	initDatabase();
}

DbWrapper::~DbWrapper() {
	//dtor
}

bool DbWrapper::isDatabaseConnectionActive() {
	return true;
}

MangaSqlQueryModel* DbWrapper::getUserReadingList(bool displayFinished) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		MangaSqlQueryModel *model = new MangaSqlQueryModel();
		QString query;
		if(displayFinished)
		{
			query = "SELECT MI.MANGA_TITLE, RL.READ_STARTING_CHAPTER, RL.READ_CURRENT_CHAPTER, RL.READ_ONLINE_URL, RL.READ_LAST_TIME, RL.READ_IS_FINISHED "
				"FROM MANGA_INFO MI, READING_LIST RL "
				"WHERE MI.MANGA_ID = RL.MANGA_ID";
		}
		else
		{
			query = "SELECT MI.MANGA_TITLE, RL.READ_STARTING_CHAPTER, RL.READ_CURRENT_CHAPTER, RL.READ_ONLINE_URL, RL.READ_LAST_TIME "
				"FROM MANGA_INFO MI, READING_LIST RL "
				"WHERE MI.MANGA_ID = RL.MANGA_ID AND RL.READ_IS_FINISHED = 'false'";
		}
		model->setQuery(query,mangaData);

		int i = 0;
		model->setHeaderData(i++,Qt::Horizontal,"Manga Title");
		model->setHeaderData(i++,Qt::Horizontal,"Starting\nChapter");
		model->setHeaderData(i++,Qt::Horizontal,"Current\nChapter");
		model->setHeaderData(i++,Qt::Horizontal,"Online URL");
		model->setHeaderData(i++,Qt::Horizontal,"Last\nRead");
		if(displayFinished)
			model->setHeaderData(i++,Qt::Horizontal,"Finished\nReading?");
		return model;
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

QString DbWrapper::getMangaTitle(int mangaId) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QString mangaTitle;
		QSqlQuery query;
		query.prepare("SELECT MANGA_TITLE "
			"FROM MANGA_INFO "
			"WHERE MANGA_ID = ?");

		query.bindValue(0, mangaId);
		query.exec();

		while (query.next()) {
			mangaTitle = query.value(0).toString();
		}

		return mangaTitle;
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

int DbWrapper::getMangaID(QString mangaTitle) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		int valueToReturn = -1;
		QSqlQuery query;
		query.prepare("SELECT MANGA_ID "
			"FROM MANGA_INFO "
			"WHERE MANGA_TITLE = ?");

		query.bindValue(0, mangaTitle);
		query.exec();

		while (query.next()) {
			valueToReturn = query.value(0).toInt();
		}
		//qDebug() << "mangaId for: " << mangaTitle << " is " << QString::number(valueToReturn,10);
		return valueToReturn;
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::insertReadItem(ReadItem* readItem) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO READING_LIST ("
			"MANGA_ID, "
			"READ_STARTING_CHAPTER, "
			"READ_CURRENT_CHAPTER, "
			"READ_ONLINE_URL, "
			"READ_IS_FINISHED, "
			"READ_LAST_TIME, "
			"READ_NOTE"
			") VALUES ("
			"?, ?, ?, ?, ?, ?, ?"
			")");

		int i = 0;
		if(getMangaID(readItem->getMangaTitle())==-1)
		{
			qDebug("Match of Read Item with Manga Info Failed");
			return;
		}
		query.bindValue(i++, getMangaID(readItem->getMangaTitle()));
		query.bindValue(i++, (int) readItem->getStartingChapter());
		query.bindValue(i++, (int) readItem->getCurrentChapter());
		query.bindValue(i++, readItem->getOnlineUrl());
		query.bindValue(i++, readItem->getReadFinished());
		query.bindValue(i++, readItem->getLastRead());
		query.bindValue(i++, readItem->getMangaNote());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::insertMangaData(MangaInfo* manga) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO MANGA_INFO ("
			"MANGA_ID, "
			"MANGA_TITLE, "
			"MANGA_DESCRIPTION, "
			"MANGA_PUBLICATION_DATE, "
			"MANGA_PUBLICATION_STATUS, "
			"MANGA_PUBLISHER_ID, "
			"MANGA_COVER"
			") VALUES ("
			"?, ?, ?, ?, ?, ?, ?"
			")");

		int i = 0;
		query.bindValue(i++, (int) manga->getMangaId());
		query.bindValue(i++, manga->getMangaTitle());
		query.bindValue(i++, manga->getMangaDescription());
		query.bindValue(i++, manga->getMangaPublicationDate());
		query.bindValue(i++, manga->getMangaPublicationStatus());
		query.bindValue(i++, (int) manga->getMangaPublisherId());
		query.bindValue(i++, manga->getMangaCover());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::insertAuthorData(AuthorInfo* author) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO AUTHOR_INFO ("
			"AUTHOR_ID, "
			"AUTHOR_NAME, "
			"AUTHOR_NATIONALITY, "
			"AUTHOR_BIRTHDAY, "
			"AUTHOR_WEBSITE "
			") VALUES ("
			"?, ?, ?, ?, ?"
			")");


		int i = 0;
		query.bindValue(i++, (int) author->getAuthorId());
		query.bindValue(i++, author->getAuthorName());
		query.bindValue(i++, author->getAuthorNationality());
		query.bindValue(i++, author->getAuthorBirthday());
		query.bindValue(i++, author->getAuthorWebsite());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::insertGenreData(GenreInfo* genre) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO GENRE_INFO ("
			"GENRE_ID, "
			"GENRE_NAME "
			") VALUES ( "
			"?, ?"
			")");

		int i = 0;
		query.bindValue(i++, (int) genre->getGenreId());
		query.bindValue(i++, genre->getGenreName());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::insertPublisherData(PublisherInfo* publisher) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO PUBLISHER_INFO ( "
			"PUBLISHER_ID, "
			"PUBLISHER_NAME, "
			"PUBLISHER_COUNTRY, "
			"PUBLISHER_WEBSITE, "
			"PUBLISHER_NOTE "
			" ) values ( "
			"?, ?, ?, ?, ?"
			")");

		int i = 0;
		query.bindValue(i++, (int) publisher->getPublisherId());
		query.bindValue(i++, publisher->getPublisherName());
		query.bindValue(i++, publisher->getPublisherCountry());
		query.bindValue(i++, publisher->getPublisherWebsite());
		query.bindValue(i++, publisher->getPublisherNote());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::insertNewsItem(NewsStorage* newsItem) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO NEWS_STORAGE ( "
			"NEWSITEM_ID, "
			"NEWSITEM_TITLE, "
			"NEWSITEM_HYPERLINK, "
			"NEWSITEM_DESCRIPTION, "
			"NEWSITEM_PUBLICATION_DATE, "
			"NEWSITEM_AQUISITION_DATE "
			") VALUES ( "
			"?, ?, ?, ?, ?, ?"
			")");

		int i = 0;
		query.bindValue(i++, (int) newsItem->getNewsItemId());
		query.bindValue(i++, newsItem->getNewsItemTitle());
		query.bindValue(i++, newsItem->getNewsItemHyperLink());
		query.bindValue(i++, newsItem->getNewsItemDescription());
		query.bindValue(i++, newsItem->getNewsItemPublicationDate());
		query.bindValue(i++, newsItem->getNewsItemAquisitionDate());
		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::insertNewsSubscription(NewsSubscriptions* subscription) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID, "
			"SUBSCRIPTION_URL, "
			"SUBSCRIPTION_CHANNEL_NAME "
			") VALUES ( "
			"?, ?, ? "
			")");

		int i = 0;
		query.bindValue(i++, (int) subscription->getSubscriptionId());
		query.bindValue(i++, subscription->getSubscriptionUrl());
		query.bindValue(i++, subscription->getSubscriptionChannelName());
		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::insertMangaAuthor(MangaAuthors* maAuth) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO MANGA_AUTHORS ( "
			"MANGA_ID, "
			"AUTHOR_ID "
			") VALUES ( "
			"?, ? "
			")");

		int i = 0;
		query.bindValue(i++, (int) maAuth->getMangaId());
		query.bindValue(i++, (int) maAuth->getAuthorId());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::insertMangaGenre(MangaGenres* maGen) {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("INSERT INTO MANGA_GENRES ( "
			"MANGA_ID, "
			"GENRE_ID "
			") VALUES ( "
			"?, ? "
			")");

		int i = 0;
		query.bindValue(i++, (int) maGen->getMangaId());
		query.bindValue(i++, (int) maGen->getGenreId());

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createMangaInfoTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE MANGA_INFO ( "
			"MANGA_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"MANGA_TITLE NVARCHAR(400) NOT NULL, "
			"MANGA_DESCRIPTION NVARCHAR(3000), "
			"MANGA_PUBLICATION_DATE DATE, "
			"MANGA_PUBLICATION_STATUS VARCHAR(30) DEFAULT 'Ongoing', "
			"MANGA_PUBLISHER_ID INTEGER, "
			"MANGA_COVER BLOB, "
			"FOREIGN KEY (MANGA_PUBLISHER_ID) REFERENCES PUBLISHER_INFO(PUBLISHER_ID) ON DELETE CASCADE ON UPDATE CASCADE"
			")");

		query.exec();	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createPublisherInfoTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE PUBLISHER_INFO ( "
			"PUBLISHER_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"PUBLISHER_NAME NVARCHAR(150) NOT NULL, "
			"PUBLISHER_COUNTRY NVARCHAR(40), "
			"PUBLISHER_WEBSITE NVARCHAR(150), "
			"PUBLISHER_NOTE NVARCHAR(500) "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createAuthorInfoTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE AUTHOR_INFO ( "
			"AUTHOR_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"AUTHOR_NAME NVARCHAR(100) NOT NULL, "
			"AUTHOR_NATIONALITY NVARCHAR(40), "
			"AUTHOR_BIRTHDAY DATE, "
			"AUTHOR_WEBSITE NVARCHAR(150) "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createGenreInfoTable() {
	try{
		QSqlQuery query;
		query.prepare("CREATE TABLE GENRE_INFO ( "
			"GENRE_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"GENRE_NAME NVARCHAR(50) "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createNewsStorageTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE NEWS_STORAGE ( "
			"NEWSITEM_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"NEWSITEM_TITLE NVARCHAR(150), "
			"NEWSITEM_HYPERLINK NVARCHAR(150), "
			"NEWSITEM_DESCRIPTION NVARCHAR(1000), "
			"NEWSITEM_PUBLICATION_DATE DATE, "
			"NEWSITEM_AQUISITION_DATE DATE "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createNewsSubscriptionsTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
			"SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
			")");

		query.exec();	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createMangaAuthorsTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE MANGA_AUTHORS ( "
			"MANGA_ID INTEGER  NOT NULL, "
			"AUTHOR_ID INTEGER  NOT NULL, "
			"PRIMARY KEY (MANGA_ID,AUTHOR_ID), "
			"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
			"FOREIGN KEY (AUTHOR_ID) REFERENCES AUTHOR_INFO(AUTHOR_ID) ON DELETE CASCADE ON UPDATE CASCADE "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createMangaGenresTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE MANGA_GENRES ( "
			"MANGA_ID INTEGER NOT NULL, "
			"GENRE_ID INTEGER NOT NULL, "
			"PRIMARY KEY (MANGA_ID,GENRE_ID), "
			"FOREIGN KEY (GENRE_ID) REFERENCES GENRE_INFO(GENRE_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
			"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE "
			")");

		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::createReadingListTable() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("CREATE TABLE READING_LIST ( "
			"ENTRY_ID INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"MANGA_ID INTEGER  NOT NULL, "
			"READ_STARTING_CHAPTER INTEGER, "
			"READ_CURRENT_CHAPTER INTEGER, "
			"READ_ONLINE_URL NVARCHAR(150), "
			"READ_IS_FINISHED BOOLEAN, "
			"READ_LAST_TIME DATE, "
			"READ_NOTE NVARCHAR(400), "
			"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE "
			")");

		query.exec();	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::initDatabase() {
	createAuthorInfoTable();
	createGenreInfoTable();
	createPublisherInfoTable();
	createMangaInfoTable();
	createNewsStorageTable();
	createNewsSubscriptionsTable();
	createMangaAuthorsTable();
	createMangaGenresTable();
	createReadingListTable();
}

void DbWrapper::getMangaData() {
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("SELECT * "
			"FROM MANGA_INFO");

		while (query.next()) {

		}	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateAuthorInfoTable(){
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM AUTHOR_INFO");
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateGenreInfoTable(){
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}QSqlQuery query;
		query.exec("DELETE FROM GENRE_INFO");
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateMangaAuthorsTable()

{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM MANGA_AUTHORS");	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateMangaGenresTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM MANGA_GENRES");
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateMangaInfoTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM MANGA_INFO");	
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateNewsStorageTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM NEWS_STORAGE");	
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

void DbWrapper::truncateNewsSubscriptionsTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM NEWS_SUBSCRIPTIONS");	
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::truncatePublisherInfoTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM PUBLISHER_INFO");	
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
void DbWrapper::truncateReadingListTable()
{
	try{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.exec("DELETE FROM READING_LIST");	
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

QPixmap DbWrapper::getMangaCover(QString mangaTitle)
{
	try
	{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		query.prepare("SELECT MANGA_COVER "
			"FROM MANGA_INFO "
			"WHERE MANGA_ID = ?");
		query.bindValue(0,this->getMangaID(mangaTitle));
		query.exec();
		QByteArray ba;
		while (query.next())
		{
			ba = query.value(0).toByteArray();
		}
		QGraphicsPixmapItem *pi = new QGraphicsPixmapItem;
		QPixmap pix;
		pix.loadFromData(ba,"PNG");

		if (pix.width()<160)
		{
			pix = pix.scaled(QSize(160,(pix.height())*160/pix.width()),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
		}
		if (pix.height()<230)
		{
			pix = pix.scaled(QSize((pix.width()*230)/pix.height(),230),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
		}
		return pix;
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

QString DbWrapper::getMangaDescription(QString mangaTitle)
{
	try
	{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		QString mangaDescription;
		query.prepare("SELECT MANGA_DESCRIPTION "
			"FROM MANGA_INFO "
			"WHERE MANGA_ID = ?");
		query.bindValue(0,this->getMangaID(mangaTitle));
		query.exec();
		
		while(query.next())
		{
			mangaDescription = query.value(0).toString();
		}
		return mangaDescription;
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

QString DbWrapper::getMangaNote(QString mangaTitle)
{
	try
	{
		if(!mangaData.isOpen())
		{
			mangaData.open();
		}
		QSqlQuery query;
		QString mangaNote;
		query.prepare("SELECT READ_NOTE "
			"FROM READING_LIST "
			"WHERE MANGA_ID = ?");
		query.bindValue(0,this->getMangaID(mangaTitle));
		query.exec();

		while(query.next())
		{
			mangaNote=query.value(0).toString();
		}
		return mangaNote;
			
	}
	catch (std::exception& e)
	{
		qDebug(e.what());
	}
}
