#ifndef AUTHORINFOSERVICE_H
#define AUTHORINFOSERVICE_H

#include "dataservicebase.h"
#include <QSqlDatabase>
#include <QString>
#include <QStringList>
#include <QDateTime>

class AuthorInfoService : public DataServiceBase
{

public:
    explicit AuthorInfoService(QSqlDatabase *db, QObject *parent = 0);
    int getAuthorCount();
    QStringList getAllAuthorNames();
    QString getAuthorCountryOfBirth(QString authorName);
    QDateTime getAuthorBirthday(QString authorName);
    QString getAuthorWebsite(QString authorName);
    
signals:
    
public slots:
    
};

#endif // AUTHORINFOSERVICE_H
