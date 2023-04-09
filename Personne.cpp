#include "Personne.h"

using namespace std;

Personne::Personne(const string& nom, const string& prenom, const string& adresse, const string& telephone) {
    this->idPersonne = totalPersonne++;
    this->adresse = adresse;
    this->prenom = prenom;
    this->nom = nom;
    this->telephone = telephone;
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

void Personne::setTelephone(const string &telephone) {
    this->telephone = telephone;
}

int Personne::getTotalPersonne() {
    return totalPersonne;
}

int Personne::getIdPersonne() {
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

string Personne::getTelephone() {
    return this->telephone;
}

void Personne::afficherPersonne() {
    cout << "Nom: " << this->nom << endl;
    cout << "Prenom: " << this->prenom <<endl;
    cout << "Adresse: " << this->adresse << endl;
    cout << "Telephone: " << this->telephone << endl;
    cout << "idPersonne: " << this->idPersonne << endl;
}