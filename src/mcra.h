#ifndef SRCMCRA_H
#define SRCMCRA_H

#include <QtGui/QMainWindow>
#include <qsqltablemodel>
#include <DbWrapper.h>
#include "ui_mcra.h"

class mcra : public QMainWindow
{
    Q_OBJECT

public:
    mcra(QWidget *parent = 0);
    ~mcra();

private:
    Ui::mcraClass ui;
    DbWrapper* db;
};

#endif // SRCMCRA_H
