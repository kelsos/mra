#include "XmlReadListSaxParser.h"

typedef enum {
	PARSER_AT_START,
	PARSER_IN_MANGAREADINGLIST,
	PARSER_IN_MANGA,
	PARSER_IN_MANGA_TITLE,
	PARSER_IN_MANGA_STARTING_CHAPTER,
	PARSER_IN_MANGA_CURRENT_CHAPTER,
	PARSER_IN_MANGA_LAST_DATE,
	PARSER_IN_MANGA_ONLINE_URL,
	PARSER_IN_MANGA_READING_STATUS,
	PARSER_IN_MANGA_NOTE,
	PARSER_AT_END
} ParserState;

typedef struct _ReadingListParseState ReadingListParseState;
/*Describes the state of the parser, and also keeps info on the data parsed*/
struct _ReadingListParseState {
	ParserState state;
	ReadItem read;
	DbWrapper* mdb;
};

void parserAtDocumentStart(ReadingListParseState* state) {
	state->state = PARSER_AT_START;
}

void parserAtDocumentEnd(ReadingListParseState* state) {

}

void parserAtElementStart(ReadingListParseState* state, xmlChar* name,
		xmlChar** attrs) {
	switch (state->state) {
	case PARSER_AT_START:
		state->state = PARSER_IN_MANGAREADINGLIST;
		break;
	case PARSER_IN_MANGAREADINGLIST:
		if (!strcmp((char*) name, "manga")) {
			state->state = PARSER_IN_MANGA;
		} else {
			state->state = PARSER_AT_END;
		}
		break;
	case PARSER_IN_MANGA:
		if (!strcmp((char*) name, "Title")) {
			state->state = PARSER_IN_MANGA_TITLE;
		} else if (!strcmp((char*) name, "startingChapter")) {
			state->state = PARSER_IN_MANGA_STARTING_CHAPTER;
		} else if (!strcmp((char*) name, "currentChapter")) {
			state->state = PARSER_IN_MANGA_CURRENT_CHAPTER;
		} else if (!strcmp((char*) name, "dateRead")) {
			state->state = PARSER_IN_MANGA_LAST_DATE;
		} else if (!strcmp((char*) name, "onlineURL")) {
			state->state = PARSER_IN_MANGA_ONLINE_URL;
		} else if (!strcmp((char*) name, "finishedReading")) {
			state->state = PARSER_IN_MANGA_READING_STATUS;
		} else if (!strcmp((char*) name, "mangaNote")) {
			state->state = PARSER_IN_MANGA_NOTE;
		}
		break;
	case PARSER_IN_MANGA_TITLE:
		break;
	case PARSER_IN_MANGA_STARTING_CHAPTER:
		break;
	case PARSER_IN_MANGA_CURRENT_CHAPTER:
		break;
	case PARSER_IN_MANGA_LAST_DATE:
		break;
	case PARSER_IN_MANGA_ONLINE_URL:
		break;
	case PARSER_IN_MANGA_READING_STATUS:
		break;
	case PARSER_IN_MANGA_NOTE:
		break;
	case PARSER_AT_END:
		break;
	}
}

void parserAtElementEnd(ReadingListParseState* state, xmlChar* name) {
	switch (state->state) {
	case PARSER_AT_START:
		break;
	case PARSER_IN_MANGAREADINGLIST:
		break;
	case PARSER_IN_MANGA:
		break;
	case PARSER_IN_MANGA_TITLE:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_STARTING_CHAPTER:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_CURRENT_CHAPTER:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_LAST_DATE:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_ONLINE_URL:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_READING_STATUS:
		state->state = PARSER_IN_MANGA;
		break;
	case PARSER_IN_MANGA_NOTE:
		state->state = PARSER_IN_MANGAREADINGLIST;
		state->mdb->insertReadItem(&state->read);
		break;
	case PARSER_AT_END:
		break;
	}
}

void parserAtCharacters(ReadingListParseState* state, const xmlChar *chars,
		int len) {
	int i;

	char output[len];
	QDateTime dateData;

	for (i = 0; i < len; i++) {
		output[i] = chars[i];
	}
	output[i] = 0;
	switch (state->state) {
	case PARSER_AT_START:
		break;
	case PARSER_IN_MANGAREADINGLIST:
		break;
	case PARSER_IN_MANGA:
		break;
	case PARSER_IN_MANGA_TITLE:
		state->read.setMangaTitle(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGA_STARTING_CHAPTER:
		state->read.setStartingChapter((unsigned int)atoi(output));
		break;
	case PARSER_IN_MANGA_CURRENT_CHAPTER:
		state->read.setCurrentChapter((unsigned int)atoi(output));
		break;
	case PARSER_IN_MANGA_LAST_DATE:
		dateData.fromString(output, "yyyy-MM-ddTHH:mm:ss");
		state->read.setLastRead(dateData);
		break;
	case PARSER_IN_MANGA_ONLINE_URL:
		state->read.setOnlineUrl(QString::fromUtf8(output));
		break;
	case PARSER_IN_MANGA_READING_STATUS:
		if (!strcmp(output, "true")) {
			state->read.setReadFinished(true);
		} else if (!strcmp(output, "false")) {
			state->read.setReadFinished(false);
		} else {
			state->read.setReadFinished(false);
		}
		break;
	case PARSER_IN_MANGA_NOTE:
		state->read.appendMangaNote(QString::fromUtf8(output));
		break;
	case PARSER_AT_END:
		break;
	}
}

static xmlSAXHandler readingListParser = { 0, /* internalSubset */
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
(startDocumentSAXFunc) parserAtDocumentStart, /* startDocument */
(endDocumentSAXFunc) parserAtDocumentEnd, /* endDocument */
(startElementSAXFunc) parserAtElementStart, /* startElement */
(endElementSAXFunc) parserAtElementEnd, /* endElement */
0, /* reference */
(charactersSAXFunc) parserAtCharacters, /* characters */
0, /* ignorableWhitespace */
0, /* processingInstruction */
(commentSAXFunc) 0, /* comment */
0, /*warning */
0, /* error */
0 /* fatalError */
};

void parseReadingList(const char* fileName, DbWrapper* db)
{

	ReadingListParseState state = { };
	state.mdb = db;

	if (xmlSAXUserParseFile(&readingListParser, &state, fileName) < 0) {
		fprintf(stdout, "document not well formed");
	}
	return;
}
