#include "AuthorInfo.h"

AuthorInfo::AuthorInfo()
{
  //ctor
}

AuthorInfo::AuthorInfo(unsigned int authorId, wxString authorName, wxString authorNationality, wxDateTime authorBirthday, wxString authorWebsite)
{
  this->authorId = authorId;
  this->authorName = authorName;
  this->authorNationality = authorNationality;
  this->authorBirthday = authorBirthday;
  this->authorWebsite = authorWebsite;
}

AuthorInfo::~AuthorInfo()
{
  //dtor
}
