#include "datawrappers.h"

DataWrapperS::DataWrapperS(QObject *parent) :
    QObject(parent)
{
    //Set database driver to QSQLITE
    mangaData = QSqlDatabase::addDatabase("QSQLITE");
    mangaData.setHostName("localhost");
    mangaData.setDatabaseName("mdb.db3");
    if(!mangaData.isOpen())
    {
        mangaData.open();
    }
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
    {
        result.append(query.value(0).toString());
    }

    return result;
}
