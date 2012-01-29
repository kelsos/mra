#ifndef READITEM_H
#define READITEM_H

#include <QString>
#include <QDateTime>

class ReadItem
{
public:
    /** Default constructor */
    ReadItem();
    /** Full Parameter Constructor */
    ReadItem(unsigned int entryId, QString mangaTitle, unsigned int startingChapter,
             unsigned int currentChapter, QString onlineUrl,
             QDateTime lastRead, bool readFinished);
    /** Default destructor */
    virtual ~ReadItem();
    /** Access mangaTitle
     * \return The current value of mangaTitle
     */
    QString getMangaTitle()
    {
        return mangaTitle;
    }
    /** Set mangaTitle
     * \param val New value to set
     */
    void setMangaTitle(QString val)
    {
        mangaTitle = val;
    }
    /** Access startingChapter
     * \return The current value of startingChapter
     */
    unsigned int getStartingChapter()
    {
        return startingChapter;
    }
    /** Set startingChapter
     * \param val New value to set
     */
    void setStartingChapter(unsigned int val)
    {
        startingChapter = val;
    }
    /** Access currentChapter
     * \return The current value of currentChapter
     */
    unsigned int getCurrentChapter()
    {
        return currentChapter;
    }
    /** Set currentChapter
     * \param val New value to set
     */
    void setCurrentChapter(unsigned int val)
    {
        currentChapter = val;
    }
    /** Access onlineUrl
     * \return The current value of onlineUrl
     */
    QString getOnlineUrl()
    {
        return onlineUrl;
    }
    /** Set onlineUrl
     * \param val New value to set
     */
    void setOnlineUrl(QString val)
    {
        onlineUrl = val;
    }
    /** Access lastRead
     * \return The current value of lastRead
     */
    QDateTime getLastRead()
    {
        return lastRead;
    }
    /** Set lastRead
     * \param val New value to set
     */
    void setLastRead(QDateTime val)
    {
        lastRead = val;
    }
    /** Access readFinished
     * \return The current value of readFinished
     */
    bool getReadFinished()
    {
        return readFinished;
    }
    /** Set readFinished
     * \param val New value to set
     */
    void setReadFinished(bool val)
    {
        readFinished = val;
    }
    /** Access mangaNote
     *
     * @return
     */
    QString getMangaNote()
    {
        return mangaNote;
    }
    /** Set mangaNote
     *
     * @param val New value to set.
     */
    void setMangaNote(QString val)
    {
        mangaNote = val;
    }
    /** Appends the val to the existing data of mangaNote
     *
     * @param val
     */
    void appendMangaNote(QString val)
    {
        mangaNote += val;
    }
    /** Set entryId
     *
     * @param val
     */
    void setEntryId(unsigned int val)
    {
        entryId = val;
    }
    /** Access entryId
     *
     * @return
     */
    unsigned int getEntryId()
    {
        return entryId;
    }
    /** Clears the object data.
     *
     */
    void clear();
protected:
private:
    unsigned int entryId; //!< Member variable "entryId"
    QString mangaTitle; //!< Member variable "mangaTitle"
    unsigned int startingChapter; //!< Member variable "startingChapter"
    unsigned int currentChapter; //!< Member variable "currentChapter"
    QString onlineUrl; //!< Member variable "onlineUrl"
    QDateTime lastRead; //!< Member variable "lastRead"
    bool readFinished; //!< Member variable "readFinished"
    QString mangaNote; //!< Member variable "mangaNote"
};

#endif // READITEM_H
