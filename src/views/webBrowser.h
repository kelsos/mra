#ifndef WEBBROWSER_H
#define WEBBROWSER_H

#include <QtWidgets/QMainWindow>
#include <QMouseEvent>
#include "ui_forms_web_browser.h"

class webBrowser : public QMainWindow
{
    Q_OBJECT

public:
    webBrowser(QWidget* parent=0);
    ~webBrowser();

private:
    Ui::WebBrowser ui;
    bool eventFilter(QObject *obj, QEvent *event);

public slots:
    void navigateToUrl(QString url);

private slots:
    void goBack();
    void goForward();
    void reload();
    void loadFinished(bool isFinished);

signals:
};

#endif
