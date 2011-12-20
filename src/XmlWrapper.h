#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <qobject.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <MangaInfo.h>
#include <DbWrapper.h>
#include <XmlDataSaxParser.h>
#include <XmlReadListSaxParser.h>

using namespace std;

class XmlWrapper:public QObject  {
	Q_OBJECT
public:
	/** Default constructor */
	XmlWrapper(QObject* parent = 0);
	/** Default destructor */
	virtual ~XmlWrapper();
	/** Opens an xmlfile with
	 * \param fileName */
	void connectWithDatabase(DbWrapper* db);
	bool openXmlFile(QString fileName);
	/** Creates the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool createApplicationSettings();
	/** Saves the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool saveApplicationSettings();
	/** Loads the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
	bool loadApplicationSettings();
	/** Saves the user's reading list */
	bool saveUserReadingList();

	/** Saves the application data */
	bool saveApplicationData();


protected:
private:
	void xmlParser(QString fileName);
	DbWrapper* db;

public slots:
	/** Loads the user's reading list */
	void loadUserReadingList();
	/** Loads the application data */
	void loadApplicationData();
};

#endif // XMLWRAPPER_H
