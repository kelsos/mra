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
PublisherInfo::PublisherInfo(Publisher pub)
{
	this->publisherId = pub.id;
	this->publisherName = pub.name;
	this->publisherCountry = pub.country;
	this->publisherWebsite = pub.website;
	this->publisherNote = pub.note;
}

PublisherInfo::~PublisherInfo() {
	//dtor
}

void PublisherInfo::clear()
{
	this->publisherId = '\0';
	this->publisherName = '\0';
	this->publisherCountry = '\0';
	this->publisherWebsite = '\0';
	this->publisherNote = '\0';
}
