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
string *initDB::toHash(const string& password) {
    std::hash <std::string> hash;
    return reinterpret_cast<string *>(hash(password));
}

Personne* initDB::login(string email, string password) {
    QSqlQuery query;
    query.prepare(QString::fromStdString("SELECT * FROM personne WHERE email = `" + email + "`"));
    if(!query.exec() ){

    }
    if(query.next()){
        string mdp = query.value(5).toString().toStdString();
        if(mdp.compare(*initDB::toHash(password)) == 0){
            int idPersonne = query.value( 0 ).toInt();
            string adresse = query.value(1).toString().toStdString();
            string prenom = query.value(2).toString().toStdString();
            string nom = query.value(3).toString().toStdString();
            string email = query.value(4).toString().toStdString();
            string role = query.value(6).toString().toStdString();
            auto* p = new Personne(idPersonne,nom,prenom,adresse,email,password,role);
            return p;
        }
    }
    return nullptr;
}
