#include "mcra.h"

#include <QtGui>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    mcra w;
    w.show();
    return a.exec();
}
