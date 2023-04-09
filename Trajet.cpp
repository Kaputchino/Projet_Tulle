#include "Trajet.h"

Trajet::Trajet(int idChauffeur, string VilleDepart, string villeArrivee, string horaireDepart, string horaireArrivee, double poids, double prix) {
    this->idTrajet = totalTrajets++;
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
    Trajet::idChauffeur = idChauffeur;
}

const string &Trajet::getVilleDepart() const {
    return villeDepart;
}

void Trajet::setVilleDepart(const string &villeDepart) {
    Trajet::villeDepart = villeDepart;
}

const string &Trajet::getVilleArrivee() const {
    return villeArrivee;
}

void Trajet::setVilleArrivee(const string &villeArrivee) {
    Trajet::villeArrivee = villeArrivee;
}

const string &Trajet::getHoraireDepart() const {
    return horaireDepart;
}

void Trajet::setHoraireDepart(const string &horaireDepart) {
    Trajet::horaireDepart = horaireDepart;
}

const string &Trajet::getHoraireArrivee() const {
    return horaireArrivee;
}

void Trajet::setHoraireArrivee(const string &horaireArrivee) {
    Trajet::horaireArrivee = horaireArrivee;
}

double Trajet::getPoids() const {
    return poids;
}

void Trajet::setPoids(double poids) {
    Trajet::poids = poids;
}

double Trajet::getPrix() const {
    return prix;
}

void Trajet::setPrix(double prix) {
    Trajet::prix = prix;
}

int Trajet::getStatuts() const {
    return statuts;
}

void Trajet::setStatuts(int statuts) {
    if(statuts > -1 && statuts < 5){
        Trajet::statuts = statuts;
    }
}

void Trajet::ajouterColis(Colis colis) {
    this->listeColis.push_back(colis);
}

bool Trajet::colieAjoutable(Colis colis) {
    double prochainPoid = (colis.getPoid() + getPoidEnCharge());
    if (prochainPoid <= poids && this->statuts == 0) {
         return true;
    }

    return false;
}

double Trajet::getPoidEnCharge() {
    double poids = 0;
    for (Colis colis : listeColis) {
        poids += colis.getPoid();
    }

    return poids;
}


int Trajet::nbColis() {
    return listeColis.size();
}


int main(int argc, char const *argv[])
{
    Trajet trajetA = Trajet();
    trajetA.setHoraireArrivee("10h15");
    return 0;
}


