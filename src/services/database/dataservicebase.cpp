#include "dataservicebase.h"

DataServiceBase::DataServiceBase(QSqlDatabase *db, QObject *parent) :
    QObject(parent)
{
    this->db = db;
}

QString DataServiceBase::getStringFromDatabase( QString queryString, QString parameter)
{
    QString result;
    if(!db->isOpen())
        db->open();
    QSqlQuery query;
    query.prepare(queryString);
	if(!parameter.isEmpty)
		query.bindValue(0, parameter);
    query.exec();
    while(query.next())
        result = query.value(0).toString();
    return result;
}

QStringList DataServiceBase::getStringListFromDatabase( QString queryString, QString parameter)
{
    QStringList result;
    if(!db->isOpen())
        db->open();
    QSqlQuery query;
    query.prepare(queryString);
	if(!parameter.isEmpty)
		query.bindValue(0,parameter);
    query.exec();
    while(query.next())
        result.append(query.value(0).toString());
    return result;
}

int DataServiceBase::getCountFromDatabase(QString queryString)
{
    int result;
    if(!db->isOpen())
        db->open();
    QSqlQuery query;
    query.prepare(queryString);
    query.exec();
    while(query.next())
        result = query.value(0).toInt();
    return result;
}

QSqlDatabase *DataServiceBase::getDatabasePtr()
{
    return this->db;
}
