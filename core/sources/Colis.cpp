#include "core/headers/Colis.h"
#include "core/headers/Trajet.h"
#include <QSqlQuery>
#include <QVariant>


bool Colis::updateDate() {
    QSqlQuery query;
    query.prepare("UPDATE SET colis dataAjout=:dataAjout WHERE idColis=:idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":dataAjout", QString::fromStdString(dateAjoutColis));
    return query.exec();
}

bool Colis::updateStatut() {
    QSqlQuery query;
    query.prepare("UPDATE SET colis dataAjout=:dataAjout WHERE idColis=:idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":dataAjout", QVariant(statut));
    return query.exec();
}

bool Colis::updateTrajet() {
    QSqlQuery query;
    query.prepare("UPDATE SET colis dataAjout=:dataAjout WHERE idColis=:idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":dataAjout", QVariant(trajet->getIdTrajet()));
    return query.exec();
}

bool Colis::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO colis (idColis, poids, villeArivee, dataAjout, statut, idTrajet) "
                  "VALUES (:idColis, :poids, :villeArivee, :dataAjout, :statut, :idTrajet)");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":poids", QVariant(poid));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    query.bindValue(":dataAjout", QString::fromStdString(dateAjoutColis));
    query.bindValue(":statut", QVariant(statut));
    query.bindValue(":idTrajet", QVariant(trajet->getIdTrajet()));
    return query.exec();
}

bool Colis::updatePoid() {
    QSqlQuery query;
    query.prepare("UPDATE SET colis poids=:poids WHERE idColis=:idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":poids", QVariant(poid));
    return query.exec();
}
bool Colis::updateVille() {
    QSqlQuery query;
    query.prepare("UPDATE SET colis poids=:poids WHERE idColis=:idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":poids", QVariant(poid));
    return query.exec();
}

int Colis::getIdColis() const {
    return idColis;
}

const string &Colis::getVilleArrivee() const {
    return villeArrivee;
}

void Colis::setVilleArrivee(const string &villeArrivee) {
    Colis::villeArrivee = villeArrivee;
    updateVille();
}

const string &Colis::getDateAjoutColis() const {
    return dateAjoutColis;
}

void Colis::setDateAjoutColis(const string &dateAjoutColis) {
    Colis::dateAjoutColis = dateAjoutColis;
    updateDate();
}

int Colis::getStatut() const {
    return statut;
}

void Colis::setStatut(int statut) {
    Colis::statut = statut;
    updateStatut();
}

double Colis::getPoid() const {
    return poid;
}

void Colis::setPoid(double poid) {
    Colis::poid = poid;
    updatePoid();
}

Colis::Colis(string &villeArrivee, double poid) {
    this->villeArrivee = villeArrivee;
    this->poid = poid;
    this->idColis = ++nbColisTotal;
    this->statut = 0;
    this->trajet = nullptr;
    addIntoDb();
}

Trajet* Colis::getTrajet() const {
    return trajet;
}

void Colis::setTrajet(Trajet *trajet) {
    Colis::trajet = trajet;
    updateTrajet();
}

