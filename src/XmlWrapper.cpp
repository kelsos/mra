#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(DbWrapper* db) {
	//ctor
	this->db=db;
}

XmlWrapper::~XmlWrapper() {
	//dtor
}

void XmlWrapper::xmlParser(QString fileName) {
	QByteArray fArray = fileName.toAscii();
	parseMangaData((const char*)fArray.data(),db);
}

bool XmlWrapper::loadApplicationData() {
	xmlParser("test.xml");
	return (true);
}

void XmlWrapper::loadUserReadingList(QString fileName){
	QByteArray fArray = fileName.toAscii();
    parseReadingList((const char*)fArray.data(),db);
}
