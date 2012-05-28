#ifndef DATABASEEDITOROPERATOR_H
#define DATABASEEDITOROPERATOR_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QVariant>
#include <QDateTime>
#include <QDebug>
#include <QStringList>
#include "DataClasses/mangainfo.h"

class DatabaseEditorOperator : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseEditorOperator(QSqlDatabase *database, QObject *parent = 0);
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
	int getAuthorCount();
	int getPublisherCount();
	void deleteManga(QString mangaTitle);
	void updateNewMangaInfo(QString oldTitle, QString newTitle, QString description, QDateTime publicationDate, QString publicationStatus);
	QStringList getAllAuthorNames();
	QStringList getAllPublisherNames();
	QString getAuthorCountryOfBirth(QString authorName);
	QDateTime getAuthorBirthday(QString authorName);
	QString getAuthorWebsite(QString authorName);
	QString getPublisherCountry(QString publisher);
	QString getPublisherWebsite(QString publisher);
	QString getPublisherNote(QString publisher);

private:
	QSqlDatabase *database;
	QString getStringFromDatabase(QString queryString, QString parameter);
	QStringList getStringListFromDatabase(QString queryString, QString parameter);

signals:
    
public slots:
    
};

#endif // DATABASEEDITOROPERATOR_H
