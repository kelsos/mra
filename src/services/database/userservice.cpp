#include "userservice.h"

UserService::UserService(QSqlDatabase *db, QObject *parent):QObject(parent) {
	this->db = db;

}

UserService::~UserService() {
	// TODO Auto-generated destructor stub
}

void UserService::registerNewUser(QString username, QString password) {
    QCryptographicHash hash(QCryptographicHash::Sha1);

    QUuid saltGen;
    QString salt = saltGen.createUuid();
    salt = salt.replace("{","");
    salt = salt.replace("}","");
    QString saltedPassword = salt + password + salt;

    hash.addData(saltedPassword.toUtf8());
    QString hashedPassword = QString(hash.result().toHex());

    if(!db->isOpen())
        db->open();

    QSqlQuery query;
    query.prepare("INSERT INTO users (username, password, salt) VALUES (?,?,?)");
    query.bindValue(0, username);
    query.bindValue(1, hashedPassword);
    query.bindValue(2, salt);

    emit registrationResult((query.exec()) ? Successful : Failed);
}

void UserService::authenticateUser(QString username, QString password) {
    QCryptographicHash hash(QCryptographicHash::Sha1);

    if(!db->isOpen())
        db->open();

    QSqlQuery retrieveSalt;
    retrieveSalt.prepare("SELECT salt FROM users WHERE username = ?");
    retrieveSalt.bindValue(0, username);
    retrieveSalt.exec();
    QString salt;

    while(retrieveSalt.next())
    {
        salt = retrieveSalt.value(0).toString();
    }

    /* If the salt is empty something is wrong, or the user was not found */
    if(salt.isNull()||salt.isEmpty()){
    	emit authenticationResult(NotFound);
    	return;
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

    emit authenticationResult((storedPasswordHash == hashedPassword)? Success : WrongPassword);

}
