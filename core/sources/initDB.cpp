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
        throw std::runtime_error("Can't connect to DB.\nMake sure the absolute path in \"config\" is valid.");
    }else{
        QSqlQuery query;
        query.prepare("SELECT * FROM TRAJET");
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
    throw std::invalid_argument("Cannot read the config file.\nDoes the file \"config\" exists?");
}
