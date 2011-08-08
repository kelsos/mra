#ifndef MANGAINFO_H
#define MANGAINFO_H
#include <wx/wx.h>

class MangaInfo
{
public:
  /** Default constructor */
  MangaInfo();
  MangaInfo(unsigned int mangaId, wxString mangaTitle, wxString mangaDescription, wxDateTime mangaPublicationDate, wxString mangaPublicationStatus, unsigned int mangaPublisherId);
  MangaInfo(unsigned int mangaId, wxString mangaTitle);
  /** Default destructor */
  virtual ~MangaInfo();
  /** Access mangaId
   * \return The current value of mangaId
   */
  unsigned int GetmangaId()
  {
    return mangaId;
  }
  /** Set mangaId
   * \param val New value to set
   */
  void SetmangaId(unsigned int val)
  {
    mangaId = val;
  }
  /** Access mangaTitle
   * \return The current value of mangaTitle
   */
  wxString GetmangaTitle()
  {
    return mangaTitle;
  }
  /** Set mangaTitle
   * \param val New value to set
   */
  void SetmangaTitle(wxString val)
  {
    mangaTitle = val;
  }
  /** Access mangaDescription
   * \return The current value of mangaDescription
   */
  wxString GetmangaDescription()
  {
    return mangaDescription;
  }
  /** Set mangaDescription
   * \param val New value to set
   */
  void SetmangaDescription(wxString val)
  {
    mangaDescription = val;
  }
  wxDateTime GetmangaPublicationDate()
  {
    return mangaPublicationDate;
  }
  void SetmangaPublicationDate(wxDateTime val)
  {
    mangaPublicationDate = val;
  }
  wxString GetmangaPublicationStatus()
  {
    return mangaPublicationStatus;
  }
  void SetmangaPublicationStatus(wxString val)
  {
    mangaPublicationStatus = val;
  }
  unsigned int GetmangaPublisherId()
  {
    return mangaPublisherId;
  }
  void SetmangaPublisherId(unsigned int val)
  {
    mangaPublisherId = val;
  }
protected:
private:
  unsigned int mangaId; //!< Member variable "mangaId"
  wxString mangaTitle; //!< Member variable "mangaTitle"
  wxString mangaDescription; //!< Member variable "mangaDescription"
  wxDateTime mangaPublicationDate; //!< Member variable "mangaPublicationDate"
  wxString mangaPublicationStatus; //!< Member variable "mangaPublicationStatus"
  unsigned int mangaPublisherId; //!< Member variable "mangaPublisherId"
};

#endif // MANGAINFO_H
