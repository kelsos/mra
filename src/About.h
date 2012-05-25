#ifndef ABOUT_H
#define ABOUT_H
#include <QDialog>
#include "ui_forms_about.h"

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

private:
    Ui::aboutDialog *ui;
};

#endif // ABOUT_H
