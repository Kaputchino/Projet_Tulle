#include "core/headers/Personne.h"

using namespace std;

Personne::Personne(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password, const string& role) {
    this->idPersonne = ++totalPersonne;
    this->adresse = adresse;
    this->prenom = prenom;
    this->nom = nom;
    this->email = email;
    this->password = password;
    this->role = role;
}

void Personne::setAdresse(const string &adresse) {
    this->adresse = adresse;
}

void Personne::setPrenom(const string &premom) {
    this->prenom = premom;
}

void Personne::setNom(const string &nom) {
    this->nom = nom;
}

void Personne::setEmail(const string &email) {
    this->email = email;
}

void Personne::setPassword(const string &password) {
    this->password = password;
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

void Personne::afficherPersonne() {
    cout << "Nom: " << this->nom << endl;
    cout << "Prenom: " << this->prenom <<endl;
    cout << "Adresse: " << this->adresse << endl;
    cout << "Email: " << this->email << endl;
    cout << "idPersonne: " << this->idPersonne << endl;
    cout << "Role: " << this->role << endl;
}