#include "readinglistdatacontroller.h"
#include <QDebug>

ReadingListDataController::ReadingListDataController(QSqlDatabase *database, QObject *parent) :
    QObject(parent)
{
    this->database=database;
}

MangaSqlQueryModel *ReadingListDataController::getUserReadingList(bool displayFinished)
{
    try
    {
        if(!database->isOpen())
            database->open();

        MangaSqlQueryModel *model = new MangaSqlQueryModel;
        QString query;
        QString readIsFinished = displayFinished ? "true" : "false";
        query = "SELECT mi.manga_title, rl.read_starting_chapter, rl.read_current_chapter, rl.read_last_time "
                "FROM manga_info mi, reading_list rl "
                "WHERE mi.manga_id = rl.manga_id AND rl.read_is_finished = '" + readIsFinished  + "'";

        model->setQuery(query,*database);

        int i = 0;
        model->setHeaderData(i++,Qt::Horizontal,"Manga Title");
        model->setHeaderData(i++,Qt::Horizontal,"Starting\nChapter");
        model->setHeaderData(i++,Qt::Horizontal,"Current\nChapter");
        model->setHeaderData(i++,Qt::Horizontal,"Last\nRead");
        if(displayFinished)
            model->setHeaderData(i++,Qt::Horizontal,"Finished\nReading?");
        return model;
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}


QPixmap ReadingListDataController::getMangaCover(QString mangaTitle)
{
    try
    {
        if(!database->isOpen())
            database->open();

        QSqlQuery query;
        query.prepare("SELECT manga_cover FROM manga_info WHERE manga_title = ?");
        query.bindValue(0,mangaTitle);
        query.exec();
        QByteArray ba;
        while (query.next())
            ba = query.value(0).toByteArray();
        QPixmap pix;
        if(ba.isEmpty()||ba.isNull())
            return pix;
        pix.loadFromData(ba,"PNG");
        if (pix.width()<160)
            pix = pix.scaled(QSize(160,(pix.height())*160/pix.width()),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
        if (pix.height()<230)
            pix = pix.scaled(QSize((pix.width()*230)/pix.height(),230),Qt::KeepAspectRatioByExpanding,Qt::SmoothTransformation);
        return pix;
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

QString ReadingListDataController::getMangaDescription(QString mangaTitle)
{
    try
    {
        if(!database->isOpen())
            database->open();
        QSqlQuery query;
        QString mangaDescription;
        query.prepare("SELECT manga_description FROM manga_info WHERE manga_title = ?");
        query.bindValue(0,mangaTitle);
        query.exec();
        while(query.next())
            mangaDescription = query.value(0).toString();
        return mangaDescription;
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}

QString ReadingListDataController::getMangaNote(QString mangaTitle)
{
    try
    {
        if(!database->isOpen())
            database->open();
        QSqlQuery query;
        QString mangaNote;
        query.prepare("SELECT read_note FROM reading_list WHERE manga_title = ?");
        query.bindValue(0,mangaTitle);
        query.exec();
        while(query.next())
            mangaNote=query.value(0).toString();
        return mangaNote;
    }
    catch (std::exception& e)
    {
        qDebug(e.what());
    }
}

QString ReadingListDataController::getMangaUrl(QString mangaTitle)
{
    try
    {
        if(!database->isOpen())
            database->open();
        QSqlQuery query;
        QString mangaUrl;
        query.prepare("SELECT RL.READ_ONLINE_URL FROM READING_LIST RL, MANGA_INFO MI WHERE MI.MANGA_TITLE = ? "
                      "AND RL.manga_id = MI.manga_id");
        query.bindValue(0,mangaTitle);
        query.exec();
        while(query.next())
        {
            mangaUrl = query.value(0).toString();
        }
        return mangaUrl;
    }
    catch(std::exception& e)
    {
        qDebug(e.what());
    }
}
