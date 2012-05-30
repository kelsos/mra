#include "form_user_login.h"
#include "ui_form_user_login.h"

form_user_login::form_user_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_user_login)
{
    ui->setupUi(this);
}

form_user_login::~form_user_login()
{
    delete ui;
}
