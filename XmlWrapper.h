#ifndef XMLWRAPPER_H
#define XMLWRAPPER_H

#include <rapidxml/rapidxml.hpp>
#include <wx/wx.h>
#include <wx/textfile.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <MangaInfo.h>
#include <DbWrapper.h>

using namespace rapidxml;
using namespace std;

/** TODO: Work on XML Logic with the RapidXML
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
    bool openXmlFile(wxString fileName);
    bool createApplicationSettings();
    bool saveApplicationSettings();
    bool loadApplicationSettings();
    bool saveUserReadingList();
    bool loadUserReadingList();
    bool saveApplicationData();
    bool loadApplicationData();

protected:
private:
    xml_document<> xmlDoc;
    void xmlParser(wxString fileName);


};

#endif // XMLWRAPPER_H
