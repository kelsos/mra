#ifndef GENREINFO_H
#define GENREINFO_H
#include <wx/wx.h>
#include "DataStructs.h"

class GenreInfo {
public:
	/** Default constructor */
	GenreInfo();
	/** Parametered constructor */
	GenreInfo(unsigned int genreId, wxString genreName);
	GenreInfo(Genre gen);
	/** Default destructor */
	virtual ~GenreInfo();
	/** Access genreId
	 * \return The current value of genreId
	 */
	unsigned int getGenreId() {
		return genreId;
	}
	/** Set genreId
	 * \param val New value to set
	 */
	void setGenreId(unsigned int val) {
		genreId = val;
	}
	/** Access genreName
	 * \return The current value of genreName
	 */
	wxString getGenreName() {
		return genreName;
	}
	/** Set genreName
	 * \param val New value to set
	 */
	void setGenreName(wxString val) {
		genreName += val;
	}
	/** Nullifies the current object;
	 *
	 */
	void clear();
protected:
private:
	unsigned int genreId; //!< Member variable "genreId"
	wxString genreName; //!< Member variable "genreName"
};

#endif // GENREINFO_H
