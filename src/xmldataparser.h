#ifndef XMLDATAPARSER_H
#define XMLDATAPARSER_H

#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include "Data/databasemanager.h"
//Data classes included.
#include "DataClasses/authorinfo.h"
#include "DataClasses/genreinfo.h"
#include "DataClasses/mangaauthors.h"
#include "DataClasses/mangagenres.h"
#include "DataClasses/mangainfo.h"
#include "DataClasses/publisherinfo.h"

class XmlDataParser
{
public:
    XmlDataParser();
    void parseData(QString fileName);
private:
    QXmlStreamReader xmlStreamReader;
    QString currentTag;
    QString currentCategory;
};
#endif
