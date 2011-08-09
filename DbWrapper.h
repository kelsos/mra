#ifndef DBWRAPPER_H
#define DBWRAPPER_H
//Include of the needed libraries.
#include <wx/wx.h>
#include <wx/wxsqlite3.h>
//Include of the needed data classes.
#include "AuthorInfo.h"
#include "GenreInfo.h"
#include "PublisherInfo.h"
#include "MangaInfo.h"
#include "NewsStorage.h"
#include "NewsSubscriptions.h"
#include "MangaAuthors.h"
#include "MangaGenres.h"
#include "ReadItem.h"

class DbWrapper
{
public:
    DbWrapper();
    virtual ~DbWrapper();
    bool isDatabaseConnectionActive();
    wxSQLite3ResultSet getUserReadingList();
    int getMangaID(wxString mangaTitle);
    void insertAuthorData(AuthorInfo author);
    void insertGenreData(GenreInfo genre);
    void insertPublisherData(PublisherInfo publisher);
    void insertMangaData(MangaInfo* manga);
    void insertMangaData2(unsigned int mangaId, wxString mangaName);
    void insertNewsItem(NewsStorage newsItem);
    void insertNewsSubscription(NewsSubscriptions subscription);
    void insertMangaAuthor(MangaAuthors maAuth);
    void insertMangaGenre(MangaGenres maGen);
    void insertReadingItem(ReadItem readItem);
    /** Returns the mangaInfo */
    void getMangaData();
protected:
private:
    wxSQLite3Database* mangaData;
    void createAuthorInfoTable();
    void createGenreInfoTable();
    void createPublisherInfoTable();
    void createMangaInfoTable();
    void createNewsStorageTable();
    void createNewsSubscriptionsTable();
    void createMangaAuthorsTable();
    void createMangaGenresTable();
    void createReadingListTable();
    void initDatabase();

};

#endif // DBWRAPPER_H
