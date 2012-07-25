#ifndef USERLOGINDIALOG_H
#define USERLOGINDIALOG_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif
#include "ui/registrationdialog.h"

namespace Ui {
    class UserLoginDialog;
}

class UserLoginDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit UserLoginDialog(QWidget *parent = 0);
    ~UserLoginDialog();
    
private:
    Ui::UserLoginDialog *ui;

public slots:
    void handleCancelButtonClick();
    void handleRegisterButtonClick();
    void handleLoginButtonClick();
    void handleAuthenticationResult(bool result);

signals:
    void openRegistrationDialog();
    void authenticateUser(QString username, QString password);

};

#endif // USERLOGINDIALOG_H
