# ----------------------------------------------------
# Project: MCRA
# ------------------------------------------------------

TEMPLATE = app
TARGET = mcra_msvc
DESTDIR = ./debug
QT += core widgets sql network xml xmlpatterns webkitwidgets
CONFIG += debug
DEFINES += QT_DLL QT_WEBKIT_LIB QT_SQL_LIB QT_XMLPATTERNS_LIB QT_XML_LIB QT_NETWORK_LIB QT_HAVE_MMX QT_HAVE_SSE QT_HAVE_MMXEXT QT_HAVE_SSE2
INCLUDEPATH += src \
    ./build/debug/.moc \
    ./build/debug/.ui \
    ./build/GeneratedFiles
win32{
    LIBS += -L$(QTDIR)/plugins/sqldrivers \
            -lqsqlited4
    DEFINES += QT_LARGEFILE_SUPPORT _WINDOWS
    INCLUDEPATH += $(QTDIR)/mkspecs/win32-g++
}

#-L/usr/lib/x86_64-linux-gnu/qt4/plugins/sqldrivers \ #UBUNTU VM SETUP
#-L/usr/lib/qt/plugins/sqldrivers \ ARCHLINUX LAPTOP SETUP
unix:!macx{
    LIBS += -L/usr/lib/qt/plugins/sqldrivers \
            -lqsqlite
}

DEPENDPATH += .
MOC_DIR += ./build/debug/.moc
OBJECTS_DIR += ./build/debug/.obj
UI_DIR += ./build/GeneratedFiles
RCC_DIR += ./build/GeneratedFiles
QMAKE_CXXFLAGS += -std=c++0x

HEADERS += \
    src/controllers/usercontroller.h \
    src/controllers/applicationcontroller.h \
    src/entities/readitem.h \
    src/entities/publisherinfo.h \
    src/entities/newssubscriptions.h \
    src/entities/newsstorage.h \
    src/entities/mangainfo.h \
    src/entities/mangagenres.h \
    src/entities/mangaauthors.h \
    src/entities/genreinfo.h \
    src/entities/authorinfo.h \
    src/models/mangasqlquerymodel.h \
    src/services/database/readinglistdatacontroller.h \
    src/services/database/dataimporter.h \
    src/services/database/databasetablecreator.h \
    src/services/database/databasemanagerservice.h \
    src/services/database/databaseeraser.h \
    src/services/xml/xmlreadinglistparser.h \
    src/services/xml/xmldataparser.h \
    src/services/xml/rssfetcher.h \
    src/utilities/datetime.h \
    src/views/webBrowser.h \
    src/views/userlogindialog.h \
    src/views/registrationdialog.h \
    src/views/genresinfoeditor.h \
    src/views/dataeditorview.h \
    src/views/databaseeditor.h \
    src/views/about.h \
    src/services/database/mangainfoservice.h \
    src/services/database/userservice.h \
    src/services/database/authorinfoservice.h \
    src/services/database/dataservicebase.h \
    src/services/database/publisherinfoservice.h \
    src/views/mainwindowview.h


SOURCES += \
    src/main.cpp \
    src/controllers/usercontroller.cpp \
    src/controllers/applicationcontroller.cpp \
    src/entities/readitem.cpp \
    src/entities/publisherinfo.cpp \
    src/entities/newssubscriptions.cpp \
    src/entities/newsstorage.cpp \
    src/entities/mangainfo.cpp \
    src/entities/mangagenres.cpp \
    src/entities/mangaauthors.cpp \
    src/entities/genreinfo.cpp \
    src/entities/authorinfo.cpp \
    src/models/mangasqlquerymodel.cpp \
    src/services/database/readinglistdatacontroller.cpp \
    src/services/database/dataimporter.cpp \
    src/services/database/databasetablecreator.cpp \
    src/services/database/databasemanagerservice.cpp \
    src/services/database/databaseeraser.cpp \
    src/services/xml/xmlreadinglistparser.cpp \
    src/services/xml/xmldataparser.cpp \
    src/services/xml/rssfetcher.cpp \
    src/utilities/datetime.cpp \
    src/views/webBrowser.cpp \
    src/views/userlogindialog.cpp \
    src/views/registrationdialog.cpp \
    src/views/genresinfoeditor.cpp \
    src/views/dataeditorview.cpp \
    src/views/databaseeditor.cpp \
    src/views/about.cpp \
    src/services/database/mangainfoservice.cpp \
    src/services/database/userservice.cpp \
    src/services/database/authorinfoservice.cpp \
    src/services/database/dataservicebase.cpp \
    src/services/database/publisherinfoservice.cpp \
    src/views/mainwindowview.cpp



FORMS += \
    src/ui/userlogindialog.ui \
    src/ui/registrationdialog.ui \
    src/ui/forms_web_browser.ui \
    src/ui/forms_subscription_manager.ui \
    src/ui/forms_genre_editor.ui \
    src/ui/forms_database_editor.ui \
    src/ui/forms_about.ui \
    src/ui/mainwindowview.ui

OTHER_FILES +=



