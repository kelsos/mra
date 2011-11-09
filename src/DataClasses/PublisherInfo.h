#ifndef PUBLISHERINFO_H
#define PUBLISHERINFO_H

#include <qstring>
#include <qdatetime>

#include "DataStructs.h"

class PublisherInfo {
public:
	/** Default constructor */
	PublisherInfo();
	/** Parametered constructor */
	PublisherInfo(unsigned int publisherId, QString publisherName,
			QString publisherCountry, QString publisherWebsite,
			QString publisherNote);
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
	QString getPublisherName() {
		return publisherName;
	}
	/** Set publisherName
	 * \param val New value to set
	 */
	void setPublisherName(QString val) {
		publisherName += val;
	}
	/** Access publisherCountry
	 * \return The current value of publisherCountry
	 */
	QString getPublisherCountry() {
		return publisherCountry;
	}
	/** Set publisherCountry
	 * \param val New value to set
	 */
	void setPublisherCountry(QString val) {
		publisherCountry += val;
	}
	/** Access publisherWebsite
	 * \return The current value of publisherWebsite
	 */
	QString getPublisherWebsite() {
		return publisherWebsite;
	}
	/** Set publisherWebsite
	 * \param val New value to set
	 */
	void setPublisherWebsite(QString val) {
		publisherWebsite += val;
	}
	/** Access publisherNote
	 * \return The current value of publisherNote
	 */
	QString getPublisherNote() {
		return publisherNote;
	}
	/** Set publisherNote
	 * \param val New value to set
	 */
	void setPublisherNote(QString val) {
		publisherNote += val;
	}
	/**
	 * Nullifies the values of the current instance.
	 */
	void clear();
protected:
private:
	unsigned int publisherId; //!< Member variable "publisherId"
	QString publisherName; //!< Member variable "publisherName"
	QString publisherCountry; //!< Member variable "publisherCountry"
	QString publisherWebsite; //!< Member variable "publisherWebsite"
	QString publisherNote; //!< Member variable "publisherNote"
};

#endif // PUBLISHERINFO_H
