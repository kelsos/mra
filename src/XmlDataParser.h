#ifndef XMLDATAPARSER_H
#define XMLDATAPARSER_H

#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include "DbWrapper.h"

class XmlDataParser
{
public:
	XmlDataParser();
	void parseData(QString fileName, DbWrapper *db);
private:
	QXmlStreamReader xmlStreamReader;
	QString currentTag;
};
#endif