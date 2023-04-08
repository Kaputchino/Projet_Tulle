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

int Colis::getPoid() const {
    return poid;
}

void Colis::setPoid(int poid) {
    Colis::poid = poid;
}

Colis::Colis(string &villeArrivee, double poid) {
    this->villeArrivee = villeArrivee;
    this->poid = poid;
    this->idColis = nbColisTotal++;
    this->statut = 0;
}
