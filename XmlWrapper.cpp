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
	ifstream input("test.xml");
	string file;
	string str;

	while (getline(input, str)) {
		file += str;
	}

	vector<char> xmlFileVector(file.begin(),file.end());

	xmlFileVector.push_back('\0');
	//Log Console messages
	wxLogDebug(wxT("pass the vector creation"));

	xml_document<> xmlDoc;

	xmlDoc.parse<parse_no_data_nodes>(&xmlFileVector[0]);
	//Log Console messages
	wxLogDebug(wxT("parse method called"));

	xml_node<>* currentNode = xmlDoc.first_node("MangaDatabase");
	currentNode = currentNode->first_node("Mangas")->first_node("Manga");

	//Log Console Messages
	wxLogDebug(wxT("parse method called"));

	DbWrapper *Db = new DbWrapper();
	while(currentNode!=NULL)
	{
		Db->insertMangaData2((unsigned int)currentNode->first_node("MangaID")->value(),currentNode->first_node("MangaTitle")->value());
		currentNode = currentNode->next_sibling();
	}



//
//	xml_document<> doc;
//
//	doc.parse<parse_no_data_nodes>(&xmlCopy[0]);
//
//	xml_node<>* currentNode = doc.first_node("MangaDatabase");
//	currentNode = currentNode->first_node("Mangas")->first_node("Manga");
//
//	while(currentNode!=NULL)
//	{
//		cout << currentNode->first_node("MangaTitle")->value() << endl;
//		currentNode = currentNode->next_sibling();
//	}


}

bool XmlWrapper::loadApplicationData()
{
	xmlParser(wxT("test"));
}
