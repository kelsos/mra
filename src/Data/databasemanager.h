#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QObject>
#include <QSqlDatabase>
#include "Data/databasecreator.h"
#include "Data/databaseeditoroperator.h"
#include "Data/databaseeraser.h"
#include "Data/dataimporter.h"
#include "Data/readinglistdatacontroller.h"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    static DatabaseManager *Instance();
    DataImporter *getImporter();
    void deleteImporter();
    ReadingListDataController *getReadDataController();
    DatabaseEditorOperator *getOperator();
    void deleteOperator();

private:
    //constructors are private to enforce the singleton state of the class
    explicit DatabaseManager(QObject *parent = 0);
    static DatabaseManager *m_pInstance;
    QSqlDatabase appData;
    DataImporter *importer;
    ReadingListDataController *readDataCon;
    DatabaseEditorOperator *editorOperator;

signals:
    
public slots:
    
};

#endif // DATABASEMANAGER_H
