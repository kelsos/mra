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
    uLogD->exec();
}


void UserController::authenticateUser(QString username, QString password)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    QSqlQuery retrieveSalt;

    if(!database->isOpen())
        database->open();

    retrieveSalt.prepare("SELECT salt FROM users WHERE username = ?");
    retrieveSalt.bindValue(0, username);
    retrieveSalt.exec();
    QString salt;

    while(retrieveSalt.next())
    {
        salt = retrieveSalt.value(0).toString();
    }

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.bindValue(0, username);
    query.exec();

    QString storedPasswordHash;
    while(query.next())
        storedPasswordHash = query.value(0).toString();

    QString saltedPassword = salt + password + salt;

    hash.addData(saltedPassword.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());

    emit authenticationResult(storedPasswordHash == hashedPassword);
}

void UserController::registerUser(QString username, QString password)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);

    QUuid saltGen;
    QString salt = saltGen.createUuid();
    QString saltedPassword = salt + password + salt;

    hash.addData(saltedPassword.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());

    if(!database->isOpen())
        database->open();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, salt) VALUES (?,?,?)");
    query.bindValue(0, username);
    query.bindValue(1, hashedPassword);
    query.bindValue(2, salt);

    emit registrationResult(query.exec());
}

void UserController::openRegistrationDialog()
{
    RegistrationDialog *regDial = new RegistrationDialog();
    connect(regDial, SIGNAL(registerUser(QString, QString)), this, SLOT(registerUser(QString,QString)));
    regDial->exec();
}
