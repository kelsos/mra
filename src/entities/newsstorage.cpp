#include "newsstorage.h"

NewsStorage::NewsStorage()
{
    //ctor
}
NewsStorage::NewsStorage(unsigned int newsItemId, QString newsItemTitle,
                         QString newsItemHyperLink, QString newsItemDescription,
                         QDateTime newsItemPublicationDate, QDateTime newsItemAquisitionDate)
{
    this->newsItemId = newsItemId;
    this->newsItemTitle = newsItemTitle;
    this->newsItemHyperLink = newsItemHyperLink;
    this->newsItemDescription = newsItemDescription;
    this->newsItemPublicationDate = newsItemPublicationDate;
    this->newsItemAquisitionDate = newsItemAquisitionDate;
}

NewsStorage::~NewsStorage()
{
    //dtor
}
void NewsStorage::clear()
{
    this->newsItemId = 0;
    this->newsItemTitle = "";
    this->newsItemHyperLink = "";
    this->newsItemDescription = "";
    this->newsItemPublicationDate = QDateTime::currentDateTime();
    this->newsItemAquisitionDate = QDateTime::currentDateTime();
}
