#include "Chauffeur.h"

bool Chauffeur::ajoutTrajet(Trajet t) {
    return false;
}

bool Chauffeur::supprimerTrajet(Trajet t) {
    return false;
}

bool
Chauffeur::modifierTrajet(Trajet t, string villeDepart, string villeArrivee, string horaireDepart, string horaireArrivee,
                          double poids, double prix) {
    return false;
}

Chauffeur::Chauffeur(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {

}

int Chauffeur::getIdChauffeur() const {
    return idChauffeur;
}

int Chauffeur::getIndexTrajet(string villeArrivee) {
    for (int i = 0; i < listeTrajet.size(); i++)
    {
        if (listeTrajet.at(i).getVilleArrivee() == villeArrivee) {
            return i;
        }
    }

    return -1;
}

