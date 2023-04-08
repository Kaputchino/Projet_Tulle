#include "Colis.h"

int Colis::getIdColis() const {
    return idColis;
}

const string &Colis::getVilleArrivee() const {
    return villeArrivee;
}

void Colis::setVilleArrivee(const string &villeArrivee) {
    Colis::villeArrivee = villeArrivee;
}

const string &Colis::getDateAjoutColis() const {
    return dateAjoutColis;
}

void Colis::setDateAjoutColis(const string &dateAjoutColis) {
    Colis::dateAjoutColis = dateAjoutColis;
}

int Colis::getStatut() const {
    return statut;
}

void Colis::setStatut(int statut) {
    Colis::statut = statut;
}
