#include "core/headers/Personne.h"
#include "core/headers/initDB.h"
#include <QtSql>
#include <memory>

using namespace std;

bool Personne::updateNom() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne nom=:nom WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":nom", QString::fromStdString(nom));
    return query.exec();
}

bool Personne::updatePrenom() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne prenom=:prenom WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":prenom", QString::fromStdString(prenom));
    return query.exec();
}

bool Personne::updateAdresse() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne adresse=:adresse WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":adresse", QString::fromStdString(adresse));
    return query.exec();
}

bool Personne::updateEmail() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne email=:email WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":email", QString::fromStdString(email));
    return query.exec();
}

bool Personne::updatePassword() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne password=:password WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":password", QString::fromStdString(password));
    return query.exec();
}

bool Personne::updateRole() {
    QSqlQuery query;
    query.prepare("UPDATE SET personne role=:role WHERE idPersonne=:idPersonne");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":role", QString::fromStdString(role));
    return query.exec();
}

bool Personne::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO personne (idPersonne, nom, prenom, adresse, email, password, role) "
                  "VALUES (:idPersonne, :nom, :prenom, :adresse, :adresse, :email, :password, :role)");
    query.bindValue(":idPersonne", QVariant(idPersonne));
    query.bindValue(":nom", QString::fromStdString(nom));
    query.bindValue(":prenom", QString::fromStdString(prenom));
    query.bindValue(":adresse", QString::fromStdString(adresse));
    query.bindValue(":email", QString::fromStdString(email));
    query.bindValue(":password", QString::fromStdString(password));
    query.bindValue(":role", QString::fromStdString(role));

    return query.exec();
}

Personne::Personne(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password, const string& role) {
    this->idPersonne = ++totalPersonne;
    this->adresse = adresse;
    this->prenom = prenom;
    this->nom = nom;
    this->email = email;
    this->password = password;
    this->role = role;
    addIntoDb();
}

void Personne::setAdresse(const string &adresse) {
    this->adresse = adresse;
    updateAdresse();
}

void Personne::setPrenom(const string &premom) {
    this->prenom = premom;
    updatePrenom();
}

void Personne::setNom(const string &nom) {
    this->nom = nom;
    updateNom();
}

void Personne::setEmail(const string &email) {
    this->email = email;
    updateEmail();
}

void Personne::setPassword(const string &password) {
    this->password = password;
    updatePassword();
}

int Personne::getTotalPersonne() {
    return totalPersonne;
}

int Personne::getIdPersonne() const {
    return this->idPersonne;
}

string Personne::getAdresse() {
    return this->adresse;
}

string Personne::getPrenom() {
    return this->prenom;
}

string Personne::getNom() {
    return this->nom;
}

string Personne::getEmail() {
    return this->email;
}

string Personne::getPassword() {
    return this->password;
}

string Personne::getRole() {
    return this->role;
}

void Personne::afficherPersonne() {
    cout << "Nom: " << this->nom << endl;
    cout << "Prenom: " << this->prenom <<endl;
    cout << "Adresse: " << this->adresse << endl;
    cout << "Email: " << this->email << endl;
    cout << "idPersonne: " << this->idPersonne << endl;
    cout << "Role: " << this->role << endl;
}

string Personne::printPersonne() {
    string str = "";
    str += "Nom: " + this->nom +"\n";
    str += "Prenom: " + this->prenom +"\n";
    str += "Adresse: " + this->adresse +"\n";
    str += "Email: " + this->email +"\n";
    str += "idPersonne: " + to_string(this->idPersonne) +"\n";
    str += "Role: " + this->role +"\n";
}

Personne::Personne(int id, const string &nom, const string &prenom, const string &adresse, const string &email,
                   const string &password, const string &role) {
    this->idPersonne = id;
    this->adresse = adresse;
    this->prenom = prenom;
    this->nom = nom;
    this->email = email;
    this->password = password;
    this->role = role;
}


Personne *Personne::findPersonneById(int id) {
    QSqlQuery query;
    query.prepare( "SELECT * FROM personne WHERE idPersonne = :id");
    query.bindValue(":id", QVariant(id));

    if(!query.exec() ){
        Errors::appendError("Pas d'utilisateur avec l'id: " + to_string(id));
    }
    if(query.next()){
        int idPersonne = query.value( 0 ).toInt();
        string adresse = query.value(1).toString().toStdString();
        string prenom = query.value(2).toString().toStdString();
        string nom = query.value(3).toString().toStdString();
        string email = query.value(4).toString().toStdString();
        string password = query.value(5).toString().toStdString();
        string role = query.value(6).toString().toStdString();
        unique_ptr<Personne> p = std::make_unique<Personne>(idPersonne,nom,prenom,adresse,email,password,role);
        return p.get();
    }
    return nullptr;
}

void Personne::setIdPersonne(int id) {
    this->idPersonne = id;
}

bool Personne::checkIfEmailAlreadyExists(string email) {
    QSqlQuery query;
    query.prepare( "SELECT idPersonne FROM personne WHERE email = :email");
    query.bindValue(":email", QString::fromStdString(email));

    if ( !query.exec() ) {
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique survenu lors d'une requete.");
    }

    if ( query.first() ) {
        return true;
    }

    return false;
}

int Personne::addUserToDb(const string &nom, const string &prenom, const string &adresse, const string &email,
                       const string &password, const string &role) {

    if (nom.empty() || prenom.empty() || email.empty() || password.empty() || role.empty()) {
        Errors::appendError("L'un de vos champ est vide.");
        return false;
    }

    if (Personne::checkIfEmailAlreadyExists(email)) {
        Errors::appendError("Email deja en base. Veuillez utiliser une autre email.");
        return false;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO personne (nom, prenom, adresse, email, password, role) "
                  "VALUES (:nom, :prenom, :adresse, :email, :password, :role)");
    query.bindValue(":nom", QString::fromStdString(nom));
    query.bindValue(":prenom", QString::fromStdString(prenom));
    query.bindValue(":adresse", QString::fromStdString(adresse));
    query.bindValue(":email", QString::fromStdString(email));
    query.bindValue(":password", QString::fromStdString(initDB::toHash(password)));
    query.bindValue(":role", QString::fromStdString(role));

    if ( !query.exec() ) {
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique survenu lors d'une requete.");
    }

    return query.lastInsertId().toInt();
}








