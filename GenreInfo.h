#ifndef GENREINFO_H
#define GENREINFO_H
#include <wx/wx.h>


class GenreInfo
{
public:
  /** Default constructor */
  GenreInfo();
  /** Parametered constructor */
  GenreInfo(unsigned int genreId, wxString genreName);
  /** Default destructor */
  virtual ~GenreInfo();
  /** Access genreId
   * \return The current value of genreId
   */
  unsigned int GetgenreId()
  {
    return genreId;
  }
  /** Set genreId
   * \param val New value to set
   */
  void SetgenreId(unsigned int val)
  {
    genreId = val;
  }
  /** Access genreName
   * \return The current value of genreName
   */
  wxString GetgenreName()
  {
    return genreName;
  }
  /** Set genreName
   * \param val New value to set
   */
  void SetgenreName(wxString val)
  {
    genreName = val;
  }
protected:
private:
  unsigned int genreId; //!< Member variable "genreId"
  wxString genreName; //!< Member variable "genreName"
};

#endif // GENREINFO_H
