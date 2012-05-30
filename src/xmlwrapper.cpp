#include "xmlwrapper.h"

XmlWrapper::XmlWrapper(QObject* parent)
    :QObject(parent)
{

}

XmlWrapper::~XmlWrapper()
{
}

void XmlWrapper::xmlParser(QString fileName)
{

}

void XmlWrapper::loadApplicationData()
{
    xmD = new XmlDataParser;
    xmD->parseData("data.xml");
}

void XmlWrapper::loadUserReadingList()
{
    xmP = new XmlReadingListParser;
    xmP->parseReadingList("test.xml");
}
