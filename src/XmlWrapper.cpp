#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(DbWrapper* db) {
	//ctor
	this->db=db;
}

XmlWrapper::~XmlWrapper() {
	//dtor
}

void XmlWrapper::xmlParser(QString fileName) {
	parseMangaData((const char*)fileName,db);
}

bool XmlWrapper::loadApplicationData() {
	xmlParser("test.xml");
	return (true);
}

void XmlWrapper::loadUserReadingList(QString fileName){
    parseReadingList((const char*)fileName,db);
}
