#include "GenreInfo.h"

GenreInfo::GenreInfo() {
	//ctor
}

GenreInfo::GenreInfo(unsigned int genreId, QString genreName) {
	this->genreId = genreId;
	this->genreName = genreName;
}

GenreInfo::~GenreInfo() {
	//dtor
}
void GenreInfo::clear() {
	this->genreId = 0;
	this->genreName = "";
}
