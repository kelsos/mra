#include "mcra.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("Manga & Comic Reading Assistant");
    a.setApplicationVersion("0.01");
    a.setOrganizationName("Kelsos");
    mcra w;
    w.show();
    return a.exec();
}
