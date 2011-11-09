#ifndef AUTHORINFO_H
#define AUTHORINFO_H

#include <qstring>
#include <qdatetime>

#include "DataStructs.h"

class AuthorInfo {
public:
	/** Default constructor */
	AuthorInfo();
	/** Full Parametered Constructor */
	AuthorInfo(unsigned int authorId, QString authorName,
			QString authorNationality, QDateTime authorBirthday,
			QString authorWebsite);
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
	QString getAuthorName() {
		return authorName;
	}
	/** Set authorName
	 * \param val New value to set
	 */
	void setAuthorName(QString val) {
		authorName += val;
	}
	/** Access authorNationality
	 * \return The current value of authorNationality
	 */
	QString getAuthorNationality() {
		return authorNationality;
	}
	/** Set authorNationality
	 * \param val New value to set
	 */
	void setAuthorNationality(QString val) {
		authorNationality += val;
	}
	/** Access authorBirthday
	 * \return The current value of authorBirthday
	 */
	QDateTime getAuthorBirthday() {
		return authorBirthday;
	}
	/** Set authorBirthday
	 * \param val New value to set
	 */
	void setAuthorBirthday(QDateTime val) {
		authorBirthday = val;
	}
	/** Access authorWebsite
	 * \return The current value of authorWebsite
	 */
	QString getAuthorWebsite() {
		return authorWebsite;
	}
	/** Set authorWebsite
	 * \param val New value to set
	 */
	void setAuthorWebsite(QString val) {
		authorWebsite += val;
	}
	/**
	 * nullifies the values of the specified instance.
	 */
	void clear();
protected:
private:
	unsigned int authorId; //!< Member variable "authorId"
	QString authorName; //!< Member variable "authorName"
	QString authorNationality; //!< Member variable "authorNationality"
	QDateTime authorBirthday; //!< Member variable "authorBirthday"
	QString authorWebsite; //!< Member variable "authorWebsite"
};

#endif // AUTHORINFO_H
