#include "publisherinfoservice.h"

PublisherInfoService::PublisherInfoService(QSqlDatabase *db, QObject *parent = 0):DataServiceBase(db, parent)
{

}

QStringList PublisherInfoService::getAllPublisherNames()
{
	QString queryString = "SELECT publisher_name FROM publisher_info ORDER BY publisher_name ASC";
	return this->getStringListFromDatabase(queryString);
}

int PublisherInfoService::getPublisherCount()
{
	QString queryString = "SELECT COUNT(*) FROM publisher_info";
	return this->getCountFromDatabase(queryString);    
}

QString PublisherInfoService::getPublisherCountry(QString publisher)
{
	QString queryString = "SELECT publisher_country FROM publisher_info WHERE publisher_name = ?";
	return this->getStringFromDatabase(queryString, publisher);
}    
     
QString PublisherInfoService::getPublisherWebsite(QString publisher)
{
    QString queryString = "SELECT publisher_website FROM publisher_info WHERE publisher_name = ?";
    return this->getStringFromDatabase(queryString, publisher);
}

QString PublisherInfoService::getPublisherNote(QString publisher)
{
    QString queryString = "SELECT publisher_note FROM publisher_info WHERE publisher_name = ?";
	return this->getStringFromDatabase(queryString, publisher);
}