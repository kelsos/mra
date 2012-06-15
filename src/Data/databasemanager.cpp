#include "databasemanager.h"
#include "QFile"
#include "mysql.h"
#include <qsql_mysql.h>
#include <QtSql/QtSql>

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
    QString filename="my.cnf";
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite))
    {
        QTextStream stream(&file);

        stream << "[manga_embedded]\n" << "basedir=.\n" << "datadir=.\n" << "default-character-set=utf8" << endl;

    }



    // Database Initialization on the constructor of the singleton class
    appData=QSqlDatabase::addDatabase("QMYSQL");
    appData.setDatabaseName("mdata");
    if(!appData.isOpen())
        appData.open();
    // Creating a temporary object of the database creator class for the db Initialization and then deleting it.
    DatabaseCreator creator(&appData,this);
    creator.initializeDatabaseTables();
    readDataCon = new ReadingListDataController(&appData,this);
	importer=nullptr;
	editorOperator=nullptr;
}

DataImporter *DatabaseManager::getImporter()
	{
    if(importer==nullptr)
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
	if(editorOperator==nullptr)
		editorOperator = new DatabaseEditorOperator(&appData,this);
	return editorOperator;
}
