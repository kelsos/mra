#ifndef DBWRAPPER_H
#define DBWRAPPER_H
//Include of the needed libraries.
#include <wx/wx.h>
#include <wx/wxsqlite3.h>
#include <wx/file.h>
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
#include "DataGrid.h"

/**Class DbWrapper is the application layer responsible for the transactions with the SQLite3 database.
 *
 */
class DbWrapper {
public:
	DbWrapper();
	virtual ~DbWrapper();
	/**Checks if there is an active connection to the database
	 *
	 * @return
	 */
	bool isDatabaseConnectionActive();
	/** Gets the User's reading List
	 *
	 * @return
	 */
	void getUserReadingList(DataGrid* grid);
	/**Inserts an entry representing an author to the database.
	 *
	 * @param author
	 */
	void insertAuthorData(AuthorInfo* author);
	/**Inserts an entry representing a Genre to the database.
	 *
	 * @param genre
	 */
	void insertGenreData(GenreInfo* genre);
	/**Inserts an entry representing a Publisher to the database.
	 *
	 * @param publisher
	 */
	void insertPublisherData(PublisherInfo* publisher);
	/**Inserts an entry representing a Manga to the database.
	 *
	 * @param manga
	 */
	void insertMangaData(MangaInfo* manga);
	/**Inserts an entry representing a NewsItem to the database.
	 *
	 * @param newsItem
	 */
	void insertNewsItem(NewsStorage* newsItem);
	/**Inserts an entry representing an Rss subscription to the database.
	 *
	 * @param subscription
	 */
	void insertNewsSubscription(NewsSubscriptions* subscription);
	/**Inserts an entry representing a Manga Author to the database.
	 *
	 * @param maAuth
	 */
	void insertMangaAuthor(MangaAuthors* maAuth);
	/**Inserts an entry representing a Manga Genre to the database.
	 *
	 * @param maGen
	 */
	void insertMangaGenre(MangaGenres* maGen);
	/**Inserts an entry representing a Read Item to the database.
	 *
	 * @param readItem
	 */
	void insertReadItem(ReadItem* readItem);
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
	int getMangaID(wxString mangaTitle);
	/**Given the manga ID number the method returns the manga title.
	 *
	 * @param mangaId
	 * @return Manga Title
	 */
	wxString getMangaTitle(int mangaId);

};

#endif // DBWRAPPER_H
