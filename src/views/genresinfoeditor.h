#ifndef GENRESINFOEDITOR_H
#define GENRESINFOEDITOR_H

#include <QDialog>

namespace Ui
{
class GenresInfoEditorForm;
}

class GenresInfoEditor : public QDialog
{
    Q_OBJECT

public:
    explicit GenresInfoEditor(QWidget *parent = 0);
    ~GenresInfoEditor();

private:
    Ui::GenresInfoEditorForm *ui;
};

#endif // GENRESINFOEDITOR_H
