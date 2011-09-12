#include "AuthorInfo.h"

AuthorInfo::AuthorInfo() {
	//ctor
}

AuthorInfo::AuthorInfo(unsigned int authorId, wxString authorName,
		wxString authorNationality, wxDateTime authorBirthday,
		wxString authorWebsite) {
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
	this->authorId = '\0';
	this->authorName = '\0';
	this->authorNationality = '\0';
	this->authorBirthday = '\0';
	this->authorWebsite = '\0';
}

AuthorInfo::AuthorInfo(Author auth)
{
	this->authorId = auth.id;
	this->authorName = auth.name;
	this->authorNationality = auth.country;
	this->authorBirthday = auth.birthday;
	this->authorWebsite = auth.website;
}
