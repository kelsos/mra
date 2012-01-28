#ifndef DATAWRAPPERS_H
#define DATAWRAPPERS_H

#include <QObject>
#include <QVector>
#include <QDateTime>
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
	QStringList getGenresForManga(QString mangaTitle);
	QString getPublisherForManga(QString mangaTitle);
	QStringList getNonSelectedAuthorsForManga(QString mangaTitle);
	QStringList getNonSelectedGenresForManga(QString mangaTitle);
	QStringList getNonSelectedPublishersForManga(QString mangaTitle);
	QDateTime getPublicationDateForManga(QString mangaTitle);
	void addAuthorForManga(QString mangaTitle, QString authorName);
	void removeAuthorForManga(QString mangaTitle, QString authorName);

signals:
    
public slots:

private:
    QSqlDatabase database;
    
};

#endif // DATAWRAPPERS_H
