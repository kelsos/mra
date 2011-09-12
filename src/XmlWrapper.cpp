#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(DbWrapper* db) {
	//ctor
	this->db=db;
}

XmlWrapper::~XmlWrapper() {
	//dtor
}

void XmlWrapper::xmlParser(wxString fileName) {
	parseMangaData(fileName,db);
}

bool XmlWrapper::loadApplicationData() {
	xmlParser(wxT("test.xml"));
	return (true);
}
