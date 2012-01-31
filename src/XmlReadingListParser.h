#ifndef XMLREADINGLISTPARSER_H
#define XMLREADINGLISTPARSER_H
#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include <QDebug>
#include "DataClasses/ReadItem.h"
#include "Data/databasemanager.h"

class XmlReadingListParser
{
public:
    XmlReadingListParser();
    void parseReadingList(QString fileName);
protected:
private:
    QXmlStreamReader xmlStreamReader;
    QString currentTag;
    ReadItem readItem;
};

#endif