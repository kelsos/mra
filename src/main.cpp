#include "views/mcra.h"

#include <QtGui>
#include <QApplication>
#include <QWindowsVistaStyle>
#include "controllers/applicationcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Manga & Comic Reading Assistant");
    a.setApplicationVersion("0.01");
    a.setOrganizationName("Kelsos");
    ApplicationController appControl;
    appControl.initialize();

    return a.exec();
}
