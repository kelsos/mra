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
    UserController *uController = new UserController(&db);
    connect(uController, SIGNAL(authenticationSuccess()), this, SLOT(handleAuthenticationSuccess()));
    uController->initialize();
}

void ApplicationController::quitApplication()
{
    QApplication::exit(0);
}

void ApplicationController::handleAuthenticationSuccess()
{
    mcra *applicationWindow = new mcra();
    applicationWindow->show();
}
