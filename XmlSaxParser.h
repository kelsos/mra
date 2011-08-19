#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <string>
#include <wx/wx.h>
#include <wx/base64.h>
#include "DbWrapper.h"
#include "DataStructs.h"
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

void manga_parser_parse_file(const char* file,DbWrapper *db);

#endif /* XMLSAXPARSER_H_ */
