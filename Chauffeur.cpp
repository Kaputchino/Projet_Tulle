#include "Chauffeur.h"

bool Chauffeur::ajoutTrajet(Trajet *t) {

    if (t->getIdChauffeur() != getIdChauffeur()) {
        return false;
    }

    for(int i = 0; i < listeTrajet.size(); i++){
        if(listeTrajet.at(i)->getIdTrajet() == t->getIdTrajet()){
            return false;
        }
    }
    listeTrajet.push_back(t);
    return true;
}

bool Chauffeur::supprimerTrajet(Trajet t) {
    for(int i = 0; i < listeTrajet.size(); i++){
        if(listeTrajet.at(i)->getIdTrajet() == t.getIdTrajet()){
            listeTrajet.erase(listeTrajet.begin() + i);
            return true;
        }
    }
    return false;
}

bool
Chauffeur::modifierTrajet(const Trajet& t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee,
                          double poids, double prix) {

    if (t.getIdChauffeur() != getIdChauffeur()) {
        return false;
    }

    int index = -1;
    for(int i = 0; i < listeTrajet.size(); i++){
        if(listeTrajet.at(i)->getIdTrajet() == t.getIdTrajet()){
            index = i;
        }
    }
    if(index == -1){
        return false;
    }
    Trajet* trajetPtr = listeTrajet.at(index);
    if(!villeDepart.empty()){
        trajetPtr->setVilleDepart(villeDepart);
    }
    if(!villeArrivee.empty()){
        trajetPtr->setVilleArrivee(villeArrivee);
    }
    if(!horaireArrivee.empty()){
        trajetPtr->setHoraireArrivee(horaireArrivee);
    }
    if(!horaireDepart.empty()){
        trajetPtr->setHoraireDepart(horaireDepart);
    }
    if(poids > 0){
        trajetPtr->setPoids(poids);
    }
    if(prix >= 0){
        trajetPtr->setPrix(prix);
    }
    return true;
}

Chauffeur::Chauffeur(const string& nom, const string& prenom, const string& adresse, const string& telephone) : Personne(nom, prenom, adresse, telephone) {
    this->idChauffeur = getIdPersonne();
}

int Chauffeur::getIdChauffeur() const {
    return idChauffeur;
}

Trajet * Chauffeur::getTrajetByIndex(int index) {
    return listeTrajet.at(index);
}

int Chauffeur::getIndexTrajet(string villeArrivee) {
    for (int i = 0; i < listeTrajet.size(); i++)
    {
        if (listeTrajet.at(i)->getVilleArrivee() == villeArrivee) {
            return i;
        }
    }

    return -1;
}

int Chauffeur::getNbTrajet() {
    return listeTrajet.size();
}

double Chauffeur::gain() {
    double ammount = 0;
    for(int i = 0; i < listeTrajet.size(); i++){
        ammount += listeTrajet.at(i)->getPrix();
    }
    return ammount;
}

int Chauffeur::nbColis() {
    int ammount = 0;
    for(int i = 0; i < listeTrajet.size(); i++){
        ammount += listeTrajet.at(i)->nbColis();
    }
    return ammount;
}

double Chauffeur::poidTotal() {
    double ammount = 0;
    for(int i = 0; i < listeTrajet.size(); i++){
        ammount += listeTrajet.at(i)->getPoidEnCharge();
    }
    return ammount;
}

vector<Colis *> Chauffeur::getAllColis() {

    vector<Colis *> listeColis;

    for(Trajet * tr : listeTrajet) {
        for (Colis * colie : tr->getListeColis()) {
            listeColis.push_back(colie);
        }
    }

    return listeColis;
}

bool Chauffeur::validerTrajet(Trajet *t) {
    bool estDansSaListe = false;
    int i = 0;
    while (!estDansSaListe && i < listeTrajet.size()) {
        if (listeTrajet.at(i) == t) {
            estDansSaListe = true;
        }
    }

    if (estDansSaListe) {
        t->setStatuts(2);
    }

    return estDansSaListe;
}