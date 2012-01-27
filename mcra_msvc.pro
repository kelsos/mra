# ----------------------------------------------------
# This file is generated by the Qt Visual Studio Add-in.
# ------------------------------------------------------

TEMPLATE = vcapp
TARGET = mcra_msvc
DESTDIR = ./debug
QT += core gui sql network xml xmlpatterns webkit qaxserver qaxcontainer
CONFIG += debug
DEFINES += _WINDOWS QT_LARGEFILE_SUPPORT QT_DLL QT_WEBKIT_LIB QT_SQL_LIB QT_XMLPATTERNS_LIB QT_XML_LIB QT_NETWORK_LIB QT_HAVE_MMX QT_HAVE_SSE QT_HAVE_MMXEXT QT_HAVE_SSE2
INCLUDEPATH += ./lib/libxml2-2.7.8.win32/include \
    ./lib/iconv-1.9.2.win32/include \
    ./src \
    ./src/DataClasses \
    ./lib/includes \
    ./debug/.moc \
    ./debug/.ui \
    $(QTDIR)/mkspecs/win32-msvc2010 \
    ./GeneratedFiles
LIBS += -L"./lib/libxml2-2.7.8.win32/lib" \
    -L"./lib/iconv-1.9.2.win32/lib" \
    -llibxml2_a_dll. \
    -liconv_a \
    -lWS2_32.Lib \
    -lC:/Qt/4.8.0/plugins/sqldrivers/qsqlited4
PRECOMPILED_HEADER = StdAfx.h
DEPENDPATH += .
MOC_DIR += debug/.moc
OBJECTS_DIR += debug
UI_DIR += ./GeneratedFiles
RCC_DIR += ./GeneratedFiles
include(mcra_msvc.pri)

HEADERS += \
    src/databaseeditor.h \
    src/genresinfoeditor.h \
    src/datawrappers.h \
    src/Database/databaseinitializer.h

SOURCES += \
    src/databaseeditor.cpp \
    src/genresinfoeditor.cpp \
    src/datawrappers.cpp \
    src/Database/databaseinitializer.cpp

FORMS += \
    src/databaseeditor.ui \
    src/genresinfoeditor.ui
