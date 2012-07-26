#include "databasetablecreator.h"

DatabaseTableCreator::DatabaseTableCreator(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}
void DatabaseTableCreator::createMangaInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
			database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE manga_info ( "
                      "manga_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                      "manga_title TEXT NOT NULL,"
                      "manga_description TEXT,"
                      "manga_publication_year INT,"
                      "manga_publication_status TEXT DEFAULT 'Ongoing',"
                      "manga_publisher_id INT,"
                      "manga_cover BLOB,"
                      "FOREIGN KEY (manga_publisher_id) REFERENCES publisher_info(publisher_id) ON DELETE CASCADE ON UPDATE CASCADE"
                      ")");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createPublisherInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE publisher_info ( "
                      "publisher_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                      "publisher_name TEXT NOT NULL,"
                      "publisher_country TEXT,"
                      "publisher_website TEXT,"
                      "publisher_note TEXT)");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createAuthorInfoTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE author_info ( "
                      "author_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                      "author_name TEXT NOT NULL,"
                      "author_nationality TEXT,"
                      "author_birthday DATE,"
                      "author_website TEXT)");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createGenreInfoTable()
{
    try
    {
        QSqlQuery query;
        query.prepare("CREATE TABLE genre_info ("
                      "genre_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,"
                      "genre_name TEXT NOT NULL)");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createNewsStorageTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE news_storage ("
                      "newsitem_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,"
                      "newsitem_title TEXT NOT NULL,"
                      "newsitem_hyperlink TEXT,"
                      "newsitem_description TEXT,"
                      "newsitem_publication_date DATE,"
                      "newsitem_aquisition_date DATE)");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createNewsSubscriptionsTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE news_subscriptions ("
                             "subscription_id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT ,"
                             "subscription_url TEXT NOT NULL,"
                             "subcription_channel_name TEXT)");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createMangaAuthorsTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE manga_authors ( "
                      "manga_id INT,"
                      "author_id INT,"
                      "PRIMARY KEY (manga_id,author_id),"
                      "FOREIGN KEY (manga_id) REFERENCES manga_info(manga_id) ON DELETE CASCADE ON UPDATE CASCADE,"
                      "FOREIGN KEY (author_id) REFERENCES author_info(author_id) ON DELETE CASCADE ON UPDATE CASCADE "
                      ")");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createMangaGenresTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE manga_genres ( "
                      "manga_id INT,"
                      "genre_id INT,"
                      "PRIMARY KEY (manga_id,genre_id),"
                      "FOREIGN KEY (manga_id) REFERENCES manga_info(manga_id) ON DELETE CASCADE ON UPDATE CASCADE,"
                      "FOREIGN KEY (genre_id) REFERENCES genre_info(genre_id) ON DELETE CASCADE ON UPDATE CASCADE"
                      ")");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createReadingListTable()
{
    try
    {
        if(!database->isOpen())
        {
            database->open();
        }
        QSqlQuery query;
        query.prepare("CREATE TABLE reading_list ( "
                      "entry_id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                      "manga_id INT NOT NULL,"
                      "read_starting_chapter INT,"
                      "read_current_chapter INT,"
                      "read_is_finished INT,"
                      "read_last_time DATETIME,"
                      "read_note TEXT,"
                      "user_id INT NOT NULL,"
                      "FOREIGN KEY (manga_id) REFERENCES manga_info(manga_id) ON DELETE CASCADE ON UPDATE CASCADE,"
                      "FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE ON UPDATE CASCADE"
                      ")");

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DatabaseTableCreator::createUserTable()
{
    if(!database->isOpen())
    {
        database->open();
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE users ( "
                  "user_id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                  "username TEXT NOT NULL,"
                  "password TEXT NOT NULL,"
                  "salt TEXT NOT NULL,"
                  "UNIQUE (user_id, username)"
                  ")");
    query.exec();
}

void DatabaseTableCreator::createOnlineReaderList()
{
    if(!database->isOpen())
    {
        database->open();
    }
    QSqlQuery query;
    query.prepare("CREATE TABLE online_reader_list ( "
                  "entry_id INTEGER PRIMARY KEY AUTOINCREMENT ,"
                  "online_reader_url TEXT NOT NULL,"
                  "manga_id INT NOT NULL,"
                  "FOREIGN KEY (manga_id) REFERENCES manga_info(manga_id) ON DELETE CASCADE ON UPDATE CASCADE"
                  ")");
    query.exec();
}

void DatabaseTableCreator::initializeDatabaseTables()
{
    createUserTable();
    createAuthorInfoTable();
    createGenreInfoTable();
    createPublisherInfoTable();
    createMangaInfoTable();
    createNewsStorageTable();
    createNewsSubscriptionsTable();
    createMangaAuthorsTable();
    createMangaGenresTable();
    createReadingListTable();
    createOnlineReaderList();
}
