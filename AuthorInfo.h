#ifndef AUTHORINFO_H
#define AUTHORINFO_H

#include <wx/wx.h>

class AuthorInfo
{
public:
  /** Default constructor */
  AuthorInfo();
  /** Full Parametered Constructor */
  AuthorInfo(unsigned int authorId, wxString authorName, wxString authorNationality, wxDateTime authorBirthday, wxString authorWebsite);
  /** Default destructor */
  virtual ~AuthorInfo();
  /** Access authorId
   * \return The current value of authorId
   */
  unsigned int GetauthorId()
  {
    return authorId;
  }
  /** Set authorId
   * \param val New value to set
   */
  void SetauthorId(unsigned int val)
  {
    authorId = val;
  }
  /** Access authorName
   * \return The current value of authorName
   */
  wxString GetauthorName()
  {
    return authorName;
  }
  /** Set authorName
   * \param val New value to set
   */
  void SetauthorName(wxString val)
  {
    authorName = val;
  }
  /** Access authorNationality
   * \return The current value of authorNationality
   */
  wxString GetauthorNationality()
  {
    return authorNationality;
  }
  /** Set authorNationality
   * \param val New value to set
   */
  void SetauthorNationality(wxString val)
  {
    authorNationality = val;
  }
  /** Access authorBirthday
   * \return The current value of authorBirthday
   */
  wxDateTime GetauthorBirthday()
  {
    return authorBirthday;
  }
  /** Set authorBirthday
   * \param val New value to set
   */
  void SetauthorBirthday(wxDateTime val)
  {
    authorBirthday = val;
  }
  /** Access authorWebsite
  * \return The current value of authorWebsite
  */
  wxString GetauthorWebsite()
  {
    return authorWebsite;
  }
  /** Set authorWebsite
  * \param val New value to set
  */
  void SetauthorWebsite(wxString val)
  {
    authorWebsite = val;
  }

protected:
private:
  unsigned int authorId; //!< Member variable "authorId"
  wxString authorName; //!< Member variable "authorName"
  wxString authorNationality; //!< Member variable "authorNationality"
  wxDateTime authorBirthday; //!< Member variable "authorBirthday"
  wxString authorWebsite; //!< Member variable "authorWebsite"
};

#endif // AUTHORINFO_H
