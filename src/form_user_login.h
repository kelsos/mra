#ifndef FORM_USER_LOGIN_H
#define FORM_USER_LOGIN_H

#if QT_VERSION >= 0x050000
#include <QtWidgets/QDialog>
#else
#include <QtGui/QDialog>
#endif

namespace Ui {
    class form_user_login;
}

class form_user_login : public QDialog
{
    Q_OBJECT
    
public:
    explicit form_user_login(QWidget *parent = 0);
    ~form_user_login();
    
private:
    Ui::form_user_login *ui;

public slots:
    void handleCancelButtonClick();

};

#endif // FORM_USER_LOGIN_H
