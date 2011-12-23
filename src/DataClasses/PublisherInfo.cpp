#include "PublisherInfo.h"

PublisherInfo::PublisherInfo() {
	//ctor
}

PublisherInfo::PublisherInfo(unsigned int publisherId, QString publisherName,
		QString publisherCountry, QString publisherWebsite,
		QString publisherNote) {
	this->publisherId = publisherId;
	this->publisherName = publisherName;
	this->publisherCountry = publisherCountry;
	this->publisherWebsite = publisherWebsite;
	this->publisherNote = publisherNote;
}

PublisherInfo::~PublisherInfo() {
	//dtor
}

void PublisherInfo::clear()
{
	this->publisherId = 0;
	this->publisherName = "";
	this->publisherCountry = "";
	this->publisherWebsite = "";
	this->publisherNote = "";
}
