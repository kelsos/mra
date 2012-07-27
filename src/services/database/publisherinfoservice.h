#ifndef PUBLISHERINFOSERVICE_H
#define PUBLISHERINFOSERVICE_H
#include "dataservicebase.h"

class PublisherInfoService : public DataServiceBase
{
public:
    PublisherInfoService(QSqlDatabase *db, QObject *parent = 0);
    int getPublisherCount();

    QStringList getAllPublisherNames();
    QString getPublisherCountry(QString publisher);
    QString getPublisherWebsite(QString publisher);
    QString getPublisherNote(QString publisher);

private:
};

#endif // PUBLISHERINFOSERVICE_H
