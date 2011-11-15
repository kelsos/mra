#ifndef XMLREADLISTSAXPARSER_H_
#define XMLREADLISTSAXPARSER_H_
//Including external library header files.
#include <libxml/parser.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
//Including project headers.
#include "DbWrapper.h"
#include <ReadItem.h>

using namespace std;

void parseReadingList(const char* fileName, DbWrapper* db);

#endif /* XMLREADLISTSAXPARSER_H_ */
