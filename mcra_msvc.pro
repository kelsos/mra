# ----------------------------------------------------
# Project: MCRA
# ------------------------------------------------------

TEMPLATE = app
TARGET = mcra_msvc
DESTDIR = ./debug
QT += core gui sql network xml xmlpatterns webkit
CONFIG += debug
DEFINES += _WINDOWS QT_DLL QT_WEBKIT_LIB QT_SQL_LIB QT_XMLPATTERNS_LIB QT_XML_LIB QT_NETWORK_LIB QT_HAVE_MMX QT_HAVE_SSE QT_HAVE_MMXEXT QT_HAVE_SSE2
INCLUDEPATH += src \
    src/DataClasses \
    ./debug/.moc \
    ./debug/.ui \
    ./GeneratedFiles
win32{
    LIBS += -lC:/Tools/Qt/4.8.1/plugins/sqldrivers/qsqlited4
    DEFINES += QT_LARGEFILE_SUPPORT
    INCLUDEPATH += $(QTDIR)/mkspecs/win32-msvc2010
}

unix:!macx{
    LIBS += -L/usr/lib/x86_64-linux-gnu/qt4/plugins/sqldrivers/ -lqsqlite
}

DEPENDPATH += .
MOC_DIR += debug/.moc
OBJECTS_DIR += debug/.obj
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += src/databaseeditor.h \
    src/genresinfoeditor.h \
    src/version.h \
    src/mcra.h \
    src/databaseeditor.h \
    src/webBrowser.h \
    src/genresinfoeditor.h \
    src/Data/databasemanager.h \
    src/Data/databasecreator.h \
    src/Data/databaseeraser.h \
    src/Data/dataimporter.h \
    src/Data/readinglistdatacontroller.h \
    src/Data/databaseeditoroperator.h \
    src/DataClasses/authorinfo.h \
    src/DataClasses/genreinfo.h \
    src/DataClasses/mangaauthors.h \
    src/DataClasses/mangagenres.h \
    src/DataClasses/mangainfo.h \
    src/DataClasses/newsstorage.h \
    src/DataClasses/newssubscriptions.h \
    src/DataClasses/publisherinfo.h \
    src/DataClasses/readitem.h \
    src/Utilities/datetime.h \
    src/about.h \
    src/mangasqlquerymodel.h \
    src/rssfetcher.h \
    src/xmldataparser.h \
    src/xmlreadinglistparser.h \
    src/xmlwrapper.h

SOURCES += src/databaseeditor.cpp \
    src/genresinfoeditor.cpp \
    src/databaseeditor.cpp \
    src/about.cpp \
    src/main.cpp \
    src/mcra.cpp \
    src/webBrowser.cpp \
    src/genresinfoeditor.cpp \
    src/Data/databasemanager.cpp \
    src/Data/databasecreator.cpp \
    src/Data/databaseeraser.cpp \
    src/Data/dataimporter.cpp \
    src/Data/readinglistdatacontroller.cpp \
    src/Data/databaseeditoroperator.cpp \
    src/DataClasses/newsstorage.cpp \
    src/DataClasses/mangainfo.cpp \
    src/DataClasses/mangagenres.cpp \
    src/DataClasses/mangaauthors.cpp \
    src/DataClasses/genreinfo.cpp \
    src/DataClasses/authorinfo.cpp \
    src/DataClasses/newssubscriptions.cpp \
    src/DataClasses/publisherinfo.cpp \
    src/DataClasses/readitem.cpp \
    src/Utilities/datetime.cpp \
    src/mangasqlquerymodel.cpp \
    src/rssfetcher.cpp \
    src/xmldataparser.cpp \
    src/xmlreadinglistparser.cpp \
    src/xmlwrapper.cpp

FORMS += src/forms_about.ui \
    src/forms_genre_editor.ui \
    src/forms_subscription_manager.ui \
    src/forms_web_browser.ui \
    src/forms_database_editor.ui \
    src/forms_main.ui
