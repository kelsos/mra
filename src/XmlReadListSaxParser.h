#include <stdio.h>
#include <memory.h>
#include <libxml/parser.h>
#include <string>
#include <wx/wx.h>
#include "DbWrapper.h"
#include "ReadItem.h"

#ifndef XMLREADLISTSAXPARSER_H_
#define XMLREADLISTSAXPARSER_H_

void parseReadingList(const char* fileName, DbWrapper* db);

#endif /* XMLREADLISTSAXPARSER_H_ */
