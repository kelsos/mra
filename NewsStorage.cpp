#include "NewsStorage.h"

NewsStorage::NewsStorage()
{
  //ctor
}
NewsStorage::NewsStorage(unsigned int newsItemId, wxString newsItemTitle, wxString newsItemHyperLink, wxString newsItemDescription, wxDateTime newsItemPublicationDate, wxDateTime newsItemAquisitionDate)
{
  this->newsItemId=newsItemId;
  this->newsItemTitle=newsItemTitle;
  this->newsItemHyperLink=newsItemHyperLink;
  this->newsItemDescription=newsItemDescription;
  this->newsItemPublicationDate=newsItemPublicationDate;
  this->newsItemAquisitionDate=newsItemAquisitionDate;
}

NewsStorage::~NewsStorage()
{
  //dtor
}
