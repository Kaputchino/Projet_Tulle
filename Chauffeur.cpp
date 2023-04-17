#include "Chauffeur.h"

bool Chauffeur::ajoutTrajet(Trajet *t) {

    if (t->getIdChauffeur() != getIdChauffeur()) {\
        return false;
    }

    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {
        return false;
    }

    listeTrajet.push_back(t);
    return true;
}

bool Chauffeur::supprimerTrajet(Trajet *t) {

    int indexTrajet = indexTrajetDansListe(t->getIdTrajet());

    if (indexTrajet != -1) {
        listeTrajet.erase(listeTrajet.begin() + indexTrajet);
        return true;
    }

    return false;
}

bool
Chauffeur::modifierTrajet(const Trajet* t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee,
                          double poids, double prix) {

    if (t->getIdChauffeur() != getIdChauffeur()) {
        return false;
    }

    int index = indexTrajetDansListe(t->getIdTrajet());
    if (index == -1) {
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
    double amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->getPrix();
    }
    return amount;
}

int Chauffeur::nbColis() {
    int amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->nbColis();
    }
    return amount;
}

double Chauffeur::poidTotal() {
    double amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->getPoidEnCharge();
    }
    return amount;
}

bool Chauffeur::validerTrajet(Trajet *t) {
    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {

        for (Colis * colis : getAllColis()) {
            colis->setStatut(2);
        }

        t->setStatuts(2);
        return true;
    }

    return false;
}

bool Chauffeur::delancheLivraison(Trajet *t) {

    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {

        for (Colis * colis : getAllColis()) {
            colis->setStatut(3);
        }

        t->setStatuts(3);
        return true;
    }

    return false;
}

int Chauffeur::indexTrajetDansListe(int idTrajet) {
    for(int i = 0; i < listeTrajet.size(); i++){
        if(listeTrajet.at(i)->getIdTrajet() == idTrajet){
            return i;
        }
    }

    return -1;
}

int Chauffeur::getNbcoliesLivree() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == 4) {
            sum++;
        }
    }

    return sum;
}

vector<Colis *> Chauffeur::getAllColis() {
    vector<Colis *> resultat;

    for (Trajet * tr : listeTrajet) {
        for (Colis * colis : tr->getListeColis()) {
            resultat.push_back(colis);
        }
    }

    return resultat;
}

int Chauffeur::getNbColiesEnCoursLivraison() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == 3) {
            sum++;
        }
    }

    return sum;
}

int Chauffeur::getNbColiesEnAttenteLivraison() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == 2) {
            sum++;
        }
    }

    return sum;
}


