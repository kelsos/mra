#include "XmlSaxParser.h"

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
	Publisher pub;
	wxString pubName;
	Genre gen;
	Author auth;
	Manga man;
	MangaGenre manGen;
	MangaAuthor manAuth;
	std::string coverString;
	DbWrapper* mdb;
};

/**TODO: Work on date parsing since I have issues and work out the
 * image cover data parsing.
 */

static void manga_parser_start_document(MangaParseState *state) {
	state->state = PARSER_START;
	state->auth.birthday.SetYear(1900);
	state->auth.birthday.SetMonth(wxDateTime::Jan);
	state->auth.birthday.SetDay(1);
	state->man.year.SetYear(1900);
	state->man.year.SetMonth(wxDateTime::Jan);
	state->man.year.SetDay(1);
}

static void manga_parser_end_document(MangaParseState *state) {
}

static void manga_parser_start_element(MangaParseState *state,
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

static void manga_parser_end_element(MangaParseState *state,
		const xmlChar *name) {
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
		state->mdb->insertPublisherData(new PublisherInfo(state->pub));
		state->pub.id = 0;
		state->pub.name = "\0";
		state->pub.country = "\0";
		state->pub.website = "\0";
		state->pub.note = "\0";
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
		state->mdb->insertGenreData(new GenreInfo(state->gen));
		state->gen.id = 0;
		state->gen.name = "\0";
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
		state->mdb->insertAuthorData(new AuthorInfo(state->auth));
		state->auth.id = 0;
		state->auth.name = "\0";
		state->auth.country = "\0";
		state->auth.website = "\0";
		state->auth.birthday.SetYear(1900);
		state->auth.birthday.SetMonth(wxDateTime::Jan);
		state->auth.birthday.SetDay(1);
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
		state->man.image = wxBase64Decode(state->coverString);
		wxLogDebug
			(_(state->coverString));
		state->mdb->insertMangaData(new MangaInfo(state->man));
		state->man.id = 0;
		state->man.pId = 0;
		state->man.description = "\0";
		state->man.status = "\0";
		state->man.title = "\0";
		state->coverString = "\0";
		state->man.year.SetYear(1900);
		state->man.year.SetMonth(wxDateTime::Jan);
		state->man.year.SetDay(1);
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
		state->mdb->insertMangaGenre(new MangaGenres(state->manGen));
		state->manGen.gId = 0;
		state->manGen.mId = 0;
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
		state->mdb->insertMangaAuthor(new MangaAuthors(state->manAuth));
		state->manAuth.aId = 0;
		state->manAuth.mId = 0;
		break;
	case PARSER_AT_END:
		break;
	}
}
static void manga_parser_characters(MangaParseState *state,
		const xmlChar *chars, int len) {
	int i;

	char output[len];
	wxDateTime dateData;

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
		state->pub.id = wxAtoi(output);
		break;
	case PARSER_IN_PUBLISHER_NAME:
		state->pub.name += wxString().FromUTF8(output);
		break;
	case PARSER_IN_PUBLISHER_COUNTRY:
		state->pub.country += wxString().FromUTF8(output);
		break;
	case PARSER_IN_PUBLISHER_WEBSITE:
		state->pub.website += wxString().FromUTF8(output);
		break;
	case PARSER_IN_PUBLISHER_NOTE:
		state->pub.note += wxString().FromUTF8(output);
		break;
	case PARSER_IN_GENRES:
	case PARSER_IN_GENRE:
		break;
	case PARSER_IN_GENRE_ID:
		state->gen.id = wxAtoi(output);
		break;
	case PARSER_IN_GENRE_NAME:
		state->gen.name += wxString().FromUTF8(output);
		break;
	case PARSER_IN_AUTHORS:
		break;
	case PARSER_IN_AUTHOR:
		break;
	case PARSER_IN_AUTHOR_ID:
		state->auth.id = wxAtoi(output);
		break;
	case PARSER_IN_AUTHOR_NAME:
		state->auth.name += wxString().FromUTF8(output);
		break;
	case PARSER_IN_AUTHOR_COUNTRY:
		state->auth.country += wxString().FromUTF8(output);
		break;
	case PARSER_IN_AUTHOR_BIRTH:
		dateData.ParseFormat(output,"%Y-%m-%dT%T");
		if (dateData.IsValid()) {
			state->auth.birthday = dateData;
		} else {
			state->auth.birthday.SetYear(1900);
			state->auth.birthday.SetMonth(wxDateTime::Jan);
			state->auth.birthday.SetDay(1);
		}
		wxLogDebug(state->auth.birthday.FormatDate());
		break;
	case PARSER_IN_AUTHOR_WEBSITE:
		state->auth.website += wxString().FromUTF8(output);
		break;
	case PARSER_IN_MANGAS:
		break;
	case PARSER_IN_MANGA:
		break;
	case PARSER_IN_MANGA_ID:
		state->man.id = wxAtoi(output);
		break;
	case PARSER_IN_MANGA_TITLE:
		state->man.title += wxString().FromUTF8(output);
		break;
	case PARSER_IN_MANGA_YEAR_OF_PUBLISH:
		dateData.ParseFormat(output,"%Y-%m-%dT%T");
		if (dateData.IsValid()) {
			state->man.year = dateData;
		} else {
			state->man.year.SetYear(1900);
			state->man.year.SetMonth(wxDateTime::Jan);
			state->man.year.SetDay(1);
		}
		wxLogDebug(dateData.FormatDate());
		wxLogDebug(state->man.year.FormatDate());
		break;
	case PARSER_IN_MANGA_STATUS:
		state->man.status += wxString().FromUTF8(output);
		;
		break;
	case PARSER_IN_MANGA_PUBLISHER_ID:
		state->man.pId = wxAtoi(output);
		break;
	case PARSER_IN_MANGA_DESCRIPTION:
		state->man.description += wxString().FromUTF8(output);
		;
		break;
	case PARSER_IN_MANGA_COVER:
		state->coverString += output;
		break;
	case PARSER_IN_MANGA_GENRES:
		break;
	case PARSER_IN_MANGA_GENRE:
		break;
	case PARSER_IN_MG_MANGA_ID:
		state->manGen.mId = wxAtoi(output);
		break;
	case PARSER_IN_MG_GENRE_ID:
		state->manGen.gId = wxAtoi(output);
		break;
	case PARSER_IN_MANGA_AUTHORS:
		break;
	case PARSER_IN_MANGA_AUTHOR:
		break;
	case PARSER_IN_MA_MANGA_ID:
		state->manAuth.mId = wxAtoi(output);
		break;
	case PARSER_IN_MA_AUTHOR_ID:
		state->manAuth.aId = wxAtoi(output);
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
(startDocumentSAXFunc) manga_parser_start_document, /* startDocument */
(endDocumentSAXFunc) manga_parser_end_document, /* endDocument */
(startElementSAXFunc) manga_parser_start_element, /* startElement */
(endElementSAXFunc) manga_parser_end_element, /* endElement */
0, /* reference */
(charactersSAXFunc) manga_parser_characters, /* characters */
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