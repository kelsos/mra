#include "datawrappers.h"

DataWrapperS::DataWrapperS(QObject *parent) :
    QObject(parent)
{
    //Set database driver to QSQLITE
    mangaData = QSqlDatabase::addDatabase("QSQLITE");
    mangaData.setHostName("localhost");
    mangaData.setDatabaseName("mdb.db3");
}

QStringList DataWrapperS::getAllMangaInfoTitles()
{
    QStringList result;
    if(!mangaData.isOpen())
        mangaData.open();
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
	if(!mangaData.isOpen())
		mangaData.open();
	QSqlQuery query;
	query.prepare("SELECT MANGA_PUBLICATION_STATUS FROM MANGA_INFO WHERE MANGA_TITLE = ?");
	query.bindValue(0,mangaTitle);
	while(query.next())
		result = query.value(0).toString();
	return result;
}