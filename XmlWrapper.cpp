#include "XmlWrapper.h"

XmlWrapper::XmlWrapper()
{
    //ctor
}

XmlWrapper::~XmlWrapper()
{
    //dtor
}

void XmlWrapper::xmlParser(wxString fileName)
{
	wxLogDebug(wxT("I R IN YAR FUNCTION"));
	xmlDocPtr doc;
	xmlNodePtr currentNode;

	doc = xmlParseFile("test.xml");
	wxLogDebug(wxT("I HAS PARSE"));

	if(doc == NULL){
		wxLogDebug(wxT("Document Not Parsed"));
		return;
	}
	currentNode = xmlDocGetRootElement(doc);

	if(currentNode==NULL){
		wxLogDebug(wxT("Empty Document"));
		xmlFreeDoc(doc);
		return;
	}
	wxLogDebug(wxT("I HAS FINISHED"));

}

bool XmlWrapper::loadApplicationData()
{
	xmlParser(wxT("test"));
}
