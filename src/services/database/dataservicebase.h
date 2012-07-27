#ifndef DATASERVICEBASE_H
#define DATASERVICEBASE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include <QString>
#include <QStringList>

class DataServiceBase : public QObject
{
    Q_OBJECT
public:
    explicit DataServiceBase(QSqlDatabase *db, QObject *parent = 0);
    QString getStringFromDatabase(QString queryString, QString parameter = "");
    QStringList getStringListFromDatabase(QString queryString, QString parameter = "");
    int getCountFromDatabase(QString queryString);
    QSqlDatabase *getDatabasePtr();
    
signals:
    
public slots:

private:
    QSqlDatabase *db;
    
};

#endif // DATASERVICEBASE_H
