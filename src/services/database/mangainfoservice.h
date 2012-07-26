#ifndef MANGAINFOSERVICE_H
#define MANGAINFOSERVICE_H

#include <QObject>
#include <QSqlDatabase>

class MangaInfoService : public QObject
{
    Q_OBJECT
public:
    explicit MangaInfoService(QSqlDatabase *db, QObject *parent = 0);
    
signals:
    
public slots:

private:
    QSqlDatabase *db;
    
};

#endif // MANGAINFOSERVICE_H
