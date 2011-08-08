#ifndef PUBLISHERINFO_H
#define PUBLISHERINFO_H
#include <wx/wx.h>

class PublisherInfo
{
public:
  /** Default constructor */
  PublisherInfo();
  /** Parametered constructor */
  PublisherInfo(unsigned int publisherId, wxString publisherName, wxString publisherCountry, wxString publisherWebsite, wxString publisherNote);
  /** Default destructor */
  virtual ~PublisherInfo();
  /** Access publisherId
   * \return The current value of publisherId
   */
  unsigned int GetpublisherId()
  {
    return publisherId;
  }
  /** Set publisherId
   * \param val New value to set
   */
  void SetpublisherId(unsigned int val)
  {
    publisherId = val;
  }
  /** Access publisherName
   * \return The current value of publisherName
   */
  wxString GetpublisherName()
  {
    return publisherName;
  }
  /** Set publisherName
   * \param val New value to set
   */
  void SetpublisherName(wxString val)
  {
    publisherName = val;
  }
  /** Access publisherCountry
   * \return The current value of publisherCountry
   */
  wxString GetpublisherCountry()
  {
    return publisherCountry;
  }
  /** Set publisherCountry
   * \param val New value to set
   */
  void SetpublisherCountry(wxString val)
  {
    publisherCountry = val;
  }
  /** Access publisherWebsite
   * \return The current value of publisherWebsite
   */
  wxString GetpublisherWebsite()
  {
    return publisherWebsite;
  }
  /** Set publisherWebsite
   * \param val New value to set
   */
  void SetpublisherWebsite(wxString val)
  {
    publisherWebsite = val;
  }
  /** Access publisherNote
   * \return The current value of publisherNote
   */
  wxString GetpublisherNote()
  {
    return publisherNote;
  }
  /** Set publisherNote
   * \param val New value to set
   */
  void SetpublisherNote(wxString val)
  {
    publisherNote = val;
  }
protected:
private:
  unsigned int publisherId; //!< Member variable "publisherId"
  wxString publisherName; //!< Member variable "publisherName"
  wxString publisherCountry; //!< Member variable "publisherCountry"
  wxString publisherWebsite; //!< Member variable "publisherWebsite"
  wxString publisherNote; //!< Member variable "publisherNote"
};

#endif // PUBLISHERINFO_H
