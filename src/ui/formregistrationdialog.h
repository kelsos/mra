#ifndef FORMREGISTRATIONDIALOG_H
#define FORMREGISTRATIONDIALOG_H

#include <QDialog>

namespace Ui {
class FormRegistrationDialog;
}

class FormRegistrationDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit FormRegistrationDialog(QWidget *parent = 0);
    ~FormRegistrationDialog();
    
private:
    Ui::FormRegistrationDialog *ui;
};

#endif // FORMREGISTRATIONDIALOG_H
