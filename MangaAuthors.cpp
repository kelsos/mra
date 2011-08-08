#include "MangaAuthors.h"

MangaAuthors::MangaAuthors()
{
  //ctor
}

MangaAuthors::MangaAuthors(unsigned int mangaId, unsigned int authorId)
{
  this->mangaId=mangaId;
  this->authorId=authorId;
}

MangaAuthors::~MangaAuthors()
{
  //dtor
}
