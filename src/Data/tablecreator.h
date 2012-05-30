#ifndef TABLECREATOR_H
#define TABLECREATOR_H

#include <QObject>

class tablecreator : public QObject
{
    Q_OBJECT
public:
    explicit tablecreator(QObject *parent = 0);
    
private:
    void createUsersTable();
    void createMangaInfoTable();
    void createReadingListTable();
    void createOnlineReaderTable();
    void createPublisherInfoTable();
    void createMangaGenresTable();
    void createGenreInfoTable();
    void createAuthorInfoTable();
    void createMangaAuthorsTable();
    void createNewsStorageTable();
    void createNewsSubscriptionTable();

signals:
    
public slots:
    void createTables();
    
};

#endif // TABLECREATOR_H
