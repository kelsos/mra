#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(DbWrapper* db) {
	//ctor
	this->db=db;
}

XmlWrapper::~XmlWrapper() {
	//dtor
}

void XmlWrapper::xmlParser(wxString fileName) {
	manga_parser_parse_file(fileName,db);
}

bool XmlWrapper::loadApplicationData() {
	xmlParser(wxT("test.xml"));
	return (true);
}
