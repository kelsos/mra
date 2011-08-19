#ifndef NEWSSTORAGE_H
#define NEWSSTORAGE_H

#include <wx/wx.h>

class NewsStorage {
public:
	/** Default constructor */
	NewsStorage();
	NewsStorage(unsigned int newsItemId, wxString newsItemTitle,
			wxString newsItemHyperLink, wxString newsItemDescription,
			wxDateTime newsItemPublicationDate,
			wxDateTime newsItemAquisitionDate);
	/** Default destructor */
	virtual ~NewsStorage();
	/** Access newsItemId
	 * \return The current value of newsItemId
	 */
	unsigned int getNewsItemId() {
		return newsItemId;
	}
	/** Set newsItemId
	 * \param val New value to set
	 */
	void setNewsItemId(unsigned int val) {
		newsItemId = val;
	}
	/** Access newsItemTitle
	 * \return The current value of newsItemTitle
	 */
	wxString getNewsItemTitle() {
		return newsItemTitle;
	}
	/** Set newsItemTitle
	 * \param val New value to set
	 */
	void setNewsItemTitle(wxString val) {
		newsItemTitle = val;
	}
	/** Access newsItemHyperLink
	 * \return The current value of newsItemHyperLink
	 */
	wxString getNewsItemHyperLink() {
		return newsItemHyperLink;
	}
	/** Set newsItemHyperLink
	 * \param val New value to set
	 */
	void setNewsItemHyperLink(wxString val) {
		newsItemHyperLink = val;
	}
	/** Access newsItemDescription
	 * \return The current value of newsItemDescription
	 */
	wxString getNewsItemDescription() {
		return newsItemDescription;
	}
	/** Set newsItemDescription
	 * \param val New value to set
	 */
	void setNewsItemDescription(wxString val) {
		newsItemDescription = val;
	}
	/** Access newsItemPublicationDate
	 * \return The current value of newsItemPublicationDate
	 */
	wxDateTime getNewsItemPublicationDate() {
		return newsItemPublicationDate;
	}
	/** Set newsItemPublicationDate
	 * \param val New value to set
	 */
	void setNewsItemPublicationDate(wxDateTime val) {
		newsItemPublicationDate = val;
	}
	/** Access newsItemAquisitionDate
	 * \return The current value of newsItemAquisitionDate
	 */
	wxDateTime getNewsItemAquisitionDate() {
		return newsItemAquisitionDate;
	}
	/** Set newsItemAquisitionDate
	 * \param val New value to set
	 */
	void setNewsItemAquisitionDate(wxDateTime val) {
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
