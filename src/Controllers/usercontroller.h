#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QCryptographicHash>
#include <QString>
#include <QVariant>

class UserController : public QObject
{
    Q_OBJECT
public:
    explicit UserController(QSqlDatabase *database, QObject *parent = 0);

private:
    QSqlDatabase *database;

signals:
    void authenticationResult(bool result);
    void registrationResult(bool result);

public slots:
    void authenticateUser(QString username, QString password);
    void registerUser(QString username, QString password);
    
};

#endif // USERCONTROLLER_H
