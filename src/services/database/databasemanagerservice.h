#ifndef DATABASEMANAGERSERVICE_H
#define DATABASEMANAGERSERVICE_H

#include <QObject>
#include <QSqlDatabase>
#include <QFile>

#include "databasetablecreator.h"

class DatabaseManagerService : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManagerService(QObject *parent = 0);
    /**
     * When called this function returns a pointer to the QSqlDatabase.
     * @brief getDatabasePtr
     * @return
     */
    QSqlDatabase *getDatabasePtr();
    
signals:
    
public slots:

private:
    QSqlDatabase db;

    
};

#endif // DATABASEMANAGERSERVICE_H
