#include "ReadItem.h"

ReadItem::ReadItem() {
	//ctor
}

ReadItem::ReadItem(unsigned int entryId, QString mangaTitle, unsigned int startingChapter,
		unsigned int currentChapter, QString onlineUrl, QDateTime lastRead,
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

void ReadItem::clear()
{
	this->entryId = '\0';
	this->mangaTitle = '\0';
	this->startingChapter = '\0';
	this->currentChapter = '\0';
	this->onlineUrl = '\0';
	this->lastRead = QDateTime::currentDateTime();
	this->readFinished = '\0';
}
