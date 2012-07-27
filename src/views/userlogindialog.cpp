#include "userlogindialog.h"
#include "ui_userlogindialog.h"

UserLoginDialog::UserLoginDialog(QWidget *parent) :
		QDialog(parent), ui(new Ui::UserLoginDialog) {
	ui->setupUi(this);
	connect(ui->cancelButton, SIGNAL(clicked()), this,
			SLOT(handleCancelButtonClick()));
	connect(ui->registerPushButton, SIGNAL(clicked()), this,
			SLOT(handleRegisterButtonClick()));
	connect(ui->loginButton, SIGNAL(clicked()), this,
			SLOT(handleLoginButtonClick()));
}

UserLoginDialog::~UserLoginDialog() {
	delete ui;
}

void UserLoginDialog::handleCancelButtonClick() {
	this->close();
}

void UserLoginDialog::handleRegisterButtonClick() {
	emit openRegistrationDialog();
}

void UserLoginDialog::handleLoginButtonClick() {
	emit authenticateUser(ui->userNameLineEdit->text(),
			ui->passwordLineEdit->text());
}

void UserLoginDialog::handleAuthenticationResult(bool result) {
	if (!result) {
		ui->passwordLineEdit->setText("");
		ui->userNameLineEdit->setText("");
	} else {
		this->close();
	}
}
