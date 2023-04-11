#include "Trajet.h"
#include <iostream>

Trajet::Trajet(int idChauffeur, const string &villeDepart, const string & villeArrivee, const string &horaireDepart, const string &horaireArrivee, double poids, double prix) {
    this->idTrajet = ++totalTrajets;
    this->idChauffeur= idChauffeur;
    this->villeDepart = villeDepart;
    this->villeArrivee = villeArrivee;
    this->horaireDepart = horaireDepart;
    this->horaireArrivee = horaireArrivee;
    this->poids = poids;
    this->prix = prix;
    this->statuts = 0;
}

int Trajet::getIdTrajet() const {
    return idTrajet;
}

int Trajet::getIdChauffeur() const {
    return idChauffeur;
}

void Trajet::setIdChauffeur(int idChauffeur) {
    this->idChauffeur = idChauffeur;
}

const string &Trajet::getVilleDepart() const {
    return villeDepart;
}

void Trajet::setVilleDepart(const string &villeDepart) {
    this->villeDepart = villeDepart;
}

const string &Trajet::getVilleArrivee() const {
    return villeArrivee;
}

void Trajet::setVilleArrivee(const string &villeArrivee) {
    this->villeArrivee = villeArrivee;
}

const string &Trajet::getHoraireDepart() const {
    return horaireDepart;
}

void Trajet::setHoraireDepart(const string &horaireDepart) {
    this->horaireDepart = horaireDepart;
}

const string &Trajet::getHoraireArrivee() const {
    return horaireArrivee;
}

void Trajet::setHoraireArrivee(const string &horaireArrivee) {
    this->horaireArrivee = horaireArrivee;
}

double Trajet::getPoids() const {
    return poids;
}

void Trajet::setPoids(double poids) {
    this->poids = poids;
}

double Trajet::getPrix() const {
    return prix;
}

void Trajet::setPrix(double prix) {
    this->prix = prix;
}

int Trajet::getStatuts() const {
    return statuts;
}

void Trajet::setStatuts(int statuts) {
    if(statuts > -1 && statuts < 5){
        this->statuts = statuts;
    }
}

void Trajet::ajouterColis(Colis *colis) {
    this->listeColis.push_back(colis);
}

bool Trajet::colieAjoutable(Colis *colis) {
    double prochainPoid = (colis->getPoid() + getPoidEnCharge());
    if (prochainPoid <= poids && this->statuts == 0) {
         return true;
    }

    return false;
}

double Trajet::getPoidEnCharge() {
    double poids = 0;
    for (Colis * colis : listeColis) {
        poids += colis->getPoid();
    }

    return poids;
}


int Trajet::nbColis() {
    return listeColis.size();
}

void Trajet::afficherTrajet() {
    cout << "idTrajet: " << this->idTrajet << endl;
    cout << "idChauffeur: " << this->idChauffeur << endl;
    cout << "poids: " << this->poids << endl;
    cout << "statuts: " << this->statuts << endl;
    cout << "villeDepart: " << this->villeDepart << endl;
    cout << "villeArrivee: " << this->villeArrivee << endl;
    cout << "horaireDepart: " << this->horaireDepart << endl;
    cout << "horaireArrivee: " << this->horaireArrivee << endl;
    cout << "prix: " << this->prix << endl;
}

vector<Colis *> Trajet::getListeColis() {
    return listeColis;
}
