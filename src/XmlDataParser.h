#ifndef XMLDATAPARSER_H
#define XMLDATAPARSER_H

#include <QApplication>
#include <QDateTime>
#include <QXmlStreamReader>
#include <QFile>
#include "DbWrapper.h"
//Data classes included.
#include "AuthorInfo.h"
#include "GenreInfo.h"
#include "MangaAuthors.h"
#include "MangaGenres.h"
#include "MangaInfo.h"
#include "PublisherInfo.h"

class XmlDataParser
{
public:
	XmlDataParser();
	void parseData(QString fileName, DbWrapper *db);
private:
	QXmlStreamReader xmlStreamReader;
	QString currentTag;
	QString currentCategory;
};
#endif