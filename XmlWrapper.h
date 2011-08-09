#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <libxml/tree.h>
#include <wx/wx.h>
#include <wx/textfile.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <MangaInfo.h>
#include <DbWrapper.h>

using namespace std;

/** TODO: Work on XML Logic
 *
 *
 */
class XmlWrapper
{
public:
    /** Default constructor */
    XmlWrapper();
    /** Default destructor */
    virtual ~XmlWrapper();
    /** Opens an xmlfile with
     * \param fileName */
    bool openXmlFile(wxString fileName);
    /** Creates the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
    bool createApplicationSettings();
    /** Saves the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
    bool saveApplicationSettings();
    /** Loads the application settings file. !Probably to be replaced with internal wxWidgets configuration system */
    bool loadApplicationSettings();
    bool saveUserReadingList();
    bool loadUserReadingList();
    bool saveApplicationData();
    bool loadApplicationData();

protected:
private:
    void xmlParser(wxString fileName);


};

#endif // XMLWRAPPER_H
