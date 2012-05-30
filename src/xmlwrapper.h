#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <QDebug>
#include <xmldataparser.h>
#include "xmlreadinglistparser.h"
//Data classes included.
#include "DataClasses/authorinfo.h"
#include "DataClasses/genreinfo.h"
#include "DataClasses/mangaauthors.h"
#include "DataClasses/mangagenres.h"
#include "DataClasses/mangainfo.h"
#include "DataClasses/publisherinfo.h"
#include "DataClasses/mangagenres.h"
#include "DataClasses/mangaauthors.h"

using namespace std;

class XmlWrapper:public QObject
{
    Q_OBJECT
public:
    /** Default constructor */
    XmlWrapper(QObject* parent = 0);
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

    /** Saves the application data */
    bool saveApplicationData();

protected:
private:
    void xmlParser(QString fileName);
    XmlReadingListParser *xmP;
    XmlDataParser *xmD;

public slots:
    /** Loads the user's reading list */
    void loadUserReadingList();
    /** Loads the application data */
    void loadApplicationData();
};

#endif // XMLWRAPPER_H
