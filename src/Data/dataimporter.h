#ifndef DATAIMPORTER_H
#define DATAIMPORTER_H

#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVariant>
#include "DataClasses/authorinfo.h"
#include "DataClasses/genreinfo.h"
#include "DataClasses/publisherinfo.h"
#include "DataClasses/mangainfo.h"
#include "DataClasses/newsstorage.h"
#include "DataClasses/newssubscriptions.h"
#include "DataClasses/mangaauthors.h"
#include "DataClasses/mangagenres.h"
#include "DataClasses/readitem.h"
class DataImporter : public QObject
{
    Q_OBJECT
public:
    explicit DataImporter(QSqlDatabase* database,QObject *parent = 0);
    void insertAuthorData(AuthorInfo* author);
    /**Inserts an entry representing a Genre to the database.
     *
     * @param genre
     */
    void insertGenreData(GenreInfo* genre);
    /**Inserts an entry representing a Publisher to the database.
     *
     * @param publisher
     */
    void insertPublisherData(PublisherInfo* publisher);
    /**Inserts an entry representing a Manga to the database.
     *
     * @param manga
     */
    void insertMangaData(MangaInfo* manga);
    /**Inserts an entry representing a NewsItem to the database.
     *
     * @param newsItem
     */
    void insertNewsItem(NewsStorage* newsItem);
    /**Inserts an entry representing an Rss subscription to the database.
     *
     * @param subscription
     */
    void insertNewsSubscription(NewsSubscriptions* subscription);
    /**Inserts an entry representing a Manga Author to the database.
     *
     * @param maAuth
     */
    void insertMangaAuthor(MangaAuthors* maAuth);
    /**Inserts an entry representing a Manga Genre to the database.
     *
     * @param maGen
     */
    void insertMangaGenre(MangaGenres* maGen);
    /**Inserts an entry representing a Read Item to the database.
     *
     * @param readItem
     */
    void insertReadItem(ReadItem* readItem);

private:
    QSqlDatabase *database;

signals:
    
public slots:
    
};

#endif // DATAIMPORTER_H
