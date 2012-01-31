#include "readinglistdatacontroller.h"

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
        if(displayFinished)
        {
            query = "SELECT MI.MANGA_TITLE, RL.READ_STARTING_CHAPTER, RL.READ_CURRENT_CHAPTER, RL.READ_ONLINE_URL, RL.READ_LAST_TIME, RL.READ_IS_FINISHED "
                    "FROM MANGA_INFO MI, READING_LIST RL "
                    "WHERE MI.MANGA_ID = RL.MANGA_ID";
        }
        else
        {
            query = "SELECT MI.MANGA_TITLE, RL.READ_STARTING_CHAPTER, RL.READ_CURRENT_CHAPTER, RL.READ_ONLINE_URL, RL.READ_LAST_TIME "
                    "FROM MANGA_INFO MI, READING_LIST RL "
                    "WHERE MI.MANGA_ID = RL.MANGA_ID AND RL.READ_IS_FINISHED = 'false'";
        }
        model->setQuery(query,*database);

        int i = 0;
        model->setHeaderData(i++,Qt::Horizontal,"Manga Title");
        model->setHeaderData(i++,Qt::Horizontal,"Starting\nChapter");
        model->setHeaderData(i++,Qt::Horizontal,"Current\nChapter");
        model->setHeaderData(i++,Qt::Horizontal,"Online URL");
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
        query.prepare("SELECT MANGA_COVER FROM MANGA_INFO WHERE MANGA_TITLE = ?");
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
        query.prepare("SELECT MANGA_DESCRIPTION FROM MANGA_INFO WHERE MANGA_TITLE = ?");
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
        query.prepare("SELECT READ_NOTE FROM READING_LIST WHERE MANGA_TITLE = ?");
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
        QString mangaDescription;
        query.prepare("SELECT READ_ONLINE_URL FROM READING_LIST WHERE MANGA_TITLE = ?");
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
