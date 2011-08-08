#include "PublisherInfo.h"

PublisherInfo::PublisherInfo()
{
  //ctor
}

PublisherInfo::PublisherInfo(unsigned int publisherId, wxString publisherName, wxString publisherCountry, wxString publisherWebsite, wxString publisherNote)
{
  this->publisherId = publisherId;
  this->publisherName = publisherName;
  this->publisherCountry = publisherCountry;
  this->publisherWebsite = publisherWebsite;
  this->publisherNote = publisherNote;
}

PublisherInfo::~PublisherInfo()
{
  //dtor
}
