#ifndef MANGAGENRES_H
#define MANGAGENRES_H


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
  unsigned int GetmangaId()
  {
    return mangaId;
  }
  /** Set mangaId
   * \param val New value to set
   */
  void SetmangaId(unsigned int val)
  {
    mangaId = val;
  }
  /** Access genreId
   * \return The current value of genreId
   */
  unsigned int GetgenreId()
  {
    return genreId;
  }
  /** Set genreId
   * \param val New value to set
   */
  void SetgenreId(unsigned int val)
  {
    genreId = val;
  }
protected:
private:
  unsigned int mangaId; //!< Member variable "mangaId"
  unsigned int genreId; //!< Member variable "genreId"
};

#endif // MANGAGENRES_H
