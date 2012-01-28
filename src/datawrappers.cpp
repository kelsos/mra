#include "datawrappers.h"

DataWrapperS::DataWrapperS(QObject *parent) :
    QObject(parent)
{
    //Set database driver to QSQLITE
    database = QSqlDatabase::database();
	if(!database.isOpen())
		database.open();
}

QStringList DataWrapperS::getAllMangaInfoTitles()
{
    QStringList result;
    if(!database.isOpen())
        database.open();
    QSqlQuery query;
    query.prepare("SELECT MANGA_TITLE FROM MANGA_INFO ORDER BY MANGA_TITLE ASC");
    query.exec();
    while(query.next())
        result.append(query.value(0).toString());
    return result;
}

QString DataWrapperS::getMangaStatus(QString mangaTitle)
{	
	QString result;
    if(!database.isOpen())
        database.open();
	QSqlQuery query;
	query.prepare("SELECT MANGA_PUBLICATION_STATUS FROM MANGA_INFO WHERE MANGA_TITLE = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QStringList DataWrapperS::getAuthorsForManga(QString mangaTitle)
{
	QStringList result;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("SELECT AI.AUTHOR_NAME FROM AUTHOR_INFO AI, MANGA_AUTHORS MA, MANGA_INFO MI "
                  "WHERE AI.AUTHOR_ID = MA.AUTHOR_ID AND MA.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QStringList DataWrapperS::getGenresForManga(QString mangaTitle)
{
	QStringList result;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("SELECT GI.GENRE_NAME FROM GENRE_INFO GI, MANGA_GENRES MG, MANGA_INFO MI "
                  "WHERE GI.GENRE_ID = MG.GENRE_ID AND MG.MANGA_ID = MI.MANGA_ID AND MI.MANGA_TITLE = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result.append(query.value(0).toString());
	return result;
}

QString DataWrapperS::getPublisherForManga(QString mangaTitle)
{
	QString result;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("SELECT PI.PUBLISHER_NAME FROM PUBLISHER_INFO PI, MANGA_INFO MI "
                  "WHERE PI.PUBLISHER_ID = MI.MANGA_PUBLISHER_ID AND MI.MANGA_TITLE = ?");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toString();
	return result;
}

QStringList DataWrapperS::getNonSelectedAuthorsForManga(QString mangaTitle)
{
	QStringList result;
	if(!database.isOpen())
		database.open();
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

QStringList DataWrapperS::getNonSelectedGenresForManga(QString mangaTitle)
{
	QStringList result;
	if(!database.isOpen())
		database.open();
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

QStringList DataWrapperS::getNonSelectedPublishersForManga(QString mangaTitle)
{
	QStringList result;
	if(!database.isOpen())
		database.open();
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

QDateTime DataWrapperS::getPublicationDateForManga(QString mangaTitle)
{
	QDateTime result;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("SELECT MANGA_PUBLICATION_DATE FROM MANGA_INFO WHERE MANGA_TITLE = ? ");
	query.bindValue(0,mangaTitle);
	query.exec();
	while(query.next())
		result = query.value(0).toDateTime();
	return result;
}

void DataWrapperS::addAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("INSERT INTO MANGA_AUTHORS (MANGA_ID, AUTHOR_ID) VALUES"
		" ((SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?),(SELECT AUTHOR_ID FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?))");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,authorName);
	query.exec();
}

void DataWrapperS::removeAuthorForManga(QString mangaTitle, QString authorName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(authorName.isNull()||authorName.isEmpty()))
		return;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("DELETE FROM MANGA_AUTHORS "
		"WHERE MANGA_ID IN (SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?) AND AUTHOR_ID IN (SELECT AUTHOR_ID FROM AUTHOR_INFO WHERE AUTHOR_NAME = ?)");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,authorName);
	query.exec();
}


void DataWrapperS::addGenreForManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("INSERT INTO MANGA_GENRES (MANGA_ID, GENRE_ID) VALUES"
		" ((SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?),(SELECT GENRE_ID FROM GENRE_INFO WHERE GENRE_NAME = ?))");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,genreName);
	query.exec();
}
	
void DataWrapperS::removeGenreFromManga(QString mangaTitle, QString genreName)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||(genreName.isNull()||genreName.isEmpty()))
		return;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
	query.prepare("DELETE FROM MANGA_GENRES "
		"WHERE MANGA_ID IN (SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?) AND GENRE_ID IN (SELECT GENRE_ID FROM GENRE_INFO WHERE GENRE_NAME = ?)");
	query.bindValue(0,mangaTitle);
	query.bindValue(1,genreName);
	query.exec();
}
	
void DataWrapperS::addPublisherForManga(QString mangaTitle, QString publisherName)
{
}
	
void DataWrapperS::removePublisherFromManga(QString mangaTitle, QString publisherName)
{

}

void DataWrapperS::updateCoverForManga(QString mangaTitle, QByteArray cover)
{
	if((mangaTitle.isNull()||mangaTitle.isEmpty())||((cover.isNull()||cover.isEmpty())))
		return;
	if(!database.isOpen())
		database.open();
	QSqlQuery query;
    query.prepare("UPDATE MANGA_INFO SET MANGA_COVER = ? WHERE MANGA_TITLE = ?");
    query.bindValue(0,cover);
    query.bindValue(1,mangaTitle);
    query.exec();
}
