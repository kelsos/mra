#include <wx/wx.h>
#include <string>

#ifndef DATASTRUCTS_H_
#define DATASTRUCTS_H_

typedef struct _Publisher Publisher;
/** This struct defines a Publisher with the contained information
 *
 */
struct _Publisher
{
	unsigned int id;
	wxString name;
	wxString country;
	wxString website;
	wxString note;
};

typedef struct _Genre Genre;
/** This struct defines a Genre with the contained information
 *
 */
struct _Genre
{
	unsigned int id;
	wxString name;
};

typedef struct _Author Author;

/** This struct defines an Author with the contained information
 *
 */
struct _Author
{
	unsigned int id;
	wxString name;
	wxString country;
	wxDateTime birthday;
	wxString website;
};

typedef struct _Manga Manga;

struct _Manga
{
	unsigned int id;
	wxString title;
	wxDateTime year;
	wxString status;
	unsigned int pId;
	wxString description;
	wxMemoryBuffer image;
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
