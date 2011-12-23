#include "MangaGenres.h"

MangaGenres::MangaGenres() {
	//ctor
}

MangaGenres::MangaGenres(unsigned int mangaId, unsigned int genreId) {
	this->mangaId = mangaId;
	this->genreId = genreId;
}

MangaGenres::~MangaGenres() {
	//dtor
}

void MangaGenres::clear() {
	this->mangaId = 0;
	this->genreId = 0;
}

