#include "applicationcontroller.h"

ApplicationController::ApplicationController(QObject *parent) :
    QObject(parent)
{
}

void ApplicationController::initialize()
{

    //TODO: Initialize database if database is not existant.
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("data.db");
    /** If the database does not exist initialize it **/
    if(!QFile::exists("data.db")){
        if(!db.isOpen())
            db.open();
        DatabaseCreator creator(&db);
        creator.initializeDatabaseTables();
    }

    UserController userController(&db);
    userController.initialize();
}
