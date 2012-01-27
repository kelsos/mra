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