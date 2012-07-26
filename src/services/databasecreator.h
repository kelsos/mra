#ifndef DATABASECREATOR_H
#define DATABASECREATOR_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlDatabase>

class DatabaseCreator : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseCreator(QSqlDatabase *database, QObject *parent = 0);
    void initializeDatabaseTables();
private:
    void createAuthorInfoTable();
    void createGenreInfoTable();
    void createPublisherInfoTable();
    void createMangaInfoTable();
    void createNewsStorageTable();
    void createNewsSubscriptionsTable();
    void createMangaAuthorsTable();
    void createMangaGenresTable();
    void createReadingListTable();
    void createUserTable();
    void createOnlineReaderList();


    QSqlDatabase *database;

signals:
    
public slots:
    
};

#endif // DATABASECREATOR_H
