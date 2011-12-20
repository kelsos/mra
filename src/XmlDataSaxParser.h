#ifndef XMLDATASAXPARSER_H_
#define XMLDATASAXPARSER_H_

#include <qdebug.h>
#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <string.h>
#include "DbWrapper.h"
//Data classes included.
#include "AuthorInfo.h"
#include "GenreInfo.h"
#include "MangaAuthors.h"
#include "MangaGenres.h"
#include "MangaInfo.h"
#include "PublisherInfo.h"

using namespace std;

void parseMangaData(const char* file,DbWrapper *db);

#endif /* XMLDATASAXPARSER_H_ */
