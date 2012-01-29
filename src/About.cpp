#include "About.h"

About::About(QWidget *parent) : QDialog(parent), ui(new Ui::aboutDialog)
{
    ui->setupUi(this);
}
About::~About()
{
    delete ui;
}