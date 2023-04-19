#include <QSqlDatabase>
#include <fstream>
#include <QSqlQuery>
#include "core/headers/initDB.h"
#include "iostream"
#include "core/headers/common.h"

using namespace std;

void initDB::linkDB() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(readDataBasePath()));
    if(!db.open()){
        cout << "Can't Connect to DB !";
    }else{
        cout << "Connected Successfully to DB !";
        QSqlQuery query;
        query.prepare("SELECT 2");
        if(!query.exec()){
            cout << "Can't Execute Query !";
        }
        else{
            cout << "Query Executed Successfully !";
        }
    }
}

string initDB::readDataBasePath(){
    ifstream myfile ("../config");
    string mystring;
    if ( myfile.is_open() ) {
        myfile >> mystring;
        return mystring;
    }
    throw std::invalid_argument("Impossible de lire le fichier de configuration");
}
