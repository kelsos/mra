#ifndef MANGAAUTHORS_H
#define MANGAAUTHORS_H


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
  /** Access authorId
           * \return The current value of authorId
           */
  unsigned int GetauthorId()
  {
    return authorId;
  }
  /** Set authorId
   * \param val New value to set
   */
  void SetauthorId(unsigned int val)
  {
    authorId = val;
  }

protected:
private:
  unsigned int mangaId; //!< Member variable "mangaId"
  unsigned int authorId; //!< Member variable "authorId"
};

#endif // MANGAAUTHORS_H
