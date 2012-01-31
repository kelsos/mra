#include "databasecreator.h"

DatabaseCreator::DatabaseCreator(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}
void DatabaseCreator::createMangaInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseCreator::createPublisherInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

void DatabaseCreator::createAuthorInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

void DatabaseCreator::createGenreInfoTable()
{
    try
    {
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

void DatabaseCreator::createNewsStorageTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

void DatabaseCreator::createNewsSubscriptionsTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE NEWS_SUBSCRIPTIONS ( "
                      "SUBSCRIPTION_ID INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, "
                      "SUBSCRIPTION_URL NVARCHAR(150) NOT NULL, "
                      "SUBSCRIPTION_CHANNEL_NAME NVARCHAR(150) "
                      ")");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseCreator::createMangaAuthorsTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

void DatabaseCreator::createMangaGenresTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

void DatabaseCreator::createReadingListTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
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

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseCreator::initializeDatabaseTables()
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
