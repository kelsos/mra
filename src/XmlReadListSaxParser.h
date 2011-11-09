#ifndef XMLREADLISTSAXPARSER_H_
#define XMLREADLISTSAXPARSER_H_

#include <stdio.h>
#include <memory>
#include <string>
#include "DbWrapper.h"
#include <libxml/parser.h>
#include <ReadItem.h>
void parseReadingList(const char* fileName, DbWrapper* db);

#endif /* XMLREADLISTSAXPARSER_H_ */
