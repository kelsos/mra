#include "XmlReadingListParser.h"

XmlReadingListParser::XmlReadingListParser()
{
	//default constructor
}

void XmlReadingListParser::parseReadingList(QString fileName, DbWrapper *db)
{
	QFile *file = new QFile(fileName);
	file->open(QIODevice::ReadOnly);
	xmlStreamReader.setDevice(file);

	while(!xmlStreamReader.atEnd())
	{
		xmlStreamReader.readNext();
		if (xmlStreamReader.isStartElement())
		{
			if(xmlStreamReader.name()=="manga")
			{
				/*readItem.clear();*/
			}
			currentTag = xmlStreamReader.name().toString();
		}
		else if (xmlStreamReader.isEndElement())
		{
			if(xmlStreamReader.name()=="manga")
			{
				qDebug() << readItem.getMangaTitle();
				db->insertReadItem(&readItem);
				readItem.clear();
			}
		}
		else if (xmlStreamReader.isCharacters() && !xmlStreamReader.isWhitespace())
		{
			if(currentTag=="Title")
				readItem.setMangaTitle(xmlStreamReader.text().toString());
			else if(currentTag=="startingChapter")
				readItem.setStartingChapter(xmlStreamReader.text().toString().toUInt());
			else if (currentTag=="currentChapter")
				readItem.setCurrentChapter(xmlStreamReader.text().toString().toUInt());
			else if (currentTag=="dateRead")
				readItem.setLastRead(QDateTime::fromString(xmlStreamReader.text().toString(),Qt::ISODate));
			else if (currentTag=="onlineURL")
				readItem.setOnlineUrl(xmlStreamReader.text().toString());
			else if (currentTag=="finishedReading")
				readItem.setReadFinished(QString::compare(xmlStreamReader.text().toString(),"true",Qt::CaseInsensitive)?true:false);
			else if(currentTag=="mangaNote")
				readItem.setMangaNote(xmlStreamReader.text().toString());
		}
		
	}
	if(xmlStreamReader.error() && xmlStreamReader.error()!= QXmlStreamReader::PrematureEndOfDocumentError)
	{
		qWarning() << "XML ERROR:" << xmlStreamReader.lineNumber() << ": " << xmlStreamReader.errorString();
	}
}