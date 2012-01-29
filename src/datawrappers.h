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

signals:

public slots:

private:
    QSqlDatabase database;

};

#endif // DATAWRAPPERS_H
