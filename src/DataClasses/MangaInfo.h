#ifndef MANGAINFO_H
#define MANGAINFO_H

#include <qstring>
#include <qdatetime>
#include <qbytearray>

class MangaInfo {
public:
	/** Default constructor */
	MangaInfo();
	MangaInfo(unsigned int mangaId, QString mangaTitle,
			QString mangaDescription, QDateTime mangaPublicationDate,
			QString mangaPublicationStatus, unsigned int mangaPublisherId,
			QByteArray mangaCover);
	/** Default destructor */
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
	QString getMangaTitle() {
		return mangaTitle;
	}
	/** Set mangaTitle
	 * \param val New value to set
	 */
	void setMangaTitle(QString val) {
		mangaTitle += val;
	}
	/** Access mangaDescription
	 * \return The current value of mangaDescription
	 */
	QString getMangaDescription() {
		return mangaDescription;
	}
	/** Set mangaDescription
	 * \param val New value to set
	 */
	void setMangaDescription(QString val) {
		mangaDescription += val;
	}
	/** Returns the manga Publication date (aka Date of first publication of the manga).
	 *
	 * @return
	 */
	QDateTime getMangaPublicationDate() {
		return mangaPublicationDate;
	}
	/** Sets the manga publication status.
	 *
	 * @param val
	 */
	void setMangaPublicationDate(QDateTime val) {
		mangaPublicationDate = val;
	}
	/** Returns the manga publication status.
	 *
	 * @return
	 */
	QString getMangaPublicationStatus() {
		return mangaPublicationStatus;
	}
	/** Sets the publisher ID related with the current manga.
	 *
	 * @param val
	 */
	void setMangaPublicationStatus(QString val) {
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
	QByteArray getMangaCover() {
		return mangaCover;
	}
	void setMangaCover(QByteArray cover)
	{
		mangaCover=cover;
	}
	/** Nullifies current object values.
	 *
	 */
	void clear();
protected:
private:
	unsigned int mangaId; //!< Member variable "mangaId"
	QString mangaTitle; //!< Member variable "mangaTitle"
	QString mangaDescription; //!< Member variable "mangaDescription"
	QDateTime mangaPublicationDate; //!< Member variable "mangaPublicationDate"
	QString mangaPublicationStatus; //!< Member variable "mangaPublicationStatus"
	unsigned int mangaPublisherId; //!< Member variable "mangaPublisherId"
	QByteArray mangaCover;
};

#endif // MANGAINFO_H
