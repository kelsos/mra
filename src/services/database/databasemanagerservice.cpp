#include "databasemanagerservice.h"

DatabaseManagerService::DatabaseManagerService(QObject *parent) :
    QObject(parent)
{
    //TODO: Initialize database if database is not existant.
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    /** If the database does not exist initialize it **/
    if(!QFile::exists("data.db")){
        if(!db.isOpen())
            db.open();
        DatabaseTableCreator creator(&db);
        creator.initializeDatabaseTables();
    }
}

QSqlDatabase *DatabaseManagerService::getDatabasePtr()
{
    return &this->db;
}
