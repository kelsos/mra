#ifndef RSSFETCHER_H
#define RSSFETCHER_H
#include <QtNetwork>
#include <QApplication>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QUrl>

class RssFetcher : public QObject
{
	Q_OBJECT
public:
	RssFetcher();
public slots:
	void fetch(const QUrl &url);
	void finished(QNetworkReply *reply);
	void readyRead();
	void metaDataChanged();
	void error(QNetworkReply::NetworkError);
protected:
private:
	void parseXml();
	void get(const QUrl &url);

	QXmlStreamReader xmlStreamReader;
	QString channelName;
	QString currentTag;
	QString linkString;
	QString titleString;
	QDateTime timeAquired;
	QDateTime timePublished;

	QNetworkAccessManager manager;
	QNetworkReply *currentReply;

};

#endif //RSSFETCHER_H