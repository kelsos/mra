#include "mangainfoservice.h"

MangaInfoService::MangaInfoService(QSqlDatabase *db, QObject *parent) :
    DataServiceBase(db, parent)
{

}

QStringList MangaInfoService::getAllMangaInfoTitles()
{
	QString queryString = "SELECT manga_title FROM manga_info ORDER BY manga_title ASC";
	return this->getStringListFromDatabase(queryString);
}

QString MangaInfoService::getMangaStatus(QString mangaTitle)
{
	QString queryString = "SELECT manga_publication_status FROM manga_info WHERE manga_title = ?";
	return this->getStringFromDatabase(queryString, mangaTitle);
}

QStringList MangaInfoService::getAuthorsForManga(QString mangaTitle)
{
	QString queryString = "SELECT ai.author_name "
                  "FROM author_info ai, manga_authors ma, manga_info mi "
                  "WHERE ai.author_id = ma.author_id AND ma.manga_id = mi.manga_id AND mi.manga_title = ?";
	return this->getStringListFromDatabase(queryString, mangaTitle);
}

QStringList MangaInfoService::getGenresForManga(QString mangaTitle)
{
	QString queryString = "SELECT gi.genre_name FROM genre_info gi, manga_genres mg, manga_info mi"
                  "WHERE gi.genre_id = mg.genre_id AND mg.manga_id = mi.manga_id AND mi.manga_title = ?";
	return this->getStringListFromDatabase(queryString,mangaTitle);
}

QString MangaInfoService::getPublisherForManga(QString mangaTitle)
{
	QString queryString = "SELECT pi.publisher_name FROM publisher_info pi, manga_info mi "
                  "WHERE pi.publisher_id = mi.manga_publisher_id AND mi.manga_title = ?";
	return this->getStringFromDatabase(queryString,mangaTitle);
}

QStringList MangaInfoService::getNonSelectedAuthorsForManga(QString mangaTitle)
{
	QString queryString = "SELECT author_name FROM author_info WHERE author_name NOT IN "
                  "(SELECT ai.author_name FROM author_info ai, manga_authors ma, manga_info mi "
                   "WHERE ai.author_id = ma.author_id AND ma.manga_id = mi.manga_id AND mi.manga_title = ? )";
	return this->getStringListFromDatabase(queryString,mangaTitle);
}

QStringList MangaInfoService::getNonSelectedGenresForManga(QString mangaTitle)
{
	QString queryString = "SELECT genre_name FROM genre_info WHERE genre_name NOT IN "
                  "(SELECT gi.genre_name FROM genre_info gi, manga_genres mg, manga_info mi "
                  "WHERE gi.genre_id = mg.genre_id AND mg.manga_id = mi.manga_id AND mi.manga_title = ? )";
	return this->getStringListFromDatabase(queryString,mangaTitle);
}

QStringList MangaInfoService::getNonSelectedPublishersForManga(QString mangaTitle)
{
	QString queryString = "SELECT publisher_name FROM publisher_info WHERE publisher_name NOT IN "
                  "(SELECT pi.publisher_name FROM publisher_info pi, manga_info mi "
                  "WHERE pi.publisher_id = mi.manga_publisher_id AND mi.manga_title = ?)";
	return this->getStringListFromDatabase(queryString,mangaTitle);
}

QDateTime MangaInfoService::getPublicationDateForManga(QString mangaTitle)
{
	QString queryString = "SELECT manga_publication_year FROM manga_info WHERE manga_title = ? ";
	return this->getDateTimeFromDatabase(queryString,mangaTitle);
}

void MangaInfoService::addAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
   QString sqlString = "INSERT INTO manga_authors (manga_id, author_id) VALUES "
                  "((SELECT manga_id FROM manga_info WHERE manga_title = ?),(SELECT author_id FROM author_info WHERE author_name = ?))";
   this->executeNonQuery(sqlString,mangaTitle,authorName);

}

void MangaInfoService::removeAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
    QString sqlString = "DELETE FROM manga_authors "
                  "WHERE manga_id IN (SELECT manga_id FROM manga_info WHERE manga_title = ?) AND author_id IN (SELECT author_id FROM author_info WHERE author_name = ?)";
	this->executeNonQuery(sqlString,mangaTitle,authorName);
}


void MangaInfoService::addGenreForManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
QString sqlString = "INSERT INTO manga_genres (manga_id, genre_id) VALUES "
                  "((SELECT manga_id FROM manga_info WHERE manga_title = ?),(SELECT genre_id FROM genre_info WHERE genre_name = ?))";
	this->executeNonQuery(sqlString,mangaTitle,genreName);
}

void MangaInfoService::removeGenreFromManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
	QString sqlString = "DELETE FROM manga_genres "
                  "WHERE manga_id IN (SELECT manga_id FROM manga_info WHERE manga_title = ?) "
				  "AND genre_id IN (SELECT genre_id FROM genre_info WHERE genre_name = ?)";
	this->executeNonQuery(sqlString,mangaTitle,genreName);
}

void MangaInfoService::addPublisherForManga(QString mangaTitle, QString publisherName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(publisherName.isNull()||publisherName.isEmpty()))
		return;
	QString sqlString = "UPDATE manga_info SET manga_publisher_id = (SELECT publisher_id FROM publisher_info WHERE publisher_name = ?) WHERE manga_title = ?";
	this->executeNonQuery(sqlString,publisherName,mangaTitle);
}

void MangaInfoService::removePublisherFromManga(QString mangaTitle)
{
	if(mangaTitle.isNull()||mangaTitle.isEmpty())
		return;
	QString queryString = "UPDATE manga_info SET manga_publisher_id = 0 WHERE manga_title = ?";
	this->executeNonQuery(queryString,mangaTitle);
}

void MangaInfoService::updateCoverForManga(QString mangaTitle, QByteArray cover)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||((cover.isNull()||cover.isEmpty())))
		return;
	QSqlQuery query;
    query.prepare("UPDATE manga_info SET manga_cover = ? WHERE manga_title = ?");
	query.bindValue(0,cover);
	query.bindValue(1,mangaTitle);
	this->executeNonQuery(query);

}

void MangaInfoService::insertNewMangaInfo(QString title, QString description, QString publisher, QDateTime publicationDate, QString publicationStatus, QByteArray cover)
{
		QSqlQuery query;
        query.prepare("INSERT INTO manga_info (manga_title, manga_description, manga_publication_year, manga_publication_status, manga_publisher_id, manga_cover) "
                      "VALUES (?, ?, ?, ?, (SELECT publisher_id FROM publisher_info WHERE publisher_name = ?), ?)");

		int i = 0;
		query.bindValue(i++, title);
		query.bindValue(i++, description);
		query.bindValue(i++, publicationDate);
		query.bindValue(i++, publicationStatus);
		query.bindValue(i++, publisher);
		query.bindValue(i++, cover);
		query.exec();
		this->executeNonQuery(query);
}

int MangaInfoService::getMangaCount()
{
    QString sqlString = "SELECT COUNT(*) FROM manga_info";
	return this->getCountFromDatabase(sqlString);
}

void MangaInfoService::deleteManga(QString mangaTitle)
{
    QString sqlString = "DELETE FROM manga_info WHERE manga_title = ?";
    this->executeNonQuery(sqlString,mangaTitle);
}

void MangaInfoService::updateNewMangaInfo(QString oldTitle, QString newTitle, QString description, QDateTime publicationDate, QString publicationStatus)
{

        QSqlQuery query;
        query.prepare("UPDATE manga_info "
                      "SET manga_title = ?, manga_description = ?, manga_publication_year = ?, manga_publication_status = ?"
                      "WHERE manga_title = ?");
        int i = 0;
        query.bindValue(i++, newTitle);
        query.bindValue(i++, description);
        query.bindValue(i++, publicationDate);
        query.bindValue(i++, publicationStatus);
        query.bindValue(i++, oldTitle);
        this->executeNonQuery(query);

}
