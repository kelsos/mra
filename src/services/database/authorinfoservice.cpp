#include "authorinfoservice.h"

AuthorInfoService::AuthorInfoService(QSqlDatabase *db, QObject *parent) :
    DataServiceBase(db, parent)
{
}

QStringList AuthorInfoService::getAllAuthorNames()
{
    QString queryString ="SELECT author_name FROM author_info ORDER BY author_name ASC";
	return this->getStringListFromDatabase(queryString);   
}

int AuthorInfoService::getAuthorCount()
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

QString AuthorInfoService::getAuthorCountryOfBirth(QString authorName)
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

QDateTime AuthorInfoService::getAuthorBirthday(QString authorName)
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

QString AuthorInfoService::getAuthorWebsite(QString authorName)
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
