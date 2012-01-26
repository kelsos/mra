#ifndef DBWRAPPER_H
#define DBWRAPPER_H
//Include of the needed libraries.
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QGraphicsItem>
#include <QObject>
#include <QtDebug>
///Include of the needed data classes.
#include "mangaSqlQueryModel.h"
#include "DataClasses/AuthorInfo.h"
#include "DataClasses/GenreInfo.h"
#include "DataClasses/PublisherInfo.h"
#include "DataClasses/MangaInfo.h"
#include "DataClasses/NewsStorage.h"
#include "DataClasses/NewsSubscriptions.h"
#include "DataClasses/MangaAuthors.h"
#include "DataClasses/MangaGenres.h"
#include "DataClasses/ReadItem.h"

/**Class DbWrapper is the application layer responsible for the transactions with the SQLite3 database.
 *
 */
class DbWrapper{
public:
	DbWrapper();
	virtual ~DbWrapper();
	/**Checks if there is an active connection to the database
	 *
	 * @return
	 */
    bool isDatabaseOpen();
	/** Gets the User's reading List
	 *
	 * @return
	 */
	MangaSqlQueryModel* getUserReadingList(bool displayFinished);
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
	void clearDatabase();
	void truncateAuthorInfoTable();
	void truncateGenreInfoTable();
	void truncatePublisherInfoTable();
	void truncateMangaInfoTable();
	void truncateNewsStorageTable();
	void truncateNewsSubscriptionsTable();
	void truncateMangaAuthorsTable();
	void truncateMangaGenresTable();
	void truncateReadingListTable();
	QPixmap getMangaCover(QString mangaTitle);
	QString getMangaDescription(QString mangaTitle);
	QString getMangaNote(QString mangaTitle);
	QString getMangaUrl(QString mangaTitle);
protected:
private:
	QSqlDatabase mangaData;
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
	int getMangaID(QString mangaTitle);
	/**Given the manga ID number the method returns the manga title.
	 *
	 * @param mangaId
	 * @return Manga Title
	 */
	QString getMangaTitle(int mangaId);

};

#endif // DBWRAPPER_H
