#include "DbWrapper.h"

DbWrapper::DbWrapper() {
	//Set database driver to QSQLITE
	*mangaData = QSqlDatabase::addDatabase("QSQLITE");
	mangaData->setDatabaseName("./mdb.db3");
	//initDatabase();
}

DbWrapper::~DbWrapper() {
	//dtor
}

bool DbWrapper::isDatabaseConnectionActive() {
 return true;
}

QSqlQueryModel* DbWrapper::getUserReadingList() {
	QSqlQueryModel *model = new QSqlQueryModel;
	model->setQuery("SELECT MANGA_TITLE, READ_STARTING_CHAPTER, READ_CURRENT_CHAPTER, READ_ONLINE_URL, READ_IS_FINISHED, READ_LAST_TIME"
			"FROM MANGA_INFO, READING_LIST"
			"WHERE MANGA_INFO.MANGA_ID = READING_LIST.MANGA_ID");

	return model;
}

QString DbWrapper::getMangaTitle(int mangaId) {
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

int DbWrapper::getMangaID(QString mangaTitle) {
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

	return valueToReturn;

}

void DbWrapper::insertReadItem(ReadItem* readItem) {
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
	query.bindValue(i++, getMangaID(readItem->getMangaTitle()));
	query.bindValue(i++, (int) readItem->getStartingChapter());
	query.bindValue(i++, (int) readItem->getCurrentChapter());
	query.bindValue(i++, readItem->getOnlineUrl());
	query.bindValue(i++, readItem->getReadFinished());
	query.bindValue(i++, readItem->getLastRead());
	query.bindValue(i++, readItem->getMangaNote());

	query.exec();
}

void DbWrapper::insertMangaData(MangaInfo* manga) {
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

void DbWrapper::insertAuthorData(AuthorInfo* author) {
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
void DbWrapper::insertGenreData(GenreInfo* genre) {
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
void DbWrapper::insertPublisherData(PublisherInfo* publisher) {
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

void DbWrapper::insertNewsItem(NewsStorage* newsItem) {
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
void DbWrapper::insertNewsSubscription(NewsSubscriptions* subscription) {
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
void DbWrapper::insertMangaAuthor(MangaAuthors* maAuth) {
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

void DbWrapper::insertMangaGenre(MangaGenres* maGen) {
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

void DbWrapper::createMangaInfoTable() {
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

	query.exec();
}

void DbWrapper::createPublisherInfoTable() {
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

void DbWrapper::createAuthorInfoTable() {
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

void DbWrapper::createGenreInfoTable() {
	QSqlQuery query;
	query.prepare("CREATE TABLE GENRE_INFO ( "
			"GENRE_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"GENRE_NAME NVARCHAR(50) "
			")");

	query.exec();
}

void DbWrapper::createNewsStorageTable() {
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

void DbWrapper::createNewsSubscriptionsTable() {
	QSqlQuery query;
	query.prepare("CREATE TABLE NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
			"SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
			")");

	query.exec();
}

void DbWrapper::createMangaAuthorsTable() {
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

void DbWrapper::createMangaGenresTable() {
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

void DbWrapper::createReadingListTable() {
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

	query.exec();
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
	QSqlQuery query;
	query.prepare("SELECT * "
			"FROM MANGA_INFO");

	while (query.next()) {

	}
}

void DbWrapper::truncateAuthorInfoTable(){

}
