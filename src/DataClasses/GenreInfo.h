#ifndef GENREINFO_H
#define GENREINFO_H

#include <qstring>
#include <qdatetime>

#include "DataStructs.h"

class GenreInfo {
public:
	/** Default constructor */
	GenreInfo();
	/** Parametered constructor */
	GenreInfo(unsigned int genreId, QString genreName);
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
	QString getGenreName() {
		return genreName;
	}
	/** Set genreName
	 * \param val New value to set
	 */
	void setGenreName(QString val) {
		genreName += val;
	}
	/** Nullifies the current object;
	 *
	 */
	void clear();
protected:
private:
	unsigned int genreId; //!< Member variable "genreId"
	QString genreName; //!< Member variable "genreName"
};

#endif // GENREINFO_H
