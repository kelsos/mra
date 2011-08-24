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
	DbWrapper* db;
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
		break;
	case PARSER_AT_END:
		break;
	}
}

void parserAtCharacters(ReadingListParseState* state, const xmlChar *chars,
		int len) {
	int i;

	char output[len];
	wxDateTime dateData;

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
		state->read.setMangaTitle(wxString().FromUTF8(output));
		break;
	case PARSER_IN_MANGA_STARTING_CHAPTER:
		state->read.setStartingChapter(wxAtoi(output));
		break;
	case PARSER_IN_MANGA_CURRENT_CHAPTER:
		state->read.setCurrentChapter(wxAtoi(output));
		break;
	case PARSER_IN_MANGA_LAST_DATE:
		dateData.ParseFormat(output,"%Y-%m-%dT%T");
		if (dateData.IsValid()) {
			state->read.setLastRead(dateData);
		}
		break;
	case PARSER_IN_MANGA_ONLINE_URL:
		state->read.setOnlineUrl(wxString().FromUTF8(output));
		break;
	case PARSER_IN_MANGA_READING_STATUS:
		if (!strcmp(output, "true")){
		state->read.setReadFinished(true);
		} else if (!strcmp(output, "false")){
			state->read.setReadFinished(false);
		}
		else {
			state->read.setReadFinished(false);
		}
		break;
	case PARSER_IN_MANGA_NOTE:
//		state->read.se(wxString().FromUTF8(output));
		break;
	case PARSER_AT_END:
		break;
	}
}
