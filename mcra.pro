TEMPLATE = app
TARGET = mcra
QT += core \
    gui \
    sql \
    xml \
    xmlpatterns \
    network \
    webkit
HEADERS += src/DataClasses/AuthorInfo.h \
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
