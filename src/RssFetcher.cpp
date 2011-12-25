#include "RssFetcher.h"

RssFetcher::RssFetcher()
{
	connect(&manager, SIGNAL(finished(QNetworkReply*)),this,SLOT(finished(QNetworkReply*)));
}

void RssFetcher::get(const QUrl &url)
{
	QNetworkRequest request(url);
	if (currentReply)
	{
		currentReply->disconnect(this);
		currentReply->deleteLater();
	}
	currentReply = manager.get(request);
	connect(currentReply, SIGNAL(readyRead()), this, SLOT(readyRead()));
	connect(currentReply, SIGNAL(metaDataChanged()), this, SLOT(metaDataChanged()));
	connect(currentReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(error(QNetworkReply::NetworkError)));

}

void RssFetcher::fetch(const QUrl &url)
{
	xmlStreamReader.clear();
	get(url);
}

void RssFetcher::metaDataChanged()
{
	QUrl redirectionTarget = currentReply->attribute(QNetworkRequest::RedirectionTargetAttribute).toUrl();
	if (redirectionTarget.isValid())
	{
		get(redirectionTarget);
	}
}

void RssFetcher::readyRead()
{
	int statusCode = currentReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
	if (statusCode >= 200 && statusCode < 300)
	{
		QByteArray data = currentReply->readAll();
		xmlStreamReader.addData(data);
		parseXml();
	}
}

void RssFetcher::finished(QNetworkReply *reply)
{
	Q_UNUSED(reply);
}

void RssFetcher::parseXml()
{
	while(!xmlStreamReader.atEnd())
	{
		xmlStreamReader.readNext();
		if (xmlStreamReader.isStartElement())
		{
			if(xmlStreamReader.name()=="item")
			{
				linkString = xmlStreamReader.attributes().value("rss:about").toString();
			}
			currentTag = xmlStreamReader.name().toString();
		}
		else if (xmlStreamReader.isEndElement())
		{
			if(xmlStreamReader.name()=="item")
			{
				//TODO: Dump to the database;
				titleString.clear();
				linkString.clear();
				//TODO: Initialize Dates.
			}
		}
		else if (xmlStreamReader.isCharacters() && !xmlStreamReader.isWhitespace())
		{
			if (currentTag=="title")
				titleString +=xmlStreamReader.text().toString();
			else if (currentTag=="link")
				linkString +=xmlStreamReader.text().toString();
			//TODO: Add publication date/decription parsing
		}
	}
	if (xmlStreamReader.error() && xmlStreamReader.error() !=QXmlStreamReader::PrematureEndOfDocumentError)
	{
		qWarning() << "XML ERROR:" << xmlStreamReader.lineNumber() << ": " << xmlStreamReader.errorString();
	}
}

void RssFetcher::error(QNetworkReply::NetworkError)
{
	qWarning("error retrieving RSS feed");
	currentReply->disconnect(this);
	currentReply->deleteLater();
	currentReply=0;
}