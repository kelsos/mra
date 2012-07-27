#ifndef RSSFETCHER_H
#define RSSFETCHER_H

#include <QtNetwork>
#include <QApplication>
#include <QXmlStreamReader>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QBuffer>
#include <QUrl>
#include <QDateTime>

#include "../../utilities/datetime.h"

class RssFetcher : public QObject
{
    Q_OBJECT
public:
    RssFetcher(QObject *parent = 0);
public slots:
    void fetch(QString urlString);
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
    QString descriptionString;
    QString pubDateString;
    QDateTime timeAquired;
    QDateTime timePublished;

    QNetworkAccessManager manager;
    QNetworkReply *currentReply;
};

#endif //RSSFETCHER_H
