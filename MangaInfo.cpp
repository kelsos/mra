#include "MangaInfo.h"

MangaInfo::MangaInfo()
{
  //ctor
}

MangaInfo::MangaInfo(unsigned int mangaId, wxString mangaTitle, wxString mangaDescription, wxDateTime mangaPublicationDate, wxString mangaPublicationStatus, unsigned int mangaPublisherId)
{
  this->mangaId = mangaId;
  this->mangaTitle = mangaTitle;
  this->mangaDescription = mangaDescription;
  this->mangaPublicationDate = mangaPublicationDate;
  this->mangaPublicationStatus = mangaPublicationStatus;
  this->mangaPublisherId = mangaPublisherId;
}

MangaInfo::MangaInfo(unsigned int mangaId, wxString mangaTitle)
{
	this->mangaId=mangaId;
	this->mangaTitle=mangaTitle;
}

MangaInfo::~MangaInfo()
{
  //dtor
}
