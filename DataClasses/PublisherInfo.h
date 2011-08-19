#ifndef PUBLISHERINFO_H
#define PUBLISHERINFO_H
#include <wx/wx.h>
#include <DataStructs.h>

class PublisherInfo {
public:
	/** Default constructor */
	PublisherInfo();
	/** Parametered constructor */
	PublisherInfo(unsigned int publisherId, wxString publisherName,
			wxString publisherCountry, wxString publisherWebsite,
			wxString publisherNote);
	PublisherInfo(Publisher pub);
	/** Default destructor */
	virtual ~PublisherInfo();
	/** Access publisherId
	 * \return The current value of publisherId
	 */
	unsigned int getPublisherId() {
		return publisherId;
	}
	/** Set publisherId
	 * \param val New value to set
	 */
	void setPublisherId(unsigned int val) {
		publisherId = val;
	}
	/** Access publisherName
	 * \return The current value of publisherName
	 */
	wxString getPublisherName() {
		return publisherName;
	}
	/** Set publisherName
	 * \param val New value to set
	 */
	void setPublisherName(wxString val) {
		publisherName += val;
	}
	/** Access publisherCountry
	 * \return The current value of publisherCountry
	 */
	wxString getPublisherCountry() {
		return publisherCountry;
	}
	/** Set publisherCountry
	 * \param val New value to set
	 */
	void setPublisherCountry(wxString val) {
		publisherCountry += val;
	}
	/** Access publisherWebsite
	 * \return The current value of publisherWebsite
	 */
	wxString getPublisherWebsite() {
		return publisherWebsite;
	}
	/** Set publisherWebsite
	 * \param val New value to set
	 */
	void setPublisherWebsite(wxString val) {
		publisherWebsite += val;
	}
	/** Access publisherNote
	 * \return The current value of publisherNote
	 */
	wxString getPublisherNote() {
		return publisherNote;
	}
	/** Set publisherNote
	 * \param val New value to set
	 */
	void setPublisherNote(wxString val) {
		publisherNote += val;
	}
	/**
	 * Nullifies the values of the current instance.
	 */
	void clear();
protected:
private:
	unsigned int publisherId; //!< Member variable "publisherId"
	wxString publisherName; //!< Member variable "publisherName"
	wxString publisherCountry; //!< Member variable "publisherCountry"
	wxString publisherWebsite; //!< Member variable "publisherWebsite"
	wxString publisherNote; //!< Member variable "publisherNote"
};

#endif // PUBLISHERINFO_H
