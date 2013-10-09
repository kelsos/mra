#include "applicationcontroller.h"

ApplicationController::ApplicationController(QObject *parent) :
    QObject(parent)
{
}

void ApplicationController::initialize()
{
//    UserController *uController = new UserController(&db);
//    connect(uController, SIGNAL(authenticationSuccess()), this, SLOT(handleAuthenticationSuccess()));
//    uController->initialize();

    //TEMP
    this->handleAuthenticationSuccess();
}

void ApplicationController::quitApplication()
{
    QApplication::exit(0);
}

void ApplicationController::handleAuthenticationSuccess()
{
    MainWindowView *applicationWindow = new MainWindowView();
    connect(applicationWindow, SIGNAL(quitApplication()), this, SLOT(quitApplication()));
    applicationWindow->show();
}
