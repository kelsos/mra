#ifndef DATABASETABLECREATOR_H
#define DATABASETABLECREATOR_H

#include <QObject>
#include <QSqlQuery>
#include <QSqlDatabase>

class DatabaseTableCreator : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseTableCreator(QSqlDatabase *database, QObject *parent = 0);
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

#endif // DATABASETABLECREATOR_H
