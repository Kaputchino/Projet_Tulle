#include "Admin.h"

Admin::Admin(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {

}

int Admin::nombreTrajets(Chauffeur *c) {
    return c->getNbTrajet();
}

double Admin::gainChauffeur(Chauffeur *c) {
    return c->gain();
}
