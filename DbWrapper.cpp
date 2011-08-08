#include "DbWrapper.h"

DbWrapper::DbWrapper()
{
    //ctor
    mangaData = new wxSQLite3Database();
    mangaData->Open(wxT("mdb.db3"),wxEmptyString,WXSQLITE_OPEN_READWRITE|WXSQLITE_OPEN_CREATE);
    //initDatabase();
    //insertData();
}

DbWrapper::~DbWrapper()
{
    //dtor
}

bool DbWrapper::isDatabaseConnectionActive()
{
    if (mangaData->IsOpen())
    {
        return true;
    }
    else
    {
        return false;
    }
}

wxSQLite3ResultSet DbWrapper::getUserReadingList()
{

}

int DbWrapper::getMangaID(wxString mangaTitle)
{
    int valueToReturn = -1;

    static const char sql[]=
        "SELECT MANGA_ID "
        "FROM MANGA_INFO "
        "WHERE MANGA_TITLE = ?";
    wxSQLite3Statement st = mangaData->PrepareStatement(sql);

    st.Bind(1,mangaTitle);

    wxSQLite3ResultSet queryResult = st.ExecuteQuery();
    while (queryResult.NextRow())
    {
        valueToReturn = queryResult.GetInt(wxT("MANGA_ID"));
    }
    st.Finalize();

    return valueToReturn;

}

void DbWrapper::insertMangaData(MangaInfo* manga)
{
    static const char sql[]=
        "INSERT INTO MANGA_INFO ( "
        "MANGA_ID, "
        "MANGA_TITLE , "
        "MANGA_DESCRIPTION, "
        "MANGA_PUBLICATION_DATE, "
        "MANGA_PUBLICATION_STATUS, "
        "MANGA_PUBLISHER_ID "
       // "MANGA_COVER "
        " ) VALUES ( "
        "?, ?, ?, ?, ?, ? "
        ")";

    wxSQLite3Statement st = mangaData->PrepareStatement(sql);

    st.Bind(1,(int)manga->GetmangaId());
    st.Bind(2,manga->GetmangaTitle());
    st.Bind(3,manga->GetmangaDescription());
    st.BindDateTime(4,manga->GetmangaPublicationDate());
    st.Bind(5,manga->GetmangaPublicationStatus());
    st.Bind(6,(int)manga->GetmangaPublisherId());

    st.ExecuteUpdate();
    st.Finalize();
}

void DbWrapper::insertMangaData2(unsigned int mangaId, wxString mangaName)
{
    static const char sql[]=
        "INSERT INTO MANGA_INFO ( "
        "MANGA_ID, "
        "MANGA_TITLE "
        " ) VALUES ( "
        "?, ? "
        ")";

    wxSQLite3Statement st = mangaData->PrepareStatement(sql);

    st.Bind(1,(int)mangaId);
    st.Bind(2,mangaName);

    st.ExecuteUpdate();
    st.Finalize();
}

void DbWrapper::createMangaInfoTable()
{
    static const char sql[]=
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

void DbWrapper::createPublisherInfoTable()
{
    static const char sql[]=
        "CREATE TABLE PUBLISHER_INFO ( "
        "PUBLISHER_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "PUBLISHER_NAME NVARCHAR(150) NOT NULL, "
        "PUBLISHER_COUNTRY NVARCHAR(40), "
        "PUBLISHER_WEBSITE NVARCHAR(150), "
        "PUBLISHER_NOTE NVARCHAR(500) "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createAuthorInfoTable()
{
    static const char sql[]=
        "CREATE TABLE AUTHOR_INFO ( "
        "AUTHOR_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "AUTHOR_NAME NVARCHAR(100) NOT NULL, "
        "AUTHOR_NATIONALITY NVARCHAR(40), "
        "AUTHOR_BIRTHDAY DATE, "
        "AUTHOR_WEBSITE NVARCHAR(150) "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createGenreInfoTable()
{
    static const char sql[]=
        "CREATE TABLE GENRE_INFO ( "
        "GENRE_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "GENRE_NAME NVARCHAR(50) "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createNewsStorageTable()
{
    static const char sql[]=
        "CREATE TABLE NEWS_STORAGE ( "
        "NEWSITEM_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "NEWSITEM_TITLE NVARCHAR(150), "
        "NEWSITEM_HYPERLINK NVARCHAR(150), "
        "NEWSITEM_DESCRIPTION NVARCHAR(1000), "
        "NEWSITEM_PUBLICATION_DATE DATE, "
        "NEWSITEM_AQUISITION_DATE DATE "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createNewsSubscriptionsTable()
{
    static const char sql[]=
        "CREATE TABLE NEWS_SUBSCRIPTIONS ( "
        "SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
        "SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
        "SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createMangaAuthorsTable()
{
    static const char sql[]=
        "CREATE TABLE MANGA_AUTHORS ( "
        "MANGA_ID INTEGER  NOT NULL, "
        "AUTHOR_ID INTEGER  NOT NULL, "
        "PRIMARY KEY (MANGA_ID,AUTHOR_ID), "
        "FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
        "FOREIGN KEY (AUTHOR_ID) REFERENCES AUTHOR_INFO(AUTHOR_ID) ON DELETE CASCADE ON UPDATE CASCADE "
        ")";

    mangaData->ExecuteUpdate(sql);

}

void DbWrapper::createMangaGenresTable()
{
    static const char sql[]=
        "CREATE TABLE MANGA_GENRES ( "
        "MANGA_ID INTEGER NOT NULL, "
        "GENRE_ID INTEGER NOT NULL, "
        "PRIMARY KEY (MANGA_ID,GENRE_ID), "
        "FOREIGN KEY (GENRE_ID) REFERENCES GENRE_INFO(GENRE_ID) ON DELETE CASCADE ON UPDATE CASCADE, "
        "FOREIGN KEY (MANGA_ID) REFERENCES MANGA_INFO(MANGA_ID) ON DELETE CASCADE ON UPDATE CASCADE "
        ")";

    mangaData->ExecuteUpdate(sql);
}

void DbWrapper::createReadingListTable()
{
    static const char sql[]=
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

void DbWrapper::initDatabase()
{
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
