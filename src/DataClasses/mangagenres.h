#ifndef MANGAGENRES_H
#define MANGAGENRES_H

#include <QString>
#include <QDateTime>

class MangaGenres
{
public:
    /** Default constructor */
    MangaGenres();
    MangaGenres(unsigned int mangaId, unsigned int genreId);
    /** Default destructor */
    virtual ~MangaGenres();
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
    /** Access genreId
     * \return The current value of genreId
     */
    unsigned int getGenreId()
    {
        return genreId;
    }
    /** Set genreId
     * \param val New value to set
     */
    void setGenreId(unsigned int val)
    {
        genreId = val;
    }
    /** Nullifies current object values.
     *
     */
    void clear();
protected:
private:
    unsigned int mangaId; //!< Member variable "mangaId"
    unsigned int genreId; //!< Member variable "genreId"
};

#endif // MANGAGENRES_H
