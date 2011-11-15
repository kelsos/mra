#include "XmlDataSaxParser.h"

//States of the parser
typedef enum {
	PARSER_START,
	PARSER_IN_MANGADATA,
	PARSER_IN_PUBLISHERS,
	PARSER_IN_PUBLISHER,
	PARSER_IN_PUBLISHER_ID,
	PARSER_IN_PUBLISHER_NAME,
	PARSER_IN_PUBLISHER_COUNTRY,
	PARSER_IN_PUBLISHER_WEBSITE,
	PARSER_IN_PUBLISHER_NOTE,
	PARSER_IN_GENRES,
	PARSER_IN_GENRE,
	PARSER_IN_GENRE_ID,
	PARSER_IN_GENRE_NAME,
	PARSER_IN_AUTHORS,
	PARSER_IN_AUTHOR,
	PARSER_IN_AUTHOR_ID,
	PARSER_IN_AUTHOR_NAME,
	PARSER_IN_AUTHOR_COUNTRY,
	PARSER_IN_AUTHOR_BIRTH,
	PARSER_IN_AUTHOR_WEBSITE,
	PARSER_IN_MANGAS,
	PARSER_IN_MANGA,
	PARSER_IN_MANGA_ID,
	PARSER_IN_MANGA_TITLE,
	PARSER_IN_MANGA_YEAR_OF_PUBLISH,
	PARSER_IN_MANGA_STATUS,
	PARSER_IN_MANGA_PUBLISHER_ID,
	PARSER_IN_MANGA_DESCRIPTION,
	PARSER_IN_MANGA_COVER,
	PARSER_IN_MANGA_GENRES,
	PARSER_IN_MANGA_GENRE,
	PARSER_IN_MG_MANGA_ID,
	PARSER_IN_MG_GENRE_ID,
	PARSER_IN_MANGA_AUTHORS,
	PARSER_IN_MANGA_AUTHOR,
	PARSER_IN_MA_MANGA_ID,
	PARSER_IN_MA_AUTHOR_ID,
	PARSER_AT_END
} ParserState;

typedef struct _MangaParseState MangaParseState;
/*Describes the state of the parser, and also keeps info on the data parsed*/
struct _MangaParseState {
	ParserState state;
	PublisherInfo pub;
	QString pubName;
	GenreInfo gen;
	AuthorInfo auth;
	MangaInfo man;
	MangaGenres manGen;
	MangaAuthors manAuth;
	QString coverString;
	DbWrapper* mdb;
};

/**TODO: Work on date parsing since I have issues and work out the
 * image cover data parsing.
 */

static void startDocumentMangaParser(MangaParseState *state) {
	state->state = PARSER_START;
}

static void endDocumentMangaParser(MangaParseState *state) {
}

static void startElementMangaParser(MangaParseState *state,
		const xmlChar *name, xmlChar** attrs) {
	switch (state->state) {
	case PARSER_START:
		state->state = PARSER_IN_MANGADATA;
		break;
	case PARSER_IN_MANGADATA:
		state->state = PARSER_IN_PUBLISHERS;
		break;
	case PARSER_IN_PUBLISHERS:
		if (!strcmp((char*) name, "Publisher")) {
			state->state = PARSER_IN_PUBLISHER;
		} else {
			state->state = PARSER_IN_GENRES;
		}
		break;
	case PARSER_IN_PUBLISHER:
		if (!strcmp((char*) name, "PublisherID")) {
			state->state = PARSER_IN_PUBLISHER_ID;
		} else if (!strcmp((char*) name, "PublisherName")) {
			state->state = PARSER_IN_PUBLISHER_NAME;
		} else if (!strcmp((char*) name, "PublisherCountry")) {
			state->state = PARSER_IN_PUBLISHER_COUNTRY;
		} else if (!strcmp((char*) name, "PublisherWebsite")) {
			state->state = PARSER_IN_PUBLISHER_WEBSITE;
		} else if (!strcmp((char*) name, "PublisherNote")) {
			state->state = PARSER_IN_PUBLISHER_NOTE;
		}
		break;
	case PARSER_IN_PUBLISHER_ID:
		break;
	case PARSER_IN_PUBLISHER_NAME:
		break;
	case PARSER_IN_PUBLISHER_COUNTRY:
		break;
	case PARSER_IN_PUBLISHER_WEBSITE:
		break;
	case PARSER_IN_PUBLISHER_NOTE:
		break;
	case PARSER_IN_GENRES:
		if (!strcmp((char*) name, "Genre")) {
			state->state = PARSER_IN_GENRE;
		} else if (!strcmp((char*) name, "Authors")) {
			state->state = PARSER_IN_AUTHORS;
		}
		break;
	case PARSER_IN_GENRE:
		if (!strcmp((char*) name, "GenreID")) {
			state->state = PARSER_IN_GENRE_ID;
		} else if (!strcmp((char*) name, "GenreName")) {
			state->state = PARSER_IN_GENRE_NAME;
		}
		break;
	case PARSER_IN_GENRE_ID:
		break;
	case PARSER_IN_GENRE_NAME:
		break;
	case PARSER_IN_AUTHORS:
		if (!strcmp((char*) name, "Author")) {
			state->state = PARSER_IN_AUTHOR;
		} else if (!strcmp((char*) name, "Mangas")) {
			state->state = PARSER_IN_MANGAS;
		}
		break;
	case PARSER_IN_AUTHOR:
		if (!strcmp((char*) name, "AuthorID")) {
			state->state = PARSER_IN_AUTHOR_ID;
		} else if (!strcmp((char*) name, "AuthorName")) {
			state->state = PARSER_IN_AUTHOR_NAME;
		} else if (!strcmp((char*) name, "AuthorCountry")) {
			state->state = PARSER_IN_AUTHOR_COUNTRY;
		} else if (!strcmp((char*) name, "AuthorBirth")) {
			state->state = PARSER_IN_AUTHOR_BIRTH;
		} else if (!strcmp((char*) name, "AuthorWebsite")) {
			state->state = PARSER_IN_AUTHOR_WEBSITE;
		}
		break;
	case PARSER_IN_AUTHOR_ID:
		break;
	case PARSER_IN_AUTHOR_NAME:
		break;
	case PARSER_IN_AUTHOR_COUNTRY:
		break;
	case PARSER_IN_AUTHOR_BIRTH:
		break;
	case PARSER_IN_AUTHOR_WEBSITE:
		break;
	case PARSER_IN_MANGAS:
		if (!strcmp((char*) name, "Manga")) {
			state->state = PARSER_IN_MANGA;
		} else if (!strcmp((char*) name, "MangaGenres")) {
			state->state = PARSER_IN_MANGA_GENRES;
		}
		break;
	case PARSER_IN_MANGA:
		if (!strcmp((char*) name, "MangaID")) {
			state->state = PARSER_IN_MANGA_ID;
		} else if (!strcmp((char*) name, "MangaTitle")) {
			state->state = PARSER_IN_MANGA_TITLE;
		} else if (!strcmp((char*) name, "MangaYearOfPublish")) {
			state->state = PARSER_IN_MANGA_YEAR_OF_PUBLISH;
		} else if (!strcmp((char*) name, "MangaStatus")) {
			state->state = PARSER_IN_MANGA_STATUS;
		} else if (!strcmp((char*) name, "MangaPublisherID")) {
			state->state = PARSER_IN_MANGA_PUBLISHER_ID;
		} else if (!strcmp((char*) name, "MangaDescription")) {
			state->state = PARSER_IN_MANGA_DESCRIPTION;
		} else if (!strcmp((char*) name, "MangaCover")) {
			state->state = PARSER_IN_MANGA_COVER;
		}
		break;
	case PARSER_IN_MANGA_ID:
		break;
	case PARSER_IN_MANGA_TITLE:
		break;
	case PARSER_IN_MANGA_YEAR_OF_PUBLISH:
		break;
	case PARSER_IN_MANGA_STATUS:
		break;
	case PARSER_IN_MANGA_PUBLISHER_ID:
		break;
	case PARSER_IN_MANGA_DESCRIPTION:
		break;
	case PARSER_IN_MANGA_COVER:
		break;
	case PARSER_IN_MANGA_GENRES:
		if (!strcmp((char*) name, "MangaGenre")) {
			state->state = PARSER_IN_MANGA_GENRE;
		} else if (!strcmp((char*) name, "MangaAuthors")) {
			state->state = PARSER_IN_MANGA_AUTHORS;
		}
		break;
	case PARSER_IN_MANGA_GENRE:
		if (!strcmp((char*) name, "MangaID")) {
			state->state = PARSER_IN_MG_MANGA_ID;
		} else if (!strcmp((char*) name, "GenreID")) {
			state->state = PARSER_IN_MG_GENRE_ID;
		}
		break;
	case PARSER_IN_MG_MANGA_ID:
		break;
	case PARSER_IN_MG_GENRE_ID:
		break;
	case PARSER_IN_MANGA_AUTHORS:
		if (!strcmp((char*) name, "MangaAuthor")) {
			state->state = PARSER_IN_MANGA_AUTHOR;
		} else if (!strcmp((char*) name, "MangaDatabase")) {
			state->state = PARSER_AT_END;
		}
		break;
	case PARSER_IN_MANGA_AUTHOR:
		if (!strcmp((char*) name, "MangaID")) {
			state->state = PARSER_IN_MA_MANGA_ID;
		} else if (!strcmp((char*) name, "AuthorID")) {
			state->state = PARSER_IN_MA_AUTHOR_ID;
		}
		break;
	case PARSER_IN_MA_MANGA_ID:
		break;
	case PARSER_IN_MA_AUTHOR_ID:
		break;
	case PARSER_AT_END:
		break;
	}
}

static void endElementMangaParser(MangaParseState *state,
		const xmlChar *name) {
	QByteArray ba;
	switch (state->state) {
	case PARSER_START:
		break;
	case PARSER_IN_MANGADATA:
		break;
	case PARSER_IN_PUBLISHERS:
		break;
	case PARSER_IN_PUBLISHER:
		break;
	case PARSER_IN_PUBLISHER_ID:
		state->state = PARSER_IN_PUBLISHER;
		break;
	case PARSER_IN_PUBLISHER_NAME:
		state->state = PARSER_IN_PUBLISHER;
		break;
	case PARSER_IN_PUBLISHER_COUNTRY:
		state->state = PARSER_IN_PUBLISHER;
		break;
	case PARSER_IN_PUBLISHER_WEBSITE:
		state->state = PARSER_IN_PUBLISHER;
		break;
	case PARSER_IN_PUBLISHER_NOTE:
		state->state = PARSER_IN_PUBLISHERS;
		state->mdb->insertPublisherData(&state->pub);
		state->pub.clear();
		break;
	case PARSER_IN_GENRES:
		break;
	case PARSER_IN_GENRE:
		break;
	case PARSER_IN_GENRE_ID:
		state->state = PARSER_IN_GENRE;
		break;
	case PARSER_IN_GENRE_NAME:
		state->state = PARSER_IN_GENRES;
		state->mdb->insertGenreData(&state->gen);
		state->gen.clear();
		break;
	case PARSER_IN_AUTHORS:
		break;
	case PARSER_IN_AUTHOR:
		break;
	case PARSER_IN_AUTHOR_ID:
		state->state = PARSER_IN_AUTHOR;
		break;
	case PARSER_IN_AUTHOR_NAME:
		state->state = PARSER_IN_AUTHOR;
		break;
	case PARSER_IN_AUTHOR_COUNTRY:
		state->state = PARSER_IN_AUTHOR;
		break;
	case PARSER_IN_AUTHOR_BIRTH:
		state->state = PARSER_IN_AUTHOR;
		break;
	case PARSER_IN_AUTHOR_WEBSITE:
		state->state = PARSER_IN_AUTHORS;
		state->mdb->insertAuthorData(&state->auth);
		state->auth.clear();
		break;
	case PARSER_IN_MANGAS:
		break;
	case PARSER_IN_MANGA:
		break;
	case PARSER_IN_MANGA_ID:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_TITLE:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_YEAR_OF_PUBLISH:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_STATUS:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_PUBLISHER_ID:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_DESCRIPTION:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_COVER:
		state->state = PARSER_IN_MANGAS;
		ba.append(state->coverString);
		state->man.setMangaCover(QByteArray::fromBase64(ba));
		state->mdb->insertMangaData(&state->man);
		state->man.clear();
		state->coverString = "\0";
		break;
	case PARSER_IN_MANGA_GENRES:
		break;
	case PARSER_IN_MANGA_GENRE:
		break;
	case PARSER_IN_MG_MANGA_ID:
		state->state = PARSER_IN_MANGA_GENRE;
		break;
	case PARSER_IN_MG_GENRE_ID:
		state->state = PARSER_IN_MANGA_GENRES;
		state->mdb->insertMangaGenre(&state->manGen);
		state->manGen.clear();
		break;
	case PARSER_IN_MANGA_AUTHORS:
		break;
	case PARSER_IN_MANGA_AUTHOR:
		break;
	case PARSER_IN_MA_MANGA_ID:
		state->state = PARSER_IN_MANGA_AUTHOR;
		break;
	case PARSER_IN_MA_AUTHOR_ID:
		state->state = PARSER_IN_MANGA_AUTHORS;
		state->mdb->insertMangaAuthor(&state->manAuth);
		state->manAuth.clear();
		break;
	case PARSER_AT_END:
		break;
	}
}
static void charactersMangaParser(MangaParseState *state,
		const xmlChar *chars, int len) {
	int i;

	char output[len];
	QDateTime dateData;

	for (i = 0; i < len; i++) {
		output[i] = chars[i];
	}
	output[i] = 0;

	switch (state->state) {
	case PARSER_START:
		break;
	case PARSER_IN_MANGADATA:
		break;
	case PARSER_IN_PUBLISHERS:
		break;
	case PARSER_IN_PUBLISHER:
		break;
	case PARSER_IN_PUBLISHER_ID:
		state->pub.setPublisherId((unsigned int)atoi(output));
		break;
	case PARSER_IN_PUBLISHER_NAME:
		state->pub.setPublisherName(QString::fromUtf8(output));
		break;
	case PARSER_IN_PUBLISHER_COUNTRY:
		state->pub.setPublisherCountry(QString::fromUtf8(output));
		break;
	case PARSER_IN_PUBLISHER_WEBSITE:
		state->pub.setPublisherWebsite(QString::fromUtf8(output));
		break;
	case PARSER_IN_PUBLISHER_NOTE:
		state->pub.setPublisherNote(QString::fromUtf8(output));
		break;
	case PARSER_IN_GENRES:
	case PARSER_IN_GENRE:
		break;
	case PARSER_IN_GENRE_ID:
		state->gen.setGenreId((unsigned int)atoi(output));
		break;
	case PARSER_IN_GENRE_NAME:
		state->gen.setGenreName(QString::fromUtf8(output));
		break;
	case PARSER_IN_AUTHORS:
		break;
	case PARSER_IN_AUTHOR:
		break;
	case PARSER_IN_AUTHOR_ID:
		state->auth.setAuthorId((unsigned int)atoi(output));
		break;
	case PARSER_IN_AUTHOR_NAME:
		state->auth.setAuthorName(QString::fromUtf8(output));
		break;
	case PARSER_IN_AUTHOR_COUNTRY:
		state->auth.setAuthorNationality(QString::fromUtf8(output));
		break;
	case PARSER_IN_AUTHOR_BIRTH:
		dateData.fromString(output, Qt::ISODate);
		state->auth.setAuthorBirthday(dateData);
		break;
	case PARSER_IN_AUTHOR_WEBSITE:
		state->auth.setAuthorWebsite(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGAS:
		break;
	case PARSER_IN_MANGA:
		break;
	case PARSER_IN_MANGA_ID:
		state->man.setMangaId((unsigned int)atoi(output));
		break;
	case PARSER_IN_MANGA_TITLE:
		state->man.setMangaTitle(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGA_YEAR_OF_PUBLISH:
		dateData.fromString(output, Qt::ISODate);
		state->man.setMangaPublicationDate(dateData);
		break;
	case PARSER_IN_MANGA_STATUS:
		state->man.setMangaPublicationStatus(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGA_PUBLISHER_ID:
		state->man.setMangaPublisherId((unsigned int)atoi(output));
		break;
	case PARSER_IN_MANGA_DESCRIPTION:
		state->man.setMangaDescription(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGA_COVER:
		state->coverString += output;
		break;
	case PARSER_IN_MANGA_GENRES:
		break;
	case PARSER_IN_MANGA_GENRE:
		break;
	case PARSER_IN_MG_MANGA_ID:
		state->manGen.setMangaId((unsigned int)atoi(output));
		break;
	case PARSER_IN_MG_GENRE_ID:
		state->manGen.setGenreId((unsigned int)atoi(output));
		break;
	case PARSER_IN_MANGA_AUTHORS:
		break;
	case PARSER_IN_MANGA_AUTHOR:
		break;
	case PARSER_IN_MA_MANGA_ID:
		state->manAuth.setMangaId((unsigned int)atoi(output));
		break;
	case PARSER_IN_MA_AUTHOR_ID:
		state->manAuth.setAuthorId((unsigned int)atoi(output));
		break;
	case PARSER_AT_END:
		break;
	}
}

static xmlSAXHandler manga_parser = { 0, /* internalSubset */
0, /* isStandalone */
0, /* hasInternalSubset */
0, /* hasExternalSubset */
0, /* resolveEntity */
0, /* getEntity */
0, /* entityDecl */
0, /* notationDecl */
0, /* attributeDecl */
0, /* elementDecl */
0, /* unparsedEntityDecl */
0, /* setDocumentLocator */
(startDocumentSAXFunc) startDocumentMangaParser, /* startDocument */
(endDocumentSAXFunc) endDocumentMangaParser, /* endDocument */
(startElementSAXFunc) startElementMangaParser, /* startElement */
(endElementSAXFunc) endElementMangaParser, /* endElement */
0, /* reference */
(charactersSAXFunc) charactersMangaParser, /* characters */
0, /* ignorableWhitespace */
0, /* processingInstruction */
(commentSAXFunc) 0, /* comment */
0, /*warning */
0, /* error */
0 /* fatalError */
};

void parseMangaData(const char* file, DbWrapper *db) {
	MangaParseState state = { };
	state.mdb = db;

	if (xmlSAXUserParseFile(&manga_parser, &state, file) < 0) {
		fprintf(stdout, "document not well formed");
	}
	return;
}
