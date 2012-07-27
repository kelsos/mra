#ifndef DATASERVICEBASE_H
#define DATASERVICEBASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QStringList>
#include <QDateTime>

class DataServiceBase : public QObject
{
    Q_OBJECT
public:
    explicit DataServiceBase(QSqlDatabase *db, QObject *parent = 0);
    QString getStringFromDatabase(QString sqlString, QString parameter = "");
    QStringList getStringListFromDatabase(QString sqlString, QString parameter = "");
    int getCountFromDatabase(QString sqlString);
	QDateTime getDateTimeFromDatabase(QString sqlString, QString parameter = "");
	void executeNonQuery(QString sqlString, QString parameter = "");
	void executeNonQuery(QString sqlString, QString firstParameter, QString secondParameter);
	void executeNonQuery(QSqlQuery query);
    
signals:
    
public slots:

private:
    QSqlDatabase *db;
    
};

#endif // DATASERVICEBASE_H
