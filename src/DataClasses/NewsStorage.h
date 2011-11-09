#ifndef NEWSSTORAGE_H
#define NEWSSTORAGE_H

#include <qstring>
#include <qdatetime>

class NewsStorage {
public:
	/** Default constructor */
	NewsStorage();
	NewsStorage(unsigned int newsItemId, QString newsItemTitle,
			QString newsItemHyperLink, QString newsItemDescription,
			QDateTime newsItemPublicationDate,
			QDateTime newsItemAquisitionDate);
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
	QString getNewsItemTitle() {
		return newsItemTitle;
	}
	/** Set newsItemTitle
	 * \param val New value to set
	 */
	void setNewsItemTitle(QString val) {
		newsItemTitle = val;
	}
	/** Access newsItemHyperLink
	 * \return The current value of newsItemHyperLink
	 */
	QString getNewsItemHyperLink() {
		return newsItemHyperLink;
	}
	/** Set newsItemHyperLink
	 * \param val New value to set
	 */
	void setNewsItemHyperLink(QString val) {
		newsItemHyperLink = val;
	}
	/** Access newsItemDescription
	 * \return The current value of newsItemDescription
	 */
	QString getNewsItemDescription() {
		return newsItemDescription;
	}
	/** Set newsItemDescription
	 * \param val New value to set
	 */
	void setNewsItemDescription(QString val) {
		newsItemDescription = val;
	}
	/** Access newsItemPublicationDate
	 * \return The current value of newsItemPublicationDate
	 */
	QDateTime getNewsItemPublicationDate() {
		return newsItemPublicationDate;
	}
	/** Set newsItemPublicationDate
	 * \param val New value to set
	 */
	void setNewsItemPublicationDate(QDateTime val) {
		newsItemPublicationDate = val;
	}
	/** Access newsItemAquisitionDate
	 * \return The current value of newsItemAquisitionDate
	 */
	QDateTime getNewsItemAquisitionDate() {
		return newsItemAquisitionDate;
	}
	/** Set newsItemAquisitionDate
	 * \param val New value to set
	 */
	void setNewsItemAquisitionDate(QDateTime val) {
		newsItemAquisitionDate = val;
	}
protected:
private:
	unsigned int newsItemId; //!< Member variable "newsItemId"
	QString newsItemTitle; //!< Member variable "newsItemTitle"
	QString newsItemHyperLink; //!< Member variable "newsItemHyperLink"
	QString newsItemDescription; //!< Member variable "newsItemDescription"
	QDateTime newsItemPublicationDate; //!< Member variable "newsItemPublicationDate"
	QDateTime newsItemAquisitionDate; //!< Member variable "newsItemAquisitionDate"
};

#endif // NEWSSTORAGE_H
