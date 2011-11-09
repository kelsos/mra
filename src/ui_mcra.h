#ifndef UI_MCRA_H
#define UI_MCRA_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mcraClass
{
public:
    QAction *actionOpen_To_Browser;
    QAction *actionJust_Read_It;
    QAction *actionRefresh_View;
    QWidget *centralwidget;
    QTableView *tableView;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox_3;
    QMenuBar *menubar;
    QToolBar *toolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *mcraClass)
    {
        if (mcraClass->objectName().isEmpty())
            mcraClass->setObjectName(QString::fromUtf8("mcraClass"));
        mcraClass->resize(881, 563);
        actionOpen_To_Browser = new QAction(mcraClass);
        actionOpen_To_Browser->setObjectName(QString::fromUtf8("actionOpen_To_Browser"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("resources/icons/globe.png"), QSize(), QIcon::Normal, QIcon::On);
        actionOpen_To_Browser->setIcon(icon);
        actionJust_Read_It = new QAction(mcraClass);
        actionJust_Read_It->setObjectName(QString::fromUtf8("actionJust_Read_It"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("resources/icons/calendar.png"), QSize(), QIcon::Normal, QIcon::On);
        actionJust_Read_It->setIcon(icon1);
        actionRefresh_View = new QAction(mcraClass);
        actionRefresh_View->setObjectName(QString::fromUtf8("actionRefresh_View"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("resources/icons/reload.png"), QSize(), QIcon::Normal, QIcon::On);
        actionRefresh_View->setIcon(icon2);
        centralwidget = new QWidget(mcraClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(150, 10, 721, 331));
        tableView->setSortingEnabled(true);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 350, 211, 131));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(230, 350, 641, 131));
        groupBox_2->setFlat(false);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 131, 192));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 210, 131, 131));
        mcraClass->setCentralWidget(centralwidget);
        menubar = new QMenuBar(mcraClass);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 881, 21));
        mcraClass->setMenuBar(menubar);
        toolBar = new QToolBar(mcraClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        mcraClass->addToolBar(Qt::TopToolBarArea, toolBar);
        statusBar = new QStatusBar(mcraClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        mcraClass->setStatusBar(statusBar);

        toolBar->addAction(actionOpen_To_Browser);
        toolBar->addAction(actionJust_Read_It);
        toolBar->addAction(actionRefresh_View);

        retranslateUi(mcraClass);

        QMetaObject::connectSlotsByName(mcraClass);
    } // setupUi

    void retranslateUi(QMainWindow *mcraClass)
    {
        mcraClass->setWindowTitle(QApplication::translate("mcraClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionOpen_To_Browser->setText(QApplication::translate("mcraClass", "Open To Browser", 0, QApplication::UnicodeUTF8));
        actionJust_Read_It->setText(QApplication::translate("mcraClass", "Just Read It", 0, QApplication::UnicodeUTF8));
        actionRefresh_View->setText(QApplication::translate("mcraClass", "Refresh View", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("mcraClass", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("mcraClass", "GroupBox", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("mcraClass", "GroupBox", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("mcraClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class mcraClass: public Ui_mcraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MCRA_H
