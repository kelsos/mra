TEMPLATE = app
TARGET = mcra
QT += core \
    gui \
    sql \
    xml \
    xmlpatterns \
    network \
    webkit
HEADERS += lib/includes/libxml2/libxml/DOCBparser.h \
    lib/includes/libxml2/libxml/HTMLparser.h \
    lib/includes/libxml2/libxml/HTMLtree.h \
    lib/includes/libxml2/libxml/SAX.h \
    lib/includes/libxml2/libxml/SAX2.h \
    lib/includes/libxml2/libxml/c14n.h \
    lib/includes/libxml2/libxml/catalog.h \
    lib/includes/libxml2/libxml/chvalid.h \
    lib/includes/libxml2/libxml/debugXML.h \
    lib/includes/libxml2/libxml/dict.h \
    lib/includes/libxml2/libxml/encoding.h \
    lib/includes/libxml2/libxml/entities.h \
    lib/includes/libxml2/libxml/globals.h \
    lib/includes/libxml2/libxml/hash.h \
    lib/includes/libxml2/libxml/list.h \
    lib/includes/libxml2/libxml/nanoftp.h \
    lib/includes/libxml2/libxml/nanohttp.h \
    lib/includes/libxml2/libxml/parser.h \
    lib/includes/libxml2/libxml/parserInternals.h \
    lib/includes/libxml2/libxml/pattern.h \
    lib/includes/libxml2/libxml/relaxng.h \
    lib/includes/libxml2/libxml/schemasInternals.h \
    lib/includes/libxml2/libxml/schematron.h \
    lib/includes/libxml2/libxml/threads.h \
    lib/includes/libxml2/libxml/tree.h \
    lib/includes/libxml2/libxml/uri.h \
    lib/includes/libxml2/libxml/valid.h \
    lib/includes/libxml2/libxml/xinclude.h \
    lib/includes/libxml2/libxml/xlink.h \
    lib/includes/libxml2/libxml/xmlIO.h \
    lib/includes/libxml2/libxml/xmlautomata.h \
    lib/includes/libxml2/libxml/xmlerror.h \
    lib/includes/libxml2/libxml/xmlexports.h \
    lib/includes/libxml2/libxml/xmlmemory.h \
    lib/includes/libxml2/libxml/xmlmodule.h \
    lib/includes/libxml2/libxml/xmlreader.h \
    lib/includes/libxml2/libxml/xmlregexp.h \
    lib/includes/libxml2/libxml/xmlsave.h \
    lib/includes/libxml2/libxml/xmlschemas.h \
    lib/includes/libxml2/libxml/xmlschemastypes.h \
    lib/includes/libxml2/libxml/xmlstring.h \
    lib/includes/libxml2/libxml/xmlunicode.h \
    lib/includes/libxml2/libxml/xmlversion.h \
    lib/includes/libxml2/libxml/xmlwriter.h \
    lib/includes/libxml2/libxml/xpath.h \
    lib/includes/libxml2/libxml/xpathInternals.h \
    lib/includes/libxml2/libxml/xpointer.h \
    src/DataClasses/AuthorInfo.h \
    src/DataClasses/DataStructs.h \
    src/DataClasses/GenreInfo.h \
    src/DataClasses/MangaAuthors.h \
    src/DataClasses/MangaGenres.h \
    src/DataClasses/MangaInfo.h \
    src/DataClasses/NewsStorage.h \
    src/DataClasses/NewsSubscriptions.h \
    src/DataClasses/PublisherInfo.h \
    src/DataClasses/ReadItem.h \
    src/DbWrapper.h \
    src/XmlReadListSaxParser.h \
    src/XmlSaxParser.h \
    src/XmlWrapper.h \
    src/mcra.h \
    src/version.h
SOURCES += src/DataClasses/AuthorInfo.cpp \
    src/DataClasses/GenreInfo.cpp \
    src/DataClasses/MangaAuthors.cpp \
    src/DataClasses/MangaGenres.cpp \
    src/DataClasses/MangaInfo.cpp \
    src/DataClasses/NewsStorage.cpp \
    src/DataClasses/NewsSubscriptions.cpp \
    src/DataClasses/PublisherInfo.cpp \
    src/DataClasses/ReadItem.cpp \
    src/DbWrapper.cpp \
    src/XmlReadListSaxParser.cpp \
    src/XmlSaxParser.cpp \
    src/XmlWrapper.cpp \
    src/main.cpp \
    src/mcra.cpp \
    src/main.cpp
FORMS += src/mcra.ui
RESOURCES += 
Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui
