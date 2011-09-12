#include "ReadItem.h"

ReadItem::ReadItem() {
	//ctor
}

ReadItem::ReadItem(unsigned int entryId, wxString mangaTitle, unsigned int startingChapter,
		unsigned int currentChapter, wxString onlineUrl, wxDateTime lastRead,
		bool readFinished) {
	this->entryId = entryId;
	this->mangaTitle = mangaTitle;
	this->startingChapter = startingChapter;
	this->currentChapter = currentChapter;
	this->onlineUrl = onlineUrl;
	this->lastRead = lastRead;
	this->readFinished = readFinished;
}

ReadItem::~ReadItem() {
	//dtor
}
