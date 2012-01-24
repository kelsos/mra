#ifndef XMLREADINGLISTPARSER_H
#define XMLREADINGLISTPARSER_H
#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include "DataClasses/ReadItem.h"
#include "DbWrapper.h"

class XmlReadingListParser
{
public:
	XmlReadingListParser();
	void parseReadingList(QString fileName, DbWrapper *db);
protected:
private:
	QXmlStreamReader xmlStreamReader;
	QString currentTag;
	ReadItem readItem;
};

#endif