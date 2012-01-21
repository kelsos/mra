#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(QObject* parent)
:QObject(parent){

}

XmlWrapper::~XmlWrapper() {
}
void XmlWrapper::connectWithDatabase(DbWrapper* db)
{
	this->db=db;
}

void XmlWrapper::xmlParser(QString fileName) {
	QByteArray fArray = fileName.toAscii();
	parseMangaData((const char*)fArray.data(),db);
}

void XmlWrapper::loadApplicationData() {
	xmlParser("data.xml");
}

void XmlWrapper::loadUserReadingList(){

	//QByteArray fArray = fileName.toAscii();
	//(const char*)fArray.data()
	xmP = new XmlReadingListParser;
	xmP->ParseReadingList("test.xml",db);
}