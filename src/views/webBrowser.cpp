#include "webBrowser.h"
#include <QDebug>

webBrowser::webBrowser(QWidget* parent):QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.actionGo_To_Previous_Page,SIGNAL(triggered()),this,SLOT(goBack()));
    connect(ui.actionGo_To_Next_Page,SIGNAL(triggered()),this,SLOT(goForward()));
    connect(ui.actionReload_Page,SIGNAL(triggered()),this, SLOT(reload()));
    connect(ui.webView,SIGNAL(loadFinished(bool)),this,SLOT(loadFinished(bool)));
    ui.webView->installEventFilter(this);
    ui.webView->load(QUrl("http://google.com"));

}

webBrowser::~webBrowser()
{

}

void webBrowser::goBack()
{
    ui.webView->back();
}

void webBrowser::goForward()
{
    ui.webView->forward();
}

void webBrowser::reload()
{
    ui.webView->reload();
}

void webBrowser::loadFinished(bool isFinished)
{
    if(isFinished)
    {
            ui.webView->show();
            qDebug() << "I WAS HERE";
    }
}

void webBrowser::navigateToUrl(QString url)
{
    ui.webView->load(QUrl(url));
    qDebug() << url;
}

bool webBrowser::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type()==QMouseEvent::MouseButtonPress)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        if(mouseEvent->button() == Qt::XButton1)
        {
            goBack();
            return true;
        }
        else if (mouseEvent->button()== Qt::XButton2)
        {
            goForward();
            return true;
        }
    }
    return false;
}
