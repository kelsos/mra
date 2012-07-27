#include "mangagenres.h"

MangaGenres::MangaGenres() {
	this->mangaId = 0;
	this->genreId = 0;

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

