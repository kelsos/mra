#include "databasemanager.h"

DatabaseManager *DatabaseManager::m_pInstance = NULL;

DatabaseManager *DatabaseManager::Instance()
{
    if(!m_pInstance)
        m_pInstance = new DatabaseManager;
    return m_pInstance;
}

DatabaseManager::DatabaseManager(QObject *parent) :
    QObject(parent)
{
    // Database Initialization on the constructor of the singleton class
    appData=QSqlDatabase::addDatabase("QSQLITE");
    appData.setHostName("localhost");
    appData.setDatabaseName("mdb.db3");
    if(!appData.isOpen())
        appData.open();
    // Creating a temporary object of the database creator class for the db Initialization and then deleting it.
    DatabaseCreator creator(&appData,this);
    creator.initializeDatabaseTables();
    readDataCon = new ReadingListDataController(&appData,this);
}

DataImporter *DatabaseManager::getImporter()
{
    if(!importer)
        importer = new DataImporter(&appData,this);
    return importer;
}

void DatabaseManager::deleteImporter()
{
    delete importer;
    importer = nullptr;
}

ReadingListDataController *DatabaseManager::getReadDataController()
{
    return readDataCon;
}

void DatabaseManager::deleteOperator()
{
	delete editorOperator;
	editorOperator = nullptr;
}

DatabaseEditorOperator *DatabaseManager::getOperator()
{
	if(!editorOperator)
		editorOperator = new DatabaseEditorOperator(&appData,this);
	return editorOperator;
}
