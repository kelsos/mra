#include "ui/registrationdialog.h"
#include "ui_registrationdialog.h"

RegistrationDialog::RegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegistrationDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, SIGNAL(accepted()), this, SLOT(handleOkButtonClick()));
    connect(ui->buttonBox, SIGNAL(rejected()), this, SLOT(handleCancelButtonClick()));

}

RegistrationDialog::~RegistrationDialog()
{
    delete ui;
}

void RegistrationDialog::handleOkButtonClick()
{
    emit registerUser(ui->usernamelineEdit->text(), ui->passwordLineEdit->text());
}

void RegistrationDialog::handleCancelButtonClick()
{
    this->close();
}
