#include "DbWrapper.h"

DbWrapper::DbWrapper() {
	//ctor
	mangaData = new wxSQLite3Database();
	mangaData->Open(wxT("mdb.db3"), wxEmptyString,
			WXSQLITE_OPEN_READWRITE | WXSQLITE_OPEN_CREATE);
	initDatabase();
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

void DbWrapper::getUserReadingList(DataGrid* grid) {
	int line = 0;
	grid->createGrid();
	static const char sql[] = "SELECT * "
			"FROM READING_LIST";
	wxSQLite3ResultSet queryResult = mangaData->ExecuteQuery(sql);

	while (queryResult.NextRow()) {
		wxLogDebug(wxString::Format(wxT("%i"),queryResult.GetInt(wxT("MANGA_ID"))));
		wxLogDebug(getMangaTitle(queryResult.GetInt(wxT("MANGA_ID"))));

		ReadItem* newRead = new ReadItem();

		newRead->setMangaTitle(getMangaTitle(queryResult.GetInt(wxT("MANGA_ID"))));
		newRead->setStartingChapter(queryResult.GetInt(wxT("READ_STARTING_CHAPTER")));
		newRead->setCurrentChapter(queryResult.GetInt(wxT("READ_CURRENT_CHAPTER")));
		newRead->setOnlineUrl(queryResult.GetAsString(wxT("READ_ONLINE_URL")));
		newRead->setReadFinished(queryResult.GetBool(wxT("READ_IS_FINISHED")));
		newRead->setLastRead(queryResult.GetDateTime(wxT("READ_LAST_TIME")));
		//newRead->setMangaNote(queryResult.GetString(wxT("READ_NOTE")));
		wxLogDebug(newRead->getLastRead().FormatDate());
		grid->addNewLine();
		grid->populateGrid(newRead,line);
		line++;
	}
}

wxString DbWrapper::getMangaTitle(int mangaId) {
	wxString mangaTitle;
	static const char sql[] = "SELECT MANGA_TITLE "
			"FROM MANGA_INFO "
			"WHERE MANGA_ID = ?";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	st.Bind(1, mangaId);

	wxSQLite3ResultSet queryResult = st.ExecuteQuery();
	while (queryResult.NextRow()) {
		mangaTitle = queryResult.GetAsString(wxT("MANGA_TITLE"));
	}
	st.Finalize();
	return mangaTitle;
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

void DbWrapper::insertReadItem(ReadItem* readItem) {
	static const char sql[] = "INSERT INTO READING_LIST ("
			"MANGA_ID, "
			"READ_STARTING_CHAPTER, "
			"READ_CURRENT_CHAPTER, "
			"READ_ONLINE_URL, "
			"READ_IS_FINISHED, "
			"READ_LAST_TIME, "
			"READ_NOTE"
			") VALUES ("
			"?, ?, ?, ?, ?, ?, ?"
			")";
	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	int i = 0;
	st.Bind(++i, getMangaID(readItem->getMangaTitle()));
	st.Bind(++i, (int) readItem->getStartingChapter());
	st.Bind(++i, (int) readItem->getCurrentChapter());
	st.Bind(++i, readItem->getOnlineUrl());
	st.BindBool(++i, readItem->getReadFinished());
	st.BindDateTime(++i, readItem->getLastRead());
	st.Bind(++i, readItem->getMangaNote());

	st.ExecuteUpdate();
	st.Finalize();
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

	int i = 0;
	st.Bind(++i, (int) manga->getMangaId());
	st.Bind(++i, manga->getMangaTitle());
	st.Bind(++i, manga->getMangaDescription());
	st.BindDateTime(++i, manga->getMangaPublicationDate());
	st.Bind(++i, manga->getMangaPublicationStatus());
	st.Bind(++i, (int) manga->getMangaPublisherId());
	st.Bind(++i, manga->getMangaCover());
	st.ExecuteUpdate();
	st.Finalize();
}

void DbWrapper::insertAuthorData(AuthorInfo* author) {
	static const char sql[] = "INSERT INTO AUTHOR_INFO ("
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

	int i = 0;
	st.Bind(++i, (int) author->getAuthorId());
	st.Bind(++i, author->getAuthorName());
	st.Bind(++i, author->getAuthorNationality());
	st.BindDateTime(++i, author->getAuthorBirthday());
	st.Bind(++i, author->getAuthorWebsite());

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

	int i = 0;
	st.Bind(++i, (int) genre->getGenreId());
	st.Bind(++i, genre->getGenreName());
	st.ExecuteUpdate();
	st.Finalize();
}
void DbWrapper::insertPublisherData(PublisherInfo* publisher) {
	static const char sql[] = "INSERT INTO PUBLISHER_INFO ( "
			"PUBLISHER_ID, "
			"PUBLISHER_NAME, "
			"PUBLISHER_COUNTRY, "
			"PUBLISHER_WEBSITE, "
			"PUBLISHER_NOTE "
			" ) values ( "
			"?, ?, ?, ?, ?"
			")";

	wxSQLite3Statement st = mangaData->PrepareStatement(sql);

	int i = 0;
	st.Bind(++i, (int) publisher->getPublisherId());
	st.Bind(++i, publisher->getPublisherName());
	st.Bind(++i, publisher->getPublisherCountry());
	st.Bind(++i, publisher->getPublisherWebsite());
	st.Bind(++i, publisher->getPublisherNote());
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

	int i = 0;
	st.Bind(++i, (int) newsItem->getNewsItemId());
	st.Bind(++i, newsItem->getNewsItemTitle());
	st.Bind(++i, newsItem->getNewsItemHyperLink());
	st.Bind(++i, newsItem->getNewsItemDescription());
	st.BindDateTime(++i, newsItem->getNewsItemPublicationDate());
	st.BindDateTime(++i, newsItem->getNewsItemAquisitionDate());
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

	int i = 0;
	st.Bind(++i, (int) subscription->getSubscriptionId());
	st.Bind(++i, subscription->getSubscriptionUrl());
	st.Bind(++i, subscription->getSubscriptionChannelName());
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

	int i = 0;
	st.Bind(++i, (int) maAuth->getMangaId());
	st.Bind(++i, (int) maAuth->getAuthorId());
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

	int i = 0;
	st.Bind(++i, (int) maGen->getMangaId());
	st.Bind(++i, (int) maGen->getGenreId());
	st.ExecuteUpdate();
	st.Finalize();
}

void DbWrapper::createMangaInfoTable() {
	if (mangaData->TableExists(wxT("MANGA_INFO")))
		return;
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
	if (mangaData->TableExists(wxT("PUBLISHER_INFO")))
		return;
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
	if (mangaData->TableExists(wxT("AUTHOR_INFO")))
		return;
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
	if (mangaData->TableExists(wxT("GENRE_INFO")))
		return;
	static const char sql[] = "CREATE TABLE GENRE_INFO ( "
			"GENRE_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"GENRE_NAME NVARCHAR(50) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createNewsStorageTable() {
	if (mangaData->TableExists(wxT("NEWS_STORAGE")))
		return;
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
	if (mangaData->TableExists(wxT("NEWS_SUBSCRIPTIONS")))
		return;
	static const char sql[] = "CREATE TABLE NEWS_SUBSCRIPTIONS ( "
			"SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
			"SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
			"SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
			")";

	mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createMangaAuthorsTable() {
	if (mangaData->TableExists(wxT("MANGA_AUTHORS")))
		return;
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
	if (mangaData->TableExists(wxT("MANGA_GENRES")))
		return;
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
	if (mangaData->TableExists(wxT("READING_LIST")))
		return;
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
