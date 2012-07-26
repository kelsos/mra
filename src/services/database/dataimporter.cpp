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
        query.prepare("INSERT INTO reading_list (manga_id, user_id, read_starting_chapter, read_current_chapter, read_is_finished, read_last_time, read_note) VALUES "
                      "((SELECT manga_id FROM manga_info WHERE manga_title = ?), ?, ?, ?, ?, ?, ?)");

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
        query.prepare("INSERT INTO manga_info (manga_id, manga_title, manga_description, manga_publication_year, manga_publication_status, manga_publisher_id, manga_cover) VALUES (?, ?, ?, ?, ?, ?, ?)");

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
        query.prepare("INSERT INTO author_info (author_id, author_name, author_nationality, author_birthday, author_website) VALUES (?, ?, ?, ?, ?)");

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
        query.prepare("INSERT INTO genre_info (genre_id, genre_info) VALUES (?, ?)");

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
        query.prepare("INSERT INTO publisher_info (publisher_id, publisher_name, publisher_country, "
                      "publisher_website, publisher_note) values (?, ?, ?, ?, ?)");

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
        query.prepare("INSERT INTO news_storage (newsitem_id, newsitem_title, newsitem_hyperlink, "
                      "newsitem_description, newsitem_publication_date, newsitem_aquisition_date ) VALUES "
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
        query.prepare("INSERT INTO news_subscriptions (subscription_id, subscription_url, subcription_channel_name) "
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
        query.prepare("INSERT INTO manga_authors (manga_id, author_id) VALUES (?, ?)");

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
        query.prepare("INSERT INTO manga_genres (manga_id, genre_id) VALUES (?, ?)");

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


