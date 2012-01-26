#ifndef DATABASEEDITOR_H
#define DATABASEEDITOR_H

#include <QDialog>

namespace Ui {
  class DatabaseEditor;
}

class DatabaseEditor : public QDialog
{
  Q_OBJECT
  
public:
  explicit DatabaseEditor(QWidget *parent = 0);
  ~DatabaseEditor();
  
private:
  Ui::DatabaseEditor *ui;
};

#endif // DATABASEEDITOR_H
