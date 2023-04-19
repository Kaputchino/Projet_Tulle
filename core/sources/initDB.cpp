//
// Created by andre on 19/04/2023.
//

#include <QSqlDatabase>
#include <fstream>
#include <QSqlQuery>
#include "core/headers/initDB.h"
#include "iostream"
using namespace std;


void initDB::linkDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(readDataBasePath()));
    if(!db.open()){
        cout << "Can't Connect to DB !";
    }else{
        cout << "Connected Successfully to DB !";
        QSqlQuery query;
        query.prepare("QUERY TO BE SENT TO THE DB");
        if(!query.exec()){
            cout << "Can't Execute Query !";
        }
        else{
            cout << "Query Executed Successfully !";
        }
    }
}

string initDB::readDataBasePath() {
    ifstream myfile ("../../config");
    string mystring;
    if ( myfile.is_open() ) {
        myfile >> mystring;
        return mystring;
    }
}
