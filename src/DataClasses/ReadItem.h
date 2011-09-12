#ifndef READITEM_H
#define READITEM_H

#include <wx/wx.h>

class ReadItem {
public:
	/** Default constructor */
	ReadItem();
	/** Full Parameter Constructor */
	ReadItem(unsigned int entryId, wxString mangaTitle, unsigned int startingChapter,
			unsigned int currentChapter, wxString onlineUrl,
			wxDateTime lastRead, bool readFinished);
	/** Default destructor */
	virtual ~ReadItem();
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
		mangaTitle = val;
	}
	/** Access startingChapter
	 * \return The current value of startingChapter
	 */
	unsigned int getStartingChapter() {
		return startingChapter;
	}
	/** Set startingChapter
	 * \param val New value to set
	 */
	void setStartingChapter(unsigned int val) {
		startingChapter = val;
	}
	/** Access currentChapter
	 * \return The current value of currentChapter
	 */
	unsigned int getCurrentChapter() {
		return currentChapter;
	}
	/** Set currentChapter
	 * \param val New value to set
	 */
	void setCurrentChapter(unsigned int val) {
		currentChapter = val;
	}
	/** Access onlineUrl
	 * \return The current value of onlineUrl
	 */
	wxString getOnlineUrl() {
		return onlineUrl;
	}
	/** Set onlineUrl
	 * \param val New value to set
	 */
	void setOnlineUrl(wxString val) {
		onlineUrl = val;
	}
	/** Access lastRead
	 * \return The current value of lastRead
	 */
	wxDateTime getLastRead() {
		return lastRead;
	}
	/** Set lastRead
	 * \param val New value to set
	 */
	void setLastRead(wxDateTime val) {
		lastRead = val;
	}
	/** Access readFinished
	 * \return The current value of readFinished
	 */
	bool getReadFinished() {
		return readFinished;
	}
	/** Set readFinished
	 * \param val New value to set
	 */
	void setReadFinished(bool val) {
		readFinished = val;
	}
	/** Access mangaNote
	 *
	 * @return
	 */
	wxString getMangaNote() {
		return mangaNote;
	}
	/** Set mangaNote
	 *
	 * @param val New value to set.
	 */
	void setMangaNote(wxString val) {
		mangaNote = val;
	}
	/** Appends the val to the existing data of mangaNote
	 *
	 * @param val
	 */
	void appendMangaNote(wxString val) {
		mangaNote += val;
	}
	/** Set entryId
	 *
	 * @param val
	 */
	void setEntryId(unsigned int val) {
		entryId = val;
	}
	/** Access entryId
	 *
	 * @return
	 */
	unsigned int getEntryId() {
		return entryId;
	}
protected:
private:
	unsigned int entryId; //!< Member variable "entryId"
	wxString mangaTitle; //!< Member variable "mangaTitle"
	unsigned int startingChapter; //!< Member variable "startingChapter"
	unsigned int currentChapter; //!< Member variable "currentChapter"
	wxString onlineUrl; //!< Member variable "onlineUrl"
	wxDateTime lastRead; //!< Member variable "lastRead"
	bool readFinished; //!< Member variable "readFinished"
	wxString mangaNote; //!< Member variable "mangaNote"
};

#endif // READITEM_H
