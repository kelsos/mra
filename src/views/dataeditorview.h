#ifndef DATAEDITORVIEW_H
#define DATAEDITORVIEW_H

#include <QWidget>
#include "ui_forms_database_editor.h"

namespace Ui {
    class dataeditorview;
}

class dataeditorview : public QWidget
{
    Q_OBJECT
    public:
    explicit dataeditorview(QWidget *parent = 0);
    
    signals:
    
    public slots:
    
};

#endif // DATAEDITORVIEW_H
