#ifndef DATAWRAPPERS_H
#define DATAWRAPPERS_H

#include <QObject>
#include <QVector>
#include "MangaInfo.h"
#include "DbWrapper.h"

class DataWrapperS : public QObject
{
    Q_OBJECT
public:
    explicit DataWrapperS(QObject *parent = 0);
    QStringList getAllMangaInfoTitles();
	QString getMangaStatus(QString mangaTitle);
    QStringList getAuthorsForManga(QString mangaTitle);
signals:
    
public slots:

private:
    QSqlDatabase database;
    
};

#endif // DATAWRAPPERS_H
