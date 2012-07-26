#include "mangainfoservice.h"

MangaInfoService::MangaInfoService(QSqlDatabase *db, QObject *parent) :
    QObject(parent)
{
    this->db=db;
}
