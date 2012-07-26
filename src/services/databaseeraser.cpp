#include "databaseeraser.h"

DatabaseEraser::DatabaseEraser(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}

void DatabaseEraser::truncateAuthorInfoTable()
{
    executeNonQuery("DELETE FROM author_info");
}

void DatabaseEraser::truncateGenreInfoTable()
{
    executeNonQuery("DELETE FROM genre_info");
}

void DatabaseEraser::truncateMangaAuthorsTable()
{
    executeNonQuery("DELETE FROM manga_authors");
}

void DatabaseEraser::truncateMangaGenresTable()
{
	executeNonQuery("DELETE FROM manga_genres");
}

void DatabaseEraser::truncateMangaInfoTable()
{
    executeNonQuery("DELETE FROM manga_info");
}

void DatabaseEraser::clearStoredNews()
{
    executeNonQuery("DELETE FROM news_storage");
}

void DatabaseEraser::clearSubcriptions()
{
    executeNonQuery("DELETE FROM news_subscriptions");
}

void DatabaseEraser::truncatePublisherInfoTable()
{
    executeNonQuery("DELETE FROM publisher_info");
}

void DatabaseEraser::clearReadingList()
{
    executeNonQuery("DELETE FROM reading_list");
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
