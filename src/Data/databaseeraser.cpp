#include "databaseeraser.h"

DatabaseEraser::DatabaseEraser(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}

void DatabaseEraser::truncateAuthorInfoTable()
{
	executeNonQuery("DELETE FROM AUTHOR_INFO");
}

void DatabaseEraser::truncateGenreInfoTable()
{
	executeNonQuery("DELETE FROM GENRE_INFO");
}

void DatabaseEraser::truncateMangaAuthorsTable()
{
	executeNonQuery("DELETE FROM MANGA_AUTHORS");
}

void DatabaseEraser::truncateMangaGenresTable()
{
	executeNonQuery("DELETE FROM MANGA_GENRES");
}

void DatabaseEraser::truncateMangaInfoTable()
{
	executeNonQuery("DELETE FROM MANGA_INFO");
}

void DatabaseEraser::clearStoredNews()
{
	executeNonQuery("DELETE FROM NEWS_STORAGE");
}

void DatabaseEraser::clearSubcriptions()
{
	executeNonQuery("DELETE FROM NEWS_SUBSCRIPTIONS");
}

void DatabaseEraser::truncatePublisherInfoTable()
{
	executeNonQuery("DELETE FROM PUBLISHER_INFO");
}

void DatabaseEraser::clearReadingList()
{
	executeNonQuery("DELETE FROM READING_LIST");
}

void DatabaseEraser::clearDatabase()
{
	truncateAuthorInfoTable();
	truncateGenreInfoTable();
	truncateMangaAuthorsTable();
	truncateMangaGenresTable();
	truncateMangaInfoTable();
	truncatePublisherInfoTable();
}

void DatabaseEraser::executeNonQuery( QString queryString )
{
	try
	{
		if(!database->isOpen())
			database->open();
		QSqlQuery query;
		query.exec(queryString);
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}
