#ifndef MANGAINFOSERVICE_H
#define MANGAINFOSERVICE_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QStringList>
#include <QVariant>
#include <QDateTime>

#include "dataservicebase.h"

class MangaInfoService : public DataServiceBase
{
public:
    explicit MangaInfoService(QSqlDatabase *db, QObject *parent = 0);
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
	void addGenreForManga(QString mangaTitle, QString genreName);
	void removeGenreFromManga(QString mangaTitle, QString genreName);
	void addPublisherForManga(QString mangaTitle, QString publisherName);
	void removePublisherFromManga(QString mangaTitle);
	void updateCoverForManga(QString mangaTitle, QByteArray cover);
	void insertNewMangaInfo(QString title, QString description, QString publisher, QDateTime publicationDate, QString publicationStatus, QByteArray cover);
	int getMangaCount();
    void deleteManga(QString mangaTitle);
    void updateNewMangaInfo(QString oldTitle, QString newTitle, QString description, QDateTime publicationDate, QString publicationStatus);
    
};

#endif // MANGAINFOSERVICE_H
