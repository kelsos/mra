#ifndef REGISTRATIONDIALOG_H
#define REGISTRATIONDIALOG_H

#include <QDialog>

namespace Ui {
class RegistrationDialog;
}

class RegistrationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RegistrationDialog(QWidget *parent = 0);
    ~RegistrationDialog();

public slots:
    void handleOkButtonClick();
    void handleCancelButtonClick();

signals:
    void registerUser(QString username, QString password);
    
private:
    Ui::RegistrationDialog *ui;
};

#endif // REGISTRATIONDIALOG_H
