#ifndef GENRESINFOEDITOR_H
#define GENRESINFOEDITOR_H

#include <QDialog>

namespace Ui
{
class genresInfoEditor;
}

class genresInfoEditor : public QDialog
{
    Q_OBJECT

public:
    explicit genresInfoEditor(QWidget *parent = 0);
    ~genresInfoEditor();

private:
    Ui::genresInfoEditor *ui;
};

#endif // GENRESINFOEDITOR_H
