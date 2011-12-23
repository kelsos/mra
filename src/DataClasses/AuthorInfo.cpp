#include "AuthorInfo.h"

AuthorInfo::AuthorInfo() {
	//ctor
}

AuthorInfo::AuthorInfo(unsigned int authorId, QString authorName,
		QString authorNationality, QDateTime authorBirthday,
		QString authorWebsite) {
	this->authorId = authorId;
	this->authorName = authorName;
	this->authorNationality = authorNationality;
	this->authorBirthday = authorBirthday;
	this->authorWebsite = authorWebsite;
}

AuthorInfo::~AuthorInfo() {
	//dtor
}

void AuthorInfo::clear()
{
	this->authorId = 0;
	this->authorName = "";
	this->authorNationality = "";
	this->authorBirthday=QDateTime::fromString("01.01.190000:00:00","dd.MM.yyyyhh:mm:ss");
	this->authorWebsite = "";
}
