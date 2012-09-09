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
    if(!parameter.isEmpty())
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
    if(!parameter.isEmpty())
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

QDateTime DataServiceBase::getDateTimeFromDatabase(QString queryString, QString parameter)
{
	QDateTime result;
	if(!db->isOpen())
		db->open();
	QSqlQuery query;
	query.prepare(queryString);
	if(!parameter.isEmpty())
		query.bindValue(0,parameter);
	query.exec();
	while(query.next())
		result = query.value(0).toDateTime();
	return result;

}


void DataServiceBase::executeNonQuery( QString sqlString, QString parameter /*= ""*/ )
{
	if(!db->isOpen())
		db->open();
	QSqlQuery query;
	query.prepare(sqlString);
	if(!parameter.isEmpty())
		query.bindValue(0,parameter);
	query.exec();
}

void DataServiceBase::executeNonQuery( QString sqlString, QString firstParameter, QString secondParameter )
{
	if(!db->isOpen())
		db->open();
	QSqlQuery query;
	query.prepare(sqlString);
	query.bindValue(0,firstParameter);
	query.bindValue(1,secondParameter);
	query.exec();
}

void DataServiceBase::executeNonQuery( QSqlQuery query )
{
	if(!db->isOpen())
		db->open();
	query.exec();
}
