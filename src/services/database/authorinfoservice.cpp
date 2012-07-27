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
	QString queryString = "SELECT COUNT(*) FROM author_info";
	return this->getCountFromDatabase(queryString);
}

QString AuthorInfoService::getAuthorCountryOfBirth(QString authorName)
{
    QString queryString = "SELECT author_nationality FROM author_info WHERE author_name = ?";
	return this->getStringFromDatabase(queryString, authorName);
}

QDateTime AuthorInfoService::getAuthorBirthday(QString authorName)
{
	QString queryString = "SELECT author_birthday FROM author_info WHERE author_name = ?";
	return this->getDateTimeFromDatabase(queryString, authorName);
}

QString AuthorInfoService::getAuthorWebsite(QString authorName)
{
    QString queryString = "SELECT author_website FROM author_info WHERE author_name = ?";
    return this->getStringFromDatabase(queryString, authorName);
}
