#include "Admin.h"

#include <utility>

Admin::Admin(const string& nom, const string& prenom, const string& adresse, const string& telephone) : Personne(nom, prenom, adresse, telephone) {
    this->idAdmin = getIdPersonne();
}

int Admin::getIdAdmin() {
    return idAdmin;
}

int Admin::nombreTrajets(Chauffeur *c) {
    return c->getNbTrajet();
}

double Admin::gainChauffeur(Chauffeur *c) {
    return c->gain();
}

double Admin::gainMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return c->gain()/nbTrajet;
    }
    return 0;
}

int Admin::nombreColis(Chauffeur *c) {
    return c->nbColis();
}

double Admin::colisMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return c->nbColis()/nbTrajet;
    }
    return 0;
}

double Admin::poidTotal(Chauffeur *c) {
    return c->poidTotal();
}

double Admin::poidMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return c->poidTotal()/nbTrajet;
    }
    return 0;
}

int Admin::coliesLivree(Chauffeur *c) {
    int sum = 0;
    for (Colis * colis : c->getAllColis()) {
        if (colis->getStatut() == 4) {
            sum++;
        }
    }

    return sum;
}

int Admin::coliesEnCoursLibraison(Chauffeur *c) {
    int sum = 0;
    for (Colis * colis : c->getAllColis()) {
        if (colis->getStatut() == 3) {
            sum++;
        }
    }

    return sum;
}

int Admin::coliesEnAttenteLivraison(Chauffeur *c) {
    int sum = 0;
    for (Colis * colis : c->getAllColis()) {
        if (colis->getStatut() == 2) {
            sum++;
        }
    }

    return sum;
}

int Admin::coliesEnValidationLivraison(Chauffeur *c) {
    int sum = 0;
    for (Colis * colis : c->getAllColis()) {
        if (colis->getStatut() == 1s) {
            sum++;
        }
    }

    return sum;
}

