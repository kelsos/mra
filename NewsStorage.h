#ifndef NEWSSTORAGE_H
#define NEWSSTORAGE_H

#include <wx/wx.h>


class NewsStorage
{
public:
  /** Default constructor */
  NewsStorage();
  NewsStorage(unsigned int newsItemId, wxString newsItemTitle, wxString newsItemHyperLink, wxString newsItemDescription, wxDateTime newsItemPublicationDate, wxDateTime newsItemAquisitionDate);
  /** Default destructor */
  virtual ~NewsStorage();
  /** Access newsItemId
   * \return The current value of newsItemId
   */
  unsigned int GetnewsItemId()
  {
    return newsItemId;
  }
  /** Set newsItemId
   * \param val New value to set
   */
  void SetnewsItemId(unsigned int val)
  {
    newsItemId = val;
  }
  /** Access newsItemTitle
   * \return The current value of newsItemTitle
   */
  wxString GetnewsItemTitle()
  {
    return newsItemTitle;
  }
  /** Set newsItemTitle
   * \param val New value to set
   */
  void SetnewsItemTitle(wxString val)
  {
    newsItemTitle = val;
  }
  /** Access newsItemHyperLink
   * \return The current value of newsItemHyperLink
   */
  wxString GetnewsItemHyperLink()
  {
    return newsItemHyperLink;
  }
  /** Set newsItemHyperLink
   * \param val New value to set
   */
  void SetnewsItemHyperLink(wxString val)
  {
    newsItemHyperLink = val;
  }
  /** Access newsItemDescription
   * \return The current value of newsItemDescription
   */
  wxString GetnewsItemDescription()
  {
    return newsItemDescription;
  }
  /** Set newsItemDescription
   * \param val New value to set
   */
  void SetnewsItemDescription(wxString val)
  {
    newsItemDescription = val;
  }
  /** Access newsItemPublicationDate
   * \return The current value of newsItemPublicationDate
   */
  wxDateTime GetnewsItemPublicationDate()
  {
    return newsItemPublicationDate;
  }
  /** Set newsItemPublicationDate
   * \param val New value to set
   */
  void SetnewsItemPublicationDate(wxDateTime val)
  {
    newsItemPublicationDate = val;
  }
  /** Access newsItemAquisitionDate
   * \return The current value of newsItemAquisitionDate
   */
  wxDateTime GetnewsItemAquisitionDate()
  {
    return newsItemAquisitionDate;
  }
  /** Set newsItemAquisitionDate
   * \param val New value to set
   */
  void SetnewsItemAquisitionDate(wxDateTime val)
  {
    newsItemAquisitionDate = val;
  }
protected:
private:
  unsigned int newsItemId; //!< Member variable "newsItemId"
  wxString newsItemTitle; //!< Member variable "newsItemTitle"
  wxString newsItemHyperLink; //!< Member variable "newsItemHyperLink"
  wxString newsItemDescription; //!< Member variable "newsItemDescription"
  wxDateTime newsItemPublicationDate; //!< Member variable "newsItemPublicationDate"
  wxDateTime newsItemAquisitionDate; //!< Member variable "newsItemAquisitionDate"
};

#endif // NEWSSTORAGE_H
