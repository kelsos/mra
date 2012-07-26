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
