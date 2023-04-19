#include <QSqlQuery>
#include <QVariant>
#include "core/headers/Colis.h"

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

double Colis::getPoid() const {
    return poid;
}

void Colis::setPoid(double poid) {
    Colis::poid = poid;
}

Colis::Colis(string &villeArrivee, double poid) {
    this->villeArrivee = villeArrivee;
    this->poid = poid;
    this->idColis = ++nbColisTotal;
    this->statut = 0;
}

bool Colis::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO person (idColis, poids, villeArivee, dataAjout, statut, idTrajet) "
                  "VALUES (:idColis, :poids, :villeArivee, :dataAjout, :statut, :idTrajet)");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":poids", QVariant(poid));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    query.bindValue(":dataAjout", QString::fromStdString(dateAjoutColis));
    query.bindValue(":statut", QVariant(statut));
    query.bindValue(":idTrajet", QVariant(trajet->getIdTrajet()));
    return query.exec();
}

Trajet *Colis::getTrajet() const {
    return trajet;
}

void Colis::setTrajet(Trajet *trajet) {
    Colis::trajet = trajet;
}
