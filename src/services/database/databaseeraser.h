#ifndef DATABASEERASER_H
#define DATABASEERASER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>

class DatabaseEraser : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseEraser(QSqlDatabase *database, QObject *parent = 0);
    void clearDatabase();
    void clearReadingList();
	void clearStoredNews();
	void clearSubcriptions();

private:
    void truncateAuthorInfoTable();
    void truncateGenreInfoTable();
    void truncatePublisherInfoTable();
    void truncateMangaInfoTable();
    void truncateMangaAuthorsTable();
    void truncateMangaGenresTable();
	void executeNonQuery(QString queryString);

    QSqlDatabase *database;
signals:
    
public slots:
    
};

#endif // DATABASEERASER_H
