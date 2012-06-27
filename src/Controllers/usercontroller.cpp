#include "usercontroller.h"

UserController::UserController(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database = database;
}


void UserController::authenticateUser(QString username, QString password)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(password.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());

    if(!database->isOpen())
        database->open();

    QSqlQuery query;
    query.prepare("SELECT password FROM users WHERE username = ?");
    query.bindValue(0, username);
    query.exec();

    QString queryResult;
    while(query.next())
        queryResult = query.value(0).toString();

    emit authenticationResult(queryResult == hashedPassword);
}

void UserController::registerUser(QString username, QString password)
{
    QCryptographicHash hash(QCryptographicHash::Sha1);
    hash.addData(password.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());

    if(!database->isOpen())
        database->open();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password) VALUES (?,?)");
    query.bindValue(0, username);
    query.bindValue(1, hashedPassword);

    emit registrationResult(query.exec());
}
