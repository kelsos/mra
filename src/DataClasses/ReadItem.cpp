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
	this->lastRead = QDateTime::fromString("01.01.190000:00:00","dd.MM.yyyyhh:mm:ss");
	this->readFinished = '\0';
}
