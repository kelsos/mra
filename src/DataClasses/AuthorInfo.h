#ifndef AUTHORINFO_H
#define AUTHORINFO_H

#include <wx/wx.h>
#include "DataStructs.h"

class AuthorInfo {
public:
	/** Default constructor */
	AuthorInfo();
	/** Full Parametered Constructor */
	AuthorInfo(unsigned int authorId, wxString authorName,
			wxString authorNationality, wxDateTime authorBirthday,
			wxString authorWebsite);
	/** Constructor that gets an auth structure.
	 *
	 * @param auth
	 */
	AuthorInfo(Author auth);
	/** Default destructor */
	virtual ~AuthorInfo();
	/** Access authorId
	 * \return The current value of authorId
	 */
	unsigned int getAuthorId() {
		return authorId;
	}
	/** Set authorId
	 * \param val New value to set
	 */
	void setAuthorId(unsigned int val) {
		authorId = val;
	}
	/** Access authorName
	 * \return The current value of authorName
	 */
	wxString getAuthorName() {
		return authorName;
	}
	/** Set authorName
	 * \param val New value to set
	 */
	void setAuthorName(wxString val) {
		authorName += val;
	}
	/** Access authorNationality
	 * \return The current value of authorNationality
	 */
	wxString getAuthorNationality() {
		return authorNationality;
	}
	/** Set authorNationality
	 * \param val New value to set
	 */
	void setAuthorNationality(wxString val) {
		authorNationality += val;
	}
	/** Access authorBirthday
	 * \return The current value of authorBirthday
	 */
	wxDateTime getAuthorBirthday() {
		return authorBirthday;
	}
	/** Set authorBirthday
	 * \param val New value to set
	 */
	void setAuthorBirthday(wxDateTime val) {
		authorBirthday = val;
	}
	/** Access authorWebsite
	 * \return The current value of authorWebsite
	 */
	wxString getAuthorWebsite() {
		return authorWebsite;
	}
	/** Set authorWebsite
	 * \param val New value to set
	 */
	void setAuthorWebsite(wxString val) {
		authorWebsite += val;
	}
	/**
	 * nullifies the values of the specified instance.
	 */
	void clear();
protected:
private:
	unsigned int authorId; //!< Member variable "authorId"
	wxString authorName; //!< Member variable "authorName"
	wxString authorNationality; //!< Member variable "authorNationality"
	wxDateTime authorBirthday; //!< Member variable "authorBirthday"
	wxString authorWebsite; //!< Member variable "authorWebsite"
};

#endif // AUTHORINFO_H
