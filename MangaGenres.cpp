#include "MangaGenres.h"

MangaGenres::MangaGenres()
{
  //ctor
}

MangaGenres::MangaGenres(unsigned int mangaId, unsigned int genreId)
{
  this->mangaId = mangaId;
  this->genreId = genreId;
}

MangaGenres::~MangaGenres()
{
  //dtor
}
