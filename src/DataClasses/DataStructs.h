#include <qstring>
#include <qdatetime>

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_

typedef struct _Publisher Publisher;
/** This struct defines a Publisher with the contained information
 *
 */
struct _Publisher
{
	unsigned int id;
	QString name;
	QString country;
	QString website;
	QString note;
};

typedef struct _Genre Genre;
/** This struct defines a Genre with the contained information
 *
 */
struct _Genre
{
	unsigned int id;
	QString name;
};

typedef struct _Author Author;

/** This struct defines an Author with the contained information
 *
 */
struct _Author
{
	unsigned int id;
	QString name;
	QString country;
	QDateTime birthday;
	QString website;
};

typedef struct _Manga Manga;

struct _Manga
{
	unsigned int id;
	QString title;
	QDateTime year;
	QString status;
	unsigned int pId;
	QString description;
	QByteArray image;
};

typedef struct _MangaGenre MangaGenre;

struct _MangaGenre
{
	unsigned int mId;
	unsigned int gId;
};

typedef struct _MangaAuthor MangaAuthor;

struct _MangaAuthor
{
	unsigned int mId;
	unsigned int aId;
};


#endif /* DATASTRUCTS_H_ */
