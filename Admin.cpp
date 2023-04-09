#include "Admin.h"

Admin::Admin(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {

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
