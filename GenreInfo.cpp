#include "GenreInfo.h"

GenreInfo::GenreInfo()
{
  //ctor
}

GenreInfo::GenreInfo(unsigned int genreId, wxString genreName)
{
	this->genreId=genreId;
	this->genreName=genreName;
}

GenreInfo::~GenreInfo()
{
  //dtor
}
