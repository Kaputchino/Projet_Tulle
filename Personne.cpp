#include "Personne.h"

using namespace std;

Personne::Personne(string nom, string prenom, string adresse, string telephone) {
    this->idPersonne = totalPersonne++;
    this->setAdresse(adresse);
    this->setPrenom(adresse);
    this->setNom(adresse);
    this->setTelephone(adresse);
}

void Personne::setAdresse(string adresse) {
    this->adresse = adresse;
}

void Personne::setPrenom(string premom) {
    this->premom = premom;
}

void Personne::setNom(string nom) {
    this->nom = nom;
}

void Personne::setTelephone(string telephone) {
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
    return this->premom;
}

string Personne::getNom() {
    return this->nom;
}

string Personne::getTelephone() {
    return this->telephone;
}

void Personne::afficherPersonne() {
    cout << "Nom: " << this->nom << endl;
    cout << "Prenom: " << this->premom <<endl;
    cout << "Adresse: " << this->adresse << endl;
    cout << "Telephone: " << this->telephone << endl;
    cout << "idPersonne: " << this->idPersonne << endl;
}