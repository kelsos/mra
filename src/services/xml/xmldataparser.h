#ifndef XMLDATAPARSER_H
#define XMLDATAPARSER_H

#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
//Data classes included.
#include "../../entities/authorinfo.h"
#include "../../entities/genreinfo.h"
#include "../../entities/mangaauthors.h"
#include "../../entities/mangagenres.h"
#include "../../entities/mangainfo.h"
#include "../../entities/publisherinfo.h"

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
