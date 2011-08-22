#include "GenreInfo.h"

GenreInfo::GenreInfo() {
	//ctor
}

GenreInfo::GenreInfo(unsigned int genreId, wxString genreName) {
	this->genreId = genreId;
	this->genreName = genreName;
}

GenreInfo::~GenreInfo() {
	//dtor
}
void GenreInfo::clear() {
	this->genreId = '\0';
	this->genreName = '\0';
}

GenreInfo::GenreInfo(Genre gen) {
	this->genreId = gen.id;
	this->genreName = gen.name;
}