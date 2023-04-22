#include <fstream>
#include <QtSql>
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
string initDB::toHash(const string& password) {
    std::hash <std::string> hash;
    return to_string(hash(password));
}

int initDB::getIdFromLogin(string email, string password) {
    QSqlQuery query;

    query.prepare(QString::fromStdString("SELECT idPersonne FROM personne WHERE email = :email AND password = :password"));
    query.bindValue(":email", QString::fromStdString(email));
    query.bindValue(":password", QString::fromStdString(toHash(password)));
    query.exec();

    if (query.next()) {
        return query.value("idPersonne").toInt();
    } else {
        return -1;
    }

}

string initDB::getRoleFromId(int id) {
    QSqlQuery query;

    query.prepare(QString::fromStdString("SELECT role FROM personne WHERE idPersonne = :idPersonne"));
    query.bindValue(":idPersonne", QVariant(id));

    if ( !query.exec() ) {
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique lors de la connection");
    }

    query.next();
    return query.value("role").toString().toStdString();
}