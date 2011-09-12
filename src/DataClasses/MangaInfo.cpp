#include "MangaInfo.h"

MangaInfo::MangaInfo() {
	//ctor
}

MangaInfo::MangaInfo(unsigned int mangaId, wxString mangaTitle,
		wxString mangaDescription, wxDateTime mangaPublicationDate,
		wxString mangaPublicationStatus, unsigned int mangaPublisherId,
		wxMemoryBuffer mangaCover) {
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
	this->mangaId = '\0';
	this->mangaTitle = '\0';
	this->mangaDescription = '\0';
	this->mangaPublicationDate = '\0';
	this->mangaPublicationStatus = '\0';
	this->mangaPublisherId = '\0';
	this->mangaCover = '\0';
}

MangaInfo::MangaInfo(Manga man) {
	this->mangaId = man.id;
	this->mangaTitle = man.title;
	this->mangaDescription = man.description;
	this->mangaPublicationDate = man.year;
	this->mangaPublicationStatus = man.status;
	this->mangaPublisherId = man.pId;
	this->mangaCover = man.image;
}

