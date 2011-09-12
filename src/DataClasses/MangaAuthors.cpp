#include "MangaAuthors.h"

MangaAuthors::MangaAuthors() {
	//ctor
}

MangaAuthors::MangaAuthors(unsigned int mangaId, unsigned int authorId) {
	this->mangaId = mangaId;
	this->authorId = authorId;
}

MangaAuthors::~MangaAuthors() {
	//dtor
}

void MangaAuthors::clear() {
	this->mangaId = '\0';
	this->authorId = '\0';
}

MangaAuthors::MangaAuthors(MangaAuthor manAuth) {
	this->mangaId = manAuth.mId;
	this->authorId = manAuth.aId;
}
