#include "formregistrationdialog.h"
#include "ui_formregistrationdialog.h"

FormRegistrationDialog::FormRegistrationDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FormRegistrationDialog)
{
    ui->setupUi(this);
}

FormRegistrationDialog::~FormRegistrationDialog()
{
    delete ui;
}
