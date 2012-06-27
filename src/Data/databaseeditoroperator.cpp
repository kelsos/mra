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
	query.prepare("SELECT MANGA_PUBLICATION_STATUS FROM MANGA_INFO WHERE MANGA_TITLE = ?");
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
	query.prepare("SELECT AI.AUTHOR_NAME FROM AUTHOR_INFO AI, MANGA_AUTHORS MA, MANGA_INFO MI "
		"WHERE AI.AUTHOR_ID = MA.AUTHOR_ID AND MA.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ?");
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
	query.prepare("SELECT GI.GENRE_NAME FROM GENRE_INFO GI, MANGA_GENRES MG, MANGA_INFO MI "
		"WHERE GI.GENRE_ID = MG.GENRE_ID AND MG.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ?");
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
	query.prepare("SELECT PI.PUBLISHER_NAME FROM PUBLISHER_INFO PI, MANGA_INFO MI "
		"WHERE PI.PUBLISHER_ID = MI.MANGA_PUBLISHER_ID AND MI.MANGA_TITLE = ?");
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
	query.prepare("SELECT AUTHOR_NAME FROM AUTHOR_INFO WHERE AUTHOR_NAME NOT IN "
		"(SELECT AI.AUTHOR_NAME FROM AUTHOR_INFO AI, MANGA_AUTHORS MA, MANGA_INFO MI "
		"WHERE AI.AUTHOR_ID = MA.AUTHOR_ID AND MA.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ? )");
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
	query.prepare("SELECT GENRE_NAME FROM GENRE_INFO WHERE GENRE_NAME NOT IN "
		"(SELECT GI.GENRE_NAME FROM GENRE_INFO GI, MANGA_GENRES MG, MANGA_INFO MI "
		"WHERE GI.GENRE_ID = MG.GENRE_ID AND MG.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ? )");
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
	query.prepare("SELECT PUBLISHER_NAME FROM PUBLISHER_INFO WHERE PUBLISHER_NAME NOT IN "
		"(SELECT PI.PUBLISHER_NAME FROM PUBLISHER_INFO PI, MANGA_INFO MI "
		"WHERE PI.PUBLISHER_ID = MI.MANGA_PUBLISHER_ID AND MI.MANGA_TITLE = ?)");
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
	query.prepare("SELECT MANGA_PUBLICATION_DATE FROM MANGA_INFO WHERE MANGA_TITLE = ? ");
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
	query.prepare("INSERT INTO MANGA_AUTHORS (MANGA_ID, AUTHOR_ID) VALUES"
		" ((SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?),(SELECT AUTHOR_ID FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?))");
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
	query.prepare("DELETE FROM MANGA_AUTHORS "
		"WHERE MANGA_ID IN (SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?) AND AUTHOR_ID IN (SELECT AUTHOR_ID FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?)");
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
	query.prepare("INSERT INTO MANGA_GENRES (MANGA_ID, GENRE_ID) VALUES"
		" ((SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?),(SELECT GENRE_ID FROM GENRE_INFO WHERE GENRE_NAME = ?))");
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
	query.prepare("DELETE FROM MANGA_GENRES "
		"WHERE MANGA_ID IN (SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?) AND GENRE_ID IN (SELECT GENRE_ID FROM GENRE_INFO WHERE GENRE_NAME = ?)");
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
	query.prepare("UPDATE MANGA_INFO SET MANGA_PUBLISHER_ID = (SELECT PUBLISHER_ID FROM PUBLISHER_INFO WHERE PUBLISHER_NAME = ?) WHERE MANGA_TITLE = ?");
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
	query.prepare("UPDATE MANGA_INFO SET MANGA_PUBLISHER_ID = 0 WHERE MANGA_TITLE = ?");
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
	query.prepare("UPDATE MANGA_INFO SET MANGA_COVER = ? WHERE MANGA_TITLE = ?");
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
		query.prepare("INSERT INTO MANGA_INFO (MANGA_TITLE, MANGA_DESCRIPTION, MANGA_PUBLICATION_DATE, "
			"MANGA_PUBLICATION_STATUS, MANGA_PUBLISHER_ID, MANGA_COVER) VALUES (?, ?, ?, ?, (SELECT PUBLISHER_ID FROM PUBLISHER_INFO WHERE PUBLISHER_NAME = ?), ?)");

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
		query.prepare("SELECT COUNT(*) FROM MANGA_INFO");
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
		query.prepare("DELETE FROM MANGA_INFO WHERE MANGA_TITLE = ?");
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
		query.prepare("UPDATE MANGA_INFO SET MANGA_TITLE = ?, MANGA_DESCRIPTION = ?, MANGA_PUBLICATION_DATE = ?, "
			"MANGA_PUBLICATION_STATUS = ? WHERE MANGA_TITLE = ?");
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
		query.prepare("SELECT AUTHOR_NAME FROM AUTHOR_INFO ORDER BY AUTHOR_NAME ASC");
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
		query.prepare("SELECT PUBLISHER_NAME FROM PUBLISHER_INFO ORDER BY PUBLISHER_NAME ASC");
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
		query.prepare("SELECT COUNT(*) FROM AUTHOR_INFO");
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
		query.prepare("SELECT COUNT(*) FROM PUBLISHER_INFO");
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
	query.prepare("SELECT AUTHOR_NATIONALITY FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?");
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
	query.prepare("SELECT AUTHOR_BIRTHDAY FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?");
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
	query.prepare("SELECT AUTHOR_WEBSITE FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?");
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
	query.prepare("SELECT PUBLISHER_COUNTRY FROM PUBLISHER_INFO WHERE PUBLISHER_NAME = ?");
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
	query.prepare("SELECT PUBLISHER_WEBSITE FROM PUBLISHER_INFO WHERE PUBLISHER_NAME = ?");
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
	query.prepare("SELECT PUBLISHER_NOTE FROM PUBLISHER_INFO WHERE PUBLISHER_NAME = ?");
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

