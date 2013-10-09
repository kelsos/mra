#ifndef USERCONTROLLER_H
#define USERCONTROLLER_H

#include <QObject>
#include <QSqlDatabase>

#include "../views/registrationdialog.h"
#include "../views/userlogindialog.h"

class UserController : public QObject
{
    Q_OBJECT
public:
    explicit UserController(QSqlDatabase *database, QObject *parent = 0);
    void initialize();

private:
    QSqlDatabase *database;

signals:
    void authenticationResult(bool result);
    void authenticationSuccess();
    void registrationResult(bool result);

public slots:
    void authenticateUser(QString username, QString password);
    void registerUser(QString username, QString password);
    void openRegistrationDialog();
    
};

#endif // USERCONTROLLER_H
