#include <stdio.h>
#include <memory>
#include <libxml/parser.h>
#include <string>
#include "DbWrapper.h"
//Data classes included.
#include "AuthorInfo.h"
#include "GenreInfo.h"
#include "MangaAuthors.h"
#include "MangaGenres.h"
#include "MangaInfo.h"
#include "PublisherInfo.h"
#include "MangaGenres.h"
#include "MangaAuthors.h"

#ifndef XMLSAXPARSER_H_
#define XMLSAXPARSER_H_

void parseMangaData(const char* file,DbWrapper *db);

#endif /* XMLSAXPARSER_H_ */
