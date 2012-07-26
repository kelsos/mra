#ifndef READINGLISTDATACONTROLLER_H
#define READINGLISTDATACONTROLLER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPixmap>
#include "mangasqlquerymodel.h"

class ReadingListDataController : public QObject
{
    Q_OBJECT
public:
    explicit ReadingListDataController(QSqlDatabase *database, QObject *parent = 0);
    /** Gets the User's reading List
     *
     * @return
     */
    MangaSqlQueryModel* getUserReadingList(bool displayFinished);
    QPixmap getMangaCover(QString mangaTitle);
    QString getMangaDescription(QString mangaTitle);
    QString getMangaNote(QString mangaTitle);
    QString getMangaUrl(QString mangaTitle);

private:
    QSqlDatabase *database;

signals:
    
public slots:
    
};

#endif // READINGLISTDATACONTROLLER_H
