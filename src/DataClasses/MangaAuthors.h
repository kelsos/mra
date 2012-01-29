#ifndef MANGAAUTHORS_H
#define MANGAAUTHORS_H

#include <QString>
#include <QDateTime>

class MangaAuthors
{
public:
    /** Default constructor */
    MangaAuthors();
    MangaAuthors(unsigned int mangaId, unsigned int authorId);
    /** Default destructor */
    virtual ~MangaAuthors();
    /** Access mangaId
     * \return The current value of mangaId
     */
    unsigned int getMangaId()
    {
        return mangaId;
    }
    /** Set mangaId
     * \param val New value to set
     */
    void setMangaId(unsigned int val)
    {
        mangaId = val;
    }
    /** Access authorId
     * \return The current value of authorId
     */
    unsigned int getAuthorId()
    {
        return authorId;
    }
    /** Set authorId
     * \param val New value to set
     */
    void setAuthorId(unsigned int val)
    {
        authorId = val;
    }
    /** Nullifies current object values.
     *
     */
    void clear();
protected:
private:
    unsigned int mangaId; //!< Member variable "mangaId"
    unsigned int authorId; //!< Member variable "authorId"
};

#endif // MANGAAUTHORS_H
