#include "usercontroller.h"

UserController::UserController(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database = database;
}

void UserController::initialize()
{

    UserLoginDialog *uLogD = new UserLoginDialog();
    connect(uLogD, SIGNAL(openRegistrationDialog()), this, SLOT(openRegistrationDialog()));
    connect(uLogD, SIGNAL(authenticateUser(QString,QString)), this, SLOT(authenticateUser(QString,QString)));
    connect(this, SIGNAL(authenticationResult(bool)), uLogD, SLOT(handleAuthenticationResult(bool)));
    uLogD->exec();
}


void UserController::authenticateUser(QString username, QString password)
{

}

void UserController::registerUser(QString username, QString password)
{

}

void UserController::openRegistrationDialog()
{
    RegistrationDialog *regDial = new RegistrationDialog();
    connect(regDial, SIGNAL(registerUser(QString, QString)), this, SLOT(registerUser(QString,QString)));
    regDial->exec();
}
