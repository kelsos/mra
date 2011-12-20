TEMPLATE = vcapp
TARGET = mcra
QT += core \
    gui \
    sql \
    xml \
    xmlpatterns \
    network \
    webkit
HEADERS += src/XmlDataSaxParser.h \
    src/DataClasses/AuthorInfo.h \
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
    src/XmlWrapper.h \
    src/mcra.h \
    src/version.h
SOURCES += src/XmlDataSaxParser.cpp \
    src/DataClasses/AuthorInfo.cpp \
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
    src/XmlWrapper.cpp \
    src/main.cpp \
    src/mcra.cpp
FORMS += src/mcra.ui
RESOURCES += 
Debug:DESTDIR = debug
Debug:OBJECTS_DIR = debug/.obj
Debug:MOC_DIR = debug/.moc
Debug:RCC_DIR = debug/.rcc
Debug:UI_DIR = debug/.ui
Release:DESTDIR = release
Release:OBJECTS_DIR = release/.obj
Release:MOC_DIR = release/.moc
Release:RCC_DIR = release/.rcc
Release:UI_DIR = release/.ui
INCLUDEPATH = lib/libxml2-2.7.8.win32/include \
	lib/iconv-1.9.2.win32/include \
    src \
    src/DataClasses \
    lib/includes 
win32:LIBS += -Llib/libxml2-2.7.8.win32/lib \
    -llibxml2_a_dll.lib \
	-Llib/iconv-1.9.2.win32/lib \
	-liconv_a.lib \
    -LC:/Qt/4.8.0/plugins/sqldrivers \
    -lqsqlited4 
