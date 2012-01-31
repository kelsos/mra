#include "dataimporter.h"

DataImporter::DataImporter(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}

void DataImporter::insertReadItem(ReadItem* readItem)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO READING_LIST (MANGA_ID, READ_STARTING_CHAPTER, READ_CURRENT_CHAPTER, "
                      "READ_ONLINE_URL, READ_IS_FINISHED, READ_LAST_TIME, READ_NOTE) VALUES "
					  "((SELECT MANGA_ID FROM MANGA_INFO WHERE MANGA_TITLE = ?), ?, ?, ?, ?, ?, ?)");

        int i = 0;
        query.bindValue(i++, readItem->getMangaTitle());
        query.bindValue(i++, (int) readItem->getStartingChapter());
        query.bindValue(i++, (int) readItem->getCurrentChapter());
        query.bindValue(i++, readItem->getOnlineUrl());
        query.bindValue(i++, readItem->getReadFinished());
        query.bindValue(i++, readItem->getLastRead());
        query.bindValue(i++, readItem->getMangaNote());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DataImporter::insertMangaData(MangaInfo* manga)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO MANGA_INFO (MANGA_ID, MANGA_TITLE, MANGA_DESCRIPTION, MANGA_PUBLICATION_DATE, "
                      "MANGA_PUBLICATION_STATUS, MANGA_PUBLISHER_ID, MANGA_COVER) VALUES (?, ?, ?, ?, ?, ?, ?)");

        int i = 0;
        query.bindValue(i++, (int) manga->getMangaId());
        query.bindValue(i++, manga->getMangaTitle());
        query.bindValue(i++, manga->getMangaDescription());
        query.bindValue(i++, manga->getMangaPublicationDate());
        query.bindValue(i++, manga->getMangaPublicationStatus());
        query.bindValue(i++, (int) manga->getMangaPublisherId());
        query.bindValue(i++, manga->getMangaCover());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DataImporter::insertAuthorData(AuthorInfo* author)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO AUTHOR_INFO (AUTHOR_ID, AUTHOR_NAME, AUTHOR_NATIONALITY, AUTHOR_BIRTHDAY, "
                      "AUTHOR_WEBSITE) VALUES (?, ?, ?, ?, ?)");

        int i = 0;
        query.bindValue(i++, (int) author->getAuthorId());
        query.bindValue(i++, author->getAuthorName());
        query.bindValue(i++, author->getAuthorNationality());
        query.bindValue(i++, author->getAuthorBirthday());
        query.bindValue(i++, author->getAuthorWebsite());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}
void DataImporter::insertGenreData(GenreInfo* genre)
{
    try
    {
        if(!database->isOpen())
            database->open();
        QSqlQuery query;
        query.prepare("INSERT INTO GENRE_INFO (GENRE_ID, GENRE_NAME) VALUES (?, ?)");

        int i = 0;
        query.bindValue(i++, (int) genre->getGenreId());
        query.bindValue(i++, genre->getGenreName());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}
void DataImporter::insertPublisherData(PublisherInfo* publisher)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO PUBLISHER_INFO (PUBLISHER_ID, PUBLISHER_NAME, PUBLISHER_COUNTRY, "
                      "PUBLISHER_WEBSITE, PUBLISHER_NOTE) values (?, ?, ?, ?, ?)");

        int i = 0;
        query.bindValue(i++, (int) publisher->getPublisherId());
        query.bindValue(i++, publisher->getPublisherName());
        query.bindValue(i++, publisher->getPublisherCountry());
        query.bindValue(i++, publisher->getPublisherWebsite());
        query.bindValue(i++, publisher->getPublisherNote());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DataImporter::insertNewsItem(NewsStorage* newsItem)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO NEWS_STORAGE (NEWSITEM_ID, NEWSITEM_TITLE, NEWSITEM_HYPERLINK, "
                      "NEWSITEM_DESCRIPTION, NEWSITEM_PUBLICATION_DATE, NEWSITEM_AQUISITION_DATE ) VALUES "
                      "(?, ?, ?, ?, ?, ?)");

        int i = 0;
        query.bindValue(i++, (int) newsItem->getNewsItemId());
        query.bindValue(i++, newsItem->getNewsItemTitle());
        query.bindValue(i++, newsItem->getNewsItemHyperLink());
        query.bindValue(i++, newsItem->getNewsItemDescription());
        query.bindValue(i++, newsItem->getNewsItemPublicationDate());
        query.bindValue(i++, newsItem->getNewsItemAquisitionDate());
        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}
void DataImporter::insertNewsSubscription(NewsSubscriptions* subscription)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO NEWS_SUBSCRIPTIONS (SUBSCRIPTION_ID, SUBSCRIPTION_URL, SUBSCRIPTION_CHANNEL_NAME) "
                      "VALUES (?, ?, ?)");

        int i = 0;
        query.bindValue(i++, (int) subscription->getSubscriptionId());
        query.bindValue(i++, subscription->getSubscriptionUrl());
        query.bindValue(i++, subscription->getSubscriptionChannelName());
        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}
void DataImporter::insertMangaAuthor(MangaAuthors* maAuth)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO MANGA_AUTHORS (MANGA_ID, AUTHOR_ID) VALUES (?, ?)");

        int i = 0;
        query.bindValue(i++, (int) maAuth->getMangaId());
        query.bindValue(i++, (int) maAuth->getAuthorId());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

void DataImporter::insertMangaGenre(MangaGenres* maGen)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("INSERT INTO MANGA_GENRES (MANGA_ID, GENRE_ID) VALUES (?, ?)");

        int i = 0;
        query.bindValue(i++, (int) maGen->getMangaId());
        query.bindValue(i++, (int) maGen->getGenreId());

        query.exec();
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}


