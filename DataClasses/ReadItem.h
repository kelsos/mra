#ifndef READITEM_H
#define READITEM_H

#include <wx/wx.h>

class ReadItem {
public:
	/** Default constructor */
	ReadItem();
	/** Full Parameter Constructor */
	ReadItem(wxString mangaTitle, unsigned intstartingChapter,
			unsigned intcurrentChapter, wxString onlineUrl, wxDateTime lastRead,
			bool readFinished);
	/** Default destructor */
	virtual ~ReadItem();
	/** Access mangaTitle
	 * \return The current value of mangaTitle
	 */
	wxString GetmangaTitle() {
		return mangaTitle;
	}
	/** Set mangaTitle
	 * \param val New value to set
	 */
	void SetmangaTitle(wxString val) {
		mangaTitle = val;
	}
	/** Access startingChapter
	 * \return The current value of startingChapter
	 */
	unsigned int GetstartingChapter() {
		return startingChapter;
	}
	/** Set startingChapter
	 * \param val New value to set
	 */
	void SetstartingChapter(unsigned int val) {
		startingChapter = val;
	}
	/** Access currentChapter
	 * \return The current value of currentChapter
	 */
	unsigned int GetcurrentChapter() {
		return currentChapter;
	}
	/** Set currentChapter
	 * \param val New value to set
	 */
	void SetcurrentChapter(unsigned int val) {
		currentChapter = val;
	}
	/** Access onlineUrl
	 * \return The current value of onlineUrl
	 */
	wxString GetonlineUrl() {
		return onlineUrl;
	}
	/** Set onlineUrl
	 * \param val New value to set
	 */
	void SetonlineUrl(wxString val) {
		onlineUrl = val;
	}
	/** Access lastRead
	 * \return The current value of lastRead
	 */
	wxDateTime GetlastRead() {
		return lastRead;
	}
	/** Set lastRead
	 * \param val New value to set
	 */
	void SetlastRead(wxDateTime val) {
		lastRead = val;
	}
	/** Access readFinished
	 * \return The current value of readFinished
	 */
	bool GetreadFinished() {
		return readFinished;
	}
	/** Set readFinished
	 * \param val New value to set
	 */
	void SetreadFinished(bool val) {
		readFinished = val;
	}
protected:
private:
	wxString mangaTitle; //!< Member variable "mangaTitle"
	unsigned int startingChapter; //!< Member variable "startingChapter"
	unsigned int currentChapter; //!< Member variable "currentChapter"
	wxString onlineUrl; //!< Member variable "onlineUrl"
	wxDateTime lastRead; //!< Member variable "lastRead"
	bool readFinished; //!< Member variable "readFinished"
};

#endif // READITEM_H
