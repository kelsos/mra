#include "form_user_login.h"
#include "ui_form_user_login.h"

form_user_login::form_user_login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::form_user_login)
{
    ui->setupUi(this);
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(handleCancelButtonClick()));
    connect(ui->registerPushButton, SIGNAL(clicked()),this,SLOT(handleRegisterButtonClick()));
}

form_user_login::~form_user_login()
{
    delete ui;
}

void form_user_login::handleCancelButtonClick()
{
    this->close();
}

void form_user_login::handleRegisterButtonClick()
{
    FormRegistrationDialog dialog;
    dialog.exec();
}
