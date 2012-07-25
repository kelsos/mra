#ifndef APPLICATIONCONTROLLER_H
#define APPLICATIONCONTROLLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QApplication>
#include <QFile>
#include "mcra.h"
#include "Data/databasecreator.h"
#include "Controllers/usercontroller.h"

class ApplicationController : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationController(QObject *parent = 0);
    void initialize();

private:
    QSqlDatabase db;


signals:
    
public slots:
    void quitApplication();
    void handleAuthenticationSuccess();
    
};

#endif // APPLICATIONCONTROLLER_H
