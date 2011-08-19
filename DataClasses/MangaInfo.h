#ifndef MANGAINFO_H
#define MANGAINFO_H
#include <wx/wx.h>
#include "DataStructs.h"


class MangaInfo {
public:
	/** Default constructor */
	MangaInfo();
	MangaInfo(unsigned int mangaId, wxString mangaTitle,
			wxString mangaDescription, wxDateTime mangaPublicationDate,
			wxString mangaPublicationStatus, unsigned int mangaPublisherId,
			wxMemoryBuffer mangaCover);
	/** Default destructor */
	MangaInfo(Manga man);
	virtual ~MangaInfo();
	/** Access mangaId
	 * \return The current value of mangaId
	 */
	unsigned int getMangaId() {
		return mangaId;
	}
	/** Set mangaId
	 * \param val New value to set
	 */
	void setMangaId(unsigned int val) {
		mangaId = val;
	}
	/** Access mangaTitle
	 * \return The current value of mangaTitle
	 */
	wxString getMangaTitle() {
		return mangaTitle;
	}
	/** Set mangaTitle
	 * \param val New value to set
	 */
	void setMangaTitle(wxString val) {
		mangaTitle += val;
	}
	/** Access mangaDescription
	 * \return The current value of mangaDescription
	 */
	wxString getMangaDescription() {
		return mangaDescription;
	}
	/** Set mangaDescription
	 * \param val New value to set
	 */
	void setMangaDescription(wxString val) {
		mangaDescription += val;
	}
	/** Returns the manga Publication date (aka Date of first publication of the manga).
	 *
	 * @return
	 */
	wxDateTime getMangaPublicationDate() {
		return mangaPublicationDate;
	}
	/** Sets the manga publication status.
	 *
	 * @param val
	 */
	void setMangaPublicationDate(wxDateTime val) {
		mangaPublicationDate = val;
	}
	/** Returns the manga publication status.
	 *
	 * @return
	 */
	wxString getMangaPublicationStatus() {
		return mangaPublicationStatus;
	}
	/** Sets the publisher ID related with the current manga.
	 *
	 * @param val
	 */
	void setMangaPublicationStatus(wxString val) {
		mangaPublicationStatus = val;
	}
	/** Returns the publisher ID related with the current manga.
	 *
	 * @return
	 */
	unsigned int getMangaPublisherId() {
		return mangaPublisherId;
	}
	/** Set Manga Publisher ID
	 *
	 * @param val
	 */
	void setMangaPublisherId(unsigned int val) {
		mangaPublisherId = val;
	}
	/** Returns the wxMemoryBuffer that represents the
	 * stored image for the specified manga.
	 */
	wxMemoryBuffer getMangaCover() {
		return mangaCover;
	}
	/** Nullifies current object values.
	 *
	 */
	void clear();
protected:
private:
	unsigned int mangaId; //!< Member variable "mangaId"
	wxString mangaTitle; //!< Member variable "mangaTitle"
	wxString mangaDescription; //!< Member variable "mangaDescription"
	wxDateTime mangaPublicationDate; //!< Member variable "mangaPublicationDate"
	wxString mangaPublicationStatus; //!< Member variable "mangaPublicationStatus"
	unsigned int mangaPublisherId; //!< Member variable "mangaPublisherId"
	wxMemoryBuffer mangaCover;
};

#endif // MANGAINFO_H
