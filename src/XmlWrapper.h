#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <MangaInfo.h>
#include <DbWrapper.h>
#include <XmlSaxParser.h>
#include <XmlReadListSaxParser.h>

using namespace std;

/** TODO: Work on XML Logic
 *
 *
 */
class XmlWrapper {
public:
	/** Default constructor */
	XmlWrapper(DbWrapper* db);
	/** Default destructor */
	virtual ~XmlWrapper();
	/** Opens an xmlfile with
	 * \param fileName */
	bool openXmlFile(QString fileName);
	/** Creates the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool createApplicationSettings();
	/** Saves the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool saveApplicationSettings();
	/** Loads the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool loadApplicationSettings();
	/** Saves the user's reading list */
	bool saveUserReadingList();
	/** Loads the user's reading list */
	void loadUserReadingList(QString fileName);
	/** Saves the application data */
	bool saveApplicationData();
	/** Loads the application data */
	bool loadApplicationData();

protected:
private:
	void xmlParser(QString fileName);
	DbWrapper* db;

};

#endif // XMLWRAPPER_H
