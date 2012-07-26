#include "databaseeditoroperator.h"

DatabaseEditorOperator::DatabaseEditorOperator(QSqlDatabase *database, QObject *parent) :
QObject(parent)
{
	this->database=database;
}

QStringList DatabaseEditorOperator::getAllMangaInfoTitles()
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT manga_title FROM manga_info ORDER BY manga_title ASC");
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QString DatabaseEditorOperator::getMangaStatus(QString mangaTitle)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT manga_publication_status FROM manga_info WHERE manga_title = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QStringList DatabaseEditorOperator::getAuthorsForManga(QString mangaTitle)
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT ai.author_name "
                  "FROM author_info ai, manga_authors ma, manga_info mi "
                  "WHERE ai.author_id = ma.author_id AND ma.manga_id = mi.manga_id AND mi.manga_title = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QStringList DatabaseEditorOperator::getGenresForManga(QString mangaTitle)
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT gi.genre_name FROM genre_info gi, manga_genres mg, manga_info mi"
                  "WHERE gi.genre_id = mg.genre_id AND mg.manga_id = mi.manga_id AND mi.manga_title = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QString DatabaseEditorOperator::getPublisherForManga(QString mangaTitle)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT pi.publisher_name FROM publisher_info pi, manga_info mi "
                  "WHERE pi.publisher_id = mi.manga_publisher_id AND mi.manga_title = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QStringList DatabaseEditorOperator::getNonSelectedAuthorsForManga(QString mangaTitle)
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT author_name FROM author_info WHERE author_name NOT IN "
                  "(SELECT ai.author_name FROM author_info ai, manga_authors ma, manga_info mi "
                   "WHERE ai.author_id = ma.author_id AND ma.manga_id = mi.manga_id AND mi.manga_title = ? )");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QStringList DatabaseEditorOperator::getNonSelectedGenresForManga(QString mangaTitle)
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT genre_name FROM genre_info WHERE genre_name NOT IN "
                  "(SELECT gi.genre_name FROM genre_info gi, manga_genres mg, manga_info mi "
                  "WHERE gi.genre_id = mg.genre_id AND mg.manga_id = mi.manga_id AND mi.manga_title = ? )");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QStringList DatabaseEditorOperator::getNonSelectedPublishersForManga(QString mangaTitle)
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT publisher_name FROM publisher_info WHERE publisher_name NOT IN "
                  "(SELECT pi.publisher_name FROM publisher_info pi, manga_info mi "
                  "WHERE pi.publisher_id = mi.manga_publisher_id AND mi.manga_title = ?)");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QDateTime DatabaseEditorOperator::getPublicationDateForManga(QString mangaTitle)
{
	QDateTime result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT manga_publication_year FROM manga_info WHERE manga_title = ? ");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toDateTime();
	return result;
}

void DatabaseEditorOperator::addAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("INSERT INTO manga_authors (manga_id, author_id) VALUES "
                  "((SELECT manga_id FROM manga_info WHERE manga_title = ?),(SELECT author_id FROM author_info WHERE author_name = ?))");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,authorName);
	query.exec();
}

void DatabaseEditorOperator::removeAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("DELETE FROM manga_authors "
                  "WHERE manga_id IN (SELECT manga_id FROM manga_info WHERE manga_title = ?) AND author_id IN (SELECT author_id FROM author_info WHERE author_name = ?)");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,authorName);
	query.exec();
}


void DatabaseEditorOperator::addGenreForManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("INSERT INTO manga_genres (manga_id, genre_id) VALUES "
                  "((SELECT manga_id FROM manga_info WHERE manga_title = ?),(SELECT genre_id FROM genre_info WHERE genre_name = ?))");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,genreName);
	query.exec();
}

void DatabaseEditorOperator::removeGenreFromManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("DELETE FROM manga_genres "
                  "WHERE manga_id IN (SELECT manga_id FROM manga_info WHERE manga_title = ?) AND genre_id IN (SELECT genre_id FROM genre_info WHERE genre_name = ?)");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,genreName);
	query.exec();
}

void DatabaseEditorOperator::addPublisherForManga(QString mangaTitle, QString publisherName)
{
	qDebug() << publisherName;
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(publisherName.isNull()||publisherName.isEmpty()))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("UPDATE manga_info SET manga_publisher_id = (SELECT publisher_id FROM publisher_info WHERE publisher_name = ?) WHERE manga_title = ?");
	query.bindValue(0,publisherName);
	query.bindValue(1,mangaTitle);
	query.exec();
}

void DatabaseEditorOperator::removePublisherFromManga(QString mangaTitle)
{
	if(mangaTitle.isNull()||mangaTitle.isEmpty())
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("UPDATE manga_info SET manga_publisher_id = 0 WHERE manga_title = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
}

void DatabaseEditorOperator::updateCoverForManga(QString mangaTitle, QByteArray cover)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||((cover.isNull()||cover.isEmpty())))
		return;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("UPDATE manga_info SET manga_cover = ? WHERE manga_title = ?");
	query.bindValue(0,cover);
	query.bindValue(1,mangaTitle);
	query.exec();
}

void DatabaseEditorOperator::insertNewMangaInfo(QString title, QString description, QString publisher, QDateTime publicationDate, QString publicationStatus, QByteArray cover)
{
	try
	{
		if(!database->isOpen())
			database->open();
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
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
}

int DatabaseEditorOperator::getMangaCount()
{
	int result = 0;
	try
	{

		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM manga_info");
		query.exec();
		while(query.next())
			result = query.value(0).toInt();

	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
	return result;
}

void DatabaseEditorOperator::deleteManga(QString mangaTitle)
{
	try
	{
		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("DELETE FROM manga_info WHERE manga_title = ?");
		query.bindValue(0,mangaTitle);
		query.exec();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}

}

void DatabaseEditorOperator::updateNewMangaInfo(QString oldTitle, QString newTitle, QString description, QDateTime publicationDate, QString publicationStatus)
{
	try
	{
		if(!database->isOpen())
			database->open();
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
		query.exec();
	}
	catch (std::exception& e)
	{
		qDebug(e.what());
	}
}

QStringList DatabaseEditorOperator::getAllAuthorNames()
{
	QStringList result;
	try
	{
		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("SELECT author_name FROM author_info ORDER BY author_name ASC");
		query.exec();
		while(query.next())
			result.append(query.value(0).toString());
	}
	catch (std::exception& e)
	{
		qDebug(e.what());
	}
	return result;
}

QStringList DatabaseEditorOperator::getAllPublisherNames()
{
	QStringList result;
	try
	{
		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("SELECT publisher_name FROM publisher_info ORDER BY publisher_name ASC");
		query.exec();
		while(query.next())
			result.append(query.value(0).toString());
	}
	catch (std::exception& e)
	{
		qDebug(e.what());
	}
	return result;
}

int DatabaseEditorOperator::getAuthorCount()
{
	int result = 0;
	try
	{

		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM author_info");
		query.exec();
		while(query.next())
			result = query.value(0).toInt();

	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
	return result;
}

int DatabaseEditorOperator::getPublisherCount()
{
	int result = 0;
	try
	{
		if(!database->isOpen())
			database->open();
		QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM publisher_info");
		query.exec();
		while(query.next())
			result = query.value(0).toInt();
	}
	catch(std::exception& e)
	{
		qDebug(e.what());
	}
	return result;
}

QString DatabaseEditorOperator::getAuthorCountryOfBirth(QString authorName)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT author_nationality FROM author_info WHERE author_name = ?");
	query.bindValue(0,authorName);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QDateTime DatabaseEditorOperator::getAuthorBirthday(QString authorName)
{
	QDateTime result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT author_birthday FROM author_info WHERE author_name = ?");
	query.bindValue(0,authorName);
	query.exec();
	while(query.next())
		result = query.value(0).toDateTime();
	return result;
}

QString DatabaseEditorOperator::getAuthorWebsite(QString authorName)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT author_website FROM author_info WHERE author_name = ?");
	query.bindValue(0,authorName);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QString DatabaseEditorOperator::getPublisherCountry(QString publisher)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT publisher_country FROM publisher_info WHERE publisher_name = ?");
	query.bindValue(0,publisher);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QString DatabaseEditorOperator::getPublisherWebsite(QString publisher)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("SELECT publisher_website FROM publisher_info WHERE publisher_name = ?");
	query.bindValue(0,publisher);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QString DatabaseEditorOperator::getPublisherNote(QString publisher)
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
    query.prepare("");
	query.bindValue(0,publisher);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QString DatabaseEditorOperator::getStringFromDatabase( QString queryString, QString parameter )
{
	QString result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
	query.prepare(queryString);
	query.bindValue(0, parameter);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QStringList DatabaseEditorOperator::getStringListFromDatabase( QString queryString, QString parameter )
{
	QStringList result;
	if(!database->isOpen())
		database->open();
	QSqlQuery query;
	query.prepare(queryString);
	query.bindValue(0,parameter);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

