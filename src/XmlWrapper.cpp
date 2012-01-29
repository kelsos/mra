#include "XmlWrapper.h"

XmlWrapper::XmlWrapper(QObject* parent)
    :QObject(parent)
{

}

XmlWrapper::~XmlWrapper()
{
}
void XmlWrapper::connectWithDatabase(DbWrapper* db)
{
    this->db=db;
}

void XmlWrapper::xmlParser(QString fileName)
{

}

void XmlWrapper::loadApplicationData()
{
    xmD = new XmlDataParser;
    xmD->parseData("data.xml",db);
}

void XmlWrapper::loadUserReadingList()
{
    xmP = new XmlReadingListParser;
    xmP->parseReadingList("test.xml",db);
}
