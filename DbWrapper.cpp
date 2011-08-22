#include "DbWrapper.h"

DbWrapper::DbWrapper() {
	//ctor
	mangaData = new wxSQLite3Database();
	mangaData->Open(wxT("mdb.db3"), wxEmptyString,
			WXSQLITE_OPEN_READWRITE | WXSQLITE_OPEN_CREATE);
//	if (!wxFile::Exists("mdb.db3"))
//	{
		initDatabase();
//	}
}

DbWrapper::~DbWrapper() {
	//dtor
}

bool DbWrapper::isDatabaseConnectionActive() {
	if (mangaData->IsOpen()) {
		return true;
	} else {
		return false;
	}
}

wxSQLite3ResultSet DbWrapper::getUserReadingList() {

}

int DbWrapper::getMangaID(wxString mangaTitle) {
	int valueToReturn = -1;

	static const char sql[] = "SELECT MANGA_ID "
			"FROM MANGA_INFO "
			"WHERE MANGA_TITLE = ?";
	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, mangaTitle);

	wxSQLite3ResultSet queryResult = st.ExecuteQuery();
	while (queryResult.NextRow()) {
		valueToReturn = queryResult.GetInt(wxT("MANGA_ID"));
	}
	st.Finalize();

	return valueToReturn;

}

void DbWrapper::insertMangaData(MangaInfo* manga) {
	static const char sql[] = "INSERT INTO MANGA_INFO ("
			"MANGA_ID, "
			"MANGA_TITLE, "
			"MANGA_DESCRIPTION, "
			"MANGA_PUBLICATION_DATE, "
			"MANGA_PUBLICATION_STATUS, "
			"MANGA_PUBLISHER_ID, "
			"MANGA_COVER"
			") VALUES ("
			"?, ?, ?, ?, ?, ?, ?"
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);
	wxDateTime toDate;

	st.Bind(1, (int) manga->getMangaId());
	st.Bind(2, manga->getMangaTitle());
	st.Bind(3, manga->getMangaDescription());
	st.BindDateTime(4, manga->getMangaPublicationDate());
	st.Bind(5, manga->getMangaPublicationStatus());
	st.Bind(6, (int) manga->getMangaPublisherId());
	st.Bind(7, manga->getMangaCover());
	st.ExecuteUpdate();
	st.Finalize();
}

void DbWrapper::insertAuthorData(AuthorInfo* author) {
	static const char sql[] =
			"INSERT INTO AUTHOR_INFO ("
			"AUTHOR_ID, "
			"AUTHOR_NAME, "
			"AUTHOR_NATIONALITY, "
			"AUTHOR_BIRTHDAY, "
			"AUTHOR_WEBSITE "
			") VALUES ("
			"?, ?, ?, ?, ?"
			")";

	wxDateTime date;
	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int)author->getAuthorId());
	st.Bind(2, author->getAuthorName());
	st.Bind(3, author->getAuthorNationality());
	st.BindDateTime(4, author->getAuthorBirthday());
	st.Bind(5, author->getAuthorWebsite());

	st.ExecuteUpdate();
	st.Finalize();

}
void DbWrapper::insertGenreData(GenreInfo* genre) {
	static const char sql[] = "INSERT INTO GENRE_INFO ("
			"GENRE_ID, "
			"GENRE_NAME "
			") VALUES ( "
			"?, ?"
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int) genre->getGenreId());
	st.Bind(2, genre->getGenreName());
	st.ExecuteUpdate();
	st.Finalize();
}
void DbWrapper::insertPublisherData(PublisherInfo* publisher) {
	static const char sql[] =
			"INSERT INTO PUBLISHER_INFO ( "
			"PUBLISHER_ID, "
			"PUBLISHER_NAME, "
			"PUBLISHER_COUNTRY, "
			"PUBLISHER_WEBSITE, "
			"PUBLISHER_NOTE "
			" ) values ( "
			"?, ?, ?, ?, ?"
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int)publisher->getPublisherId());
	st.Bind(2, publisher->getPublisherName());
	st.Bind(3, publisher->getPublisherCountry());
	st.Bind(4, publisher->getPublisherWebsite());
	st.Bind(5, publisher->getPublisherNote());
	st.ExecuteUpdate();
	st.Finalize();

}

void DbWrapper::insertNewsItem(NewsStorage* newsItem) {
	static const char sql[] = "INSERT INTO NEWS_STORAGE ( "
			"NEWSITEM_ID, "
			"NEWSITEM_TITLE, "
			"NEWSITEM_HYPERLINK, "
			"NEWSITEM_DESCRIPTION, "
			"NEWSITEM_PUBLICATION_DATE, "
			"NEWSITEM_AQUISITION_DATE "
			") VALUES ( "
			"?, ?, ?, ?, ?, ?"
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int) newsItem->getNewsItemId());
	st.Bind(2, newsItem->getNewsItemTitle());
	st.Bind(3, newsItem->getNewsItemHyperLink());
	st.Bind(4, newsItem->getNewsItemDescription());
	st.BindDateTime(5, newsItem->getNewsItemPublicationDate());
	st.BindDateTime(6, newsItem->getNewsItemAquisitionDate());
	st.ExecuteUpdate();
	st.Finalize();

}
void DbWrapper::insertNewsSubscription(NewsSubscriptions* subscription) {
	static const char sql[] = "INSERT INTO NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID, "
			"SUBSCRIPTION_URL, "
			"SUBSCRIPTION_CHANNEL_NAME "
			") VALUES ( "
			"?, ?, ? "
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int) subscription->getSubscriptionId());
	st.Bind(2, subscription->getSubscriptionUrl());
	st.Bind(3, subscription->getSubscriptionChannelName());
	st.ExecuteUpdate();
	st.Finalize();
}
void DbWrapper::insertMangaAuthor(MangaAuthors* maAuth) {
	static const char sql[] = "INSERT INTO MANGA_AUTHORS ( "
			"MANGA_ID, "
			"AUTHOR_ID "
			") VALUES ( "
			"?, ? "
			")";
	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int) maAuth->getMangaId());
	st.Bind(2, (int) maAuth->getAuthorId());
	st.ExecuteUpdate();
	st.Finalize();
}

void DbWrapper::insertMangaGenre(MangaGenres* maGen) {
	static const char sql[] = "INSERT INTO MANGA_GENRES ( "
			"MANGA_ID, "
			"GENRE_ID "
			") VALUES ( "
			"?, ? "
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, (int) maGen->getMangaId());
	st.Bind(2, (int) maGen->getGenreId());
	st.ExecuteUpdate();
	st.Finalize();
}

void DbWrapper::createMangaInfoTable() {
	static const char sql[] =
			"CREATE TABLE MANGA_INFO ( "
					"MANGA_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
					"MANGA_TITLE NVARCHAR(400) NOT NULL, "
					"MANGA_DESCRIPTION NVARCHAR(3000), "
					"MANGA_PUBLICATION_DATE DATE, "
					"MANGA_PUBLICATION_STATUS VARCHAR(30) DEFAULT 'Ongoing', "
					"MANGA_PUBLISHER_ID INTEGER, "
					"MANGA_COVER BLOB, "
					"FOREIGN KEY (MANGA_PUBLISHER_ID) REFERENCES PUBLISHER_INFO(PUBLISHER_ID) ON DELETE CASCADE ON UPDATE CASCADE"
					")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createPublisherInfoTable() {
	static const char sql[] = "CREATE TABLE PUBLISHER_INFO ( "
			"PUBLISHER_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"PUBLISHER_NAME NVARCHAR(150) NOT NULL, "
			"PUBLISHER_COUNTRY NVARCHAR(40), "
			"PUBLISHER_WEBSITE NVARCHAR(150), "
			"PUBLISHER_NOTE NVARCHAR(500) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createAuthorInfoTable() {
	static const char sql[] = "CREATE TABLE AUTHOR_INFO ( "
			"AUTHOR_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"AUTHOR_NAME NVARCHAR(100) NOT NULL, "
			"AUTHOR_NATIONALITY NVARCHAR(40), "
			"AUTHOR_BIRTHDAY DATE, "
			"AUTHOR_WEBSITE NVARCHAR(150) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createGenreInfoTable() {
	static const char sql[] = "CREATE TABLE GENRE_INFO ( "
			"GENRE_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"GENRE_NAME NVARCHAR(50) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createNewsStorageTable() {
	static const char sql[] = "CREATE TABLE NEWS_STORAGE ( "
			"NEWSITEM_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"NEWSITEM_TITLE NVARCHAR(150), "
			"NEWSITEM_HYPERLINK NVARCHAR(150), "
			"NEWSITEM_DESCRIPTION NVARCHAR(1000), "
			"NEWSITEM_PUBLICATION_DATE DATE, "
			"NEWSITEM_AQUISITION_DATE DATE "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createNewsSubscriptionsTable() {
	static const char sql[] = "CREATE TABLE NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
			"SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createMangaAuthorsTable() {
	static const char sql[] =
			"CREATE TABLE MANGA_AUTHORS ( "
					"MANGA_ID INTEGER  NOT NULL, "
					"AUTHOR_ID INTEGER  NOT NULL, "
					"PRIMARY KEY (MANGA_ID,AUTHOR_ID), "
					"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
					"FOREIGN KEY (AUTHOR_ID) REFERENCES AUTHOR_INFO(AUTHOR_ID) ON DELETE CASCADE ON UPDATE CASCADE "
					")";

	mangaData->ExecuteUpdate(sql);

}

void DbWrapper::createMangaGenresTable() {
	static const char sql[] =
			"CREATE TABLE MANGA_GENRES ( "
					"MANGA_ID INTEGER NOT NULL, "
					"GENRE_ID INTEGER NOT NULL, "
					"PRIMARY KEY (MANGA_ID,GENRE_ID), "
					"FOREIGN KEY (GENRE_ID) REFERENCES GENRE_INFO(GENRE_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
					"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE "
					")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createReadingListTable() {
	static const char sql[] =
			"CREATE TABLE READING_LIST ( "
					"ENTRY_ID INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT, "
					"MANGA_ID INTEGER  NOT NULL, "
					"READ_STARTING_CHAPTER INTEGER, "
					"READ_CURRENT_CHAPTER INTEGER, "
					"READ_ONLINE_URL NVARCHAR(150), "
					"READ_IS_FINISHED BOOLEAN, "
					"READ_LAST_TIME DATE, "
					"READ_NOTE NVARCHAR(400), "
					"FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE "
					")";

	mangaData->ExecuteUpdate(sql);
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
	static const char sql[] = "SELECT * "
			"FROM MANGA_INFO";

	wxSQLite3ResultSet rs = mangaData->ExecuteQuery(sql);

	while (rs.NextRow()) {
		wxLogDebug
			(rs.GetString(wxT("MANGA_TITLE")));
	}
}
