#include "XmlDataParser.h"

XmlDataParser::XmlDataParser()
{
	//default constructor
}

void XmlDataParser::parseData(QString fileName, DbWrapper *db)
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

			}
			currentTag = xmlStreamReader.name().toString();
		}
		else if (xmlStreamReader.isEndElement())
		{
			if(xmlStreamReader.name()=="manga")
			{

			}
		}
		else if (xmlStreamReader.isCharacters() && !xmlStreamReader.isWhitespace())
		{

		}

	}
	if(xmlStreamReader.error() && xmlStreamReader.error()!= QXmlStreamReader::PrematureEndOfDocumentError)
	{
		qWarning() << "XML ERROR:" << xmlStreamReader.lineNumber() << ": " << xmlStreamReader.errorString();
	}
}