#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <QDebug>
#include "xmlreadinglistparser.h"
#include "xmldataparser.h"
//Data classes included.
#include "entities/authorinfo.h"
#include "entities/genreinfo.h"
#include "entities/mangaauthors.h"
#include "entities/mangagenres.h"
#include "entities/mangainfo.h"
#include "entities/publisherinfo.h"
#include "entities/mangagenres.h"
#include "entities/mangaauthors.h"

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
