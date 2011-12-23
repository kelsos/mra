#include "MangaInfo.h"

MangaInfo::MangaInfo() {
	//ctor
}

MangaInfo::MangaInfo(unsigned int mangaId, QString mangaTitle,
		QString mangaDescription, QDateTime mangaPublicationDate,
		QString mangaPublicationStatus, unsigned int mangaPublisherId,
		QByteArray mangaCover) {
	this->mangaId = mangaId;
	this->mangaTitle = mangaTitle;
	this->mangaDescription = mangaDescription;
	this->mangaPublicationDate = mangaPublicationDate;
	this->mangaPublicationStatus = mangaPublicationStatus;
	this->mangaPublisherId = mangaPublisherId;
	this->mangaCover = mangaCover;
}

MangaInfo::~MangaInfo() {
	//dtor
}

void MangaInfo::clear() {
	this->mangaId = 0;
	this->mangaTitle = "";
	this->mangaDescription = "";
	this->mangaPublicationDate = QDateTime::fromString("01.01.190000:00:00","dd.MM.yyyyhh:mm:ss");
	this->mangaPublicationStatus = "";
	this->mangaPublisherId = 0;
	this->mangaCover = "";
}


