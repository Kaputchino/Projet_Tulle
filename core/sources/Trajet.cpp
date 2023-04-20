#include "core/headers/Trajet.h"
#include <iostream>
#include <QSqlQuery>
#include <QVariant>



bool Trajet::updateStatut() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet statut=:statut WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":statut", QVariant(statut));
    return query.exec();
}
bool Trajet::updateChauffeur() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet villeDepart=:villeDepart WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":idPersonne", QVariant(idChauffeur));
    return query.exec();
}
bool Trajet::updateVilleDepart() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet villeDepart=:villeDepart WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":villeDepart", QString::fromStdString(villeDepart));
    return query.exec();
}
bool Trajet::updateVilleArrivee() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet villeArivee=:villeArivee WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    return query.exec();
}
bool Trajet::updateHoraireDepart() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet horaireDepart=:horaireDepart WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":horaireDepart", QString::fromStdString(horaireDepart));
    return query.exec();
}
bool Trajet::updateHoraireArrivee() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet horaireArrivee=:horaireArrivee WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":horaireArrivee", QString::fromStdString(horaireArrivee));
    return query.exec();
}
bool Trajet::updatePoid() {
    QSqlQuery query;
    query.prepare("UPDATE SET trajet poids=:poids WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":poids", QVariant(poids));
    return query.exec();
}
bool Trajet::updatePrix(){
    QSqlQuery query;
    query.prepare("UPDATE SET trajet prix=:prix WHERE idTrajet=:idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":prix", QVariant(prix));
    return query.exec();
}
bool Trajet::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO trajet (idTrajet, villeDepart, villeArivee, horaireDepart, horaireArrivee, poids, prix, statut, idPersonne) "
                  "VALUES (:idTrajet, :villeDepart, :villeArivee, :horaireDepart, :horaireArrivee, :poids, :prix, :statut, :idPersonne)");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":villeDepart", QString::fromStdString(villeDepart));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    query.bindValue(":horaireDepart", QString::fromStdString(horaireDepart));
    query.bindValue(":horaireArrivee", QString::fromStdString(horaireArrivee));
    query.bindValue(":poids", QVariant(poids));
    query.bindValue(":prix", QVariant(prix));
    query.bindValue(":statut", QVariant(statut));
    query.bindValue(":idPersonne", QVariant(idChauffeur));
    return query.exec();
}

Trajet::Trajet(int idChauffeur, const string &villeDepart, const string & villeArrivee, const string &horaireDepart, const string &horaireArrivee, double poids, double prix) {
    this->idTrajet = ++totalTrajets;
    this->idChauffeur= idChauffeur;
    this->villeDepart = villeDepart;
    this->villeArrivee = villeArrivee;
    this->horaireDepart = horaireDepart;
    this->horaireArrivee = horaireArrivee;
    this->poids = poids;
    this->prix = prix;
    this->statut = 0;
    addIntoDb();
}

int Trajet::getIdTrajet() const {
    return idTrajet;
}

int Trajet::getIdChauffeur() const {
    return idChauffeur;
}

void Trajet::setIdChauffeur(int idChauffeur) {
    this->idChauffeur = idChauffeur;
    updateChauffeur();
}

const string &Trajet::getVilleDepart() const {
    return villeDepart;
}

void Trajet::setVilleDepart(const string &villeDepart) {
    this->villeDepart = villeDepart;
    updateVilleDepart();
}

const string &Trajet::getVilleArrivee() const {
    return villeArrivee;
}

void Trajet::setVilleArrivee(const string &villeArrivee) {
    this->villeArrivee = villeArrivee;
    updateVilleArrivee();
}

const string &Trajet::getHoraireDepart() const {
    return horaireDepart;
}

void Trajet::setHoraireDepart(const string &horaireDepart) {
    this->horaireDepart = horaireDepart;
    updateHoraireDepart();
}

const string &Trajet::getHoraireArrivee() const {
    return horaireArrivee;
}

void Trajet::setHoraireArrivee(const string &horaireArrivee) {
    this->horaireArrivee = horaireArrivee;
    updateHoraireArrivee();
}

double Trajet::getPoids() const {
    return poids;
}

void Trajet::setPoids(double poids) {
    this->poids = poids;
    updatePoid();
}

double Trajet::getPrix() const {
    return prix;
}

void Trajet::setPrix(double prix) {
    this->prix = prix;
    updatePrix();
}

int Trajet::getStatuts() const {
    return statut;
}

void Trajet::setStatuts(int statuts) {
    if(statuts > -1 && statuts < 5){
        this->statut = statuts;
        updateStatut();
    }
}

void Trajet::ajouterColis(Colis *colis) {
    this->listeColis.push_back(colis);
    this->statut = 1;
    colis->setTrajet(this);
}

bool Trajet::colieAjoutable(Colis *colis) {
    double prochainPoid = (colis->getPoid() + getPoidEnCharge());
    if (prochainPoid <= poids && this->statut <= 1) {
         return true;
    }

    return false;
}

double Trajet::getPoidEnCharge() {
    double poids = 0;
    for (Colis * colis : listeColis) {
        poids += colis->getPoid();
    }

    return poids;
}


int Trajet::nbColis() {
    return listeColis.size();
}

void Trajet::afficherTrajet() {
    cout << "idTrajet: " << this->idTrajet << endl;
    cout << "idChauffeur: " << this->idChauffeur << endl;
    cout << "poids: " << this->poids << endl;
    cout << "statut: " << this->statut << endl;
    cout << "villeDepart: " << this->villeDepart << endl;
    cout << "villeArrivee: " << this->villeArrivee << endl;
    cout << "horaireDepart: " << this->horaireDepart << endl;
    cout << "horaireArrivee: " << this->horaireArrivee << endl;
    cout << "prix: " << this->prix << endl;
}

vector<Colis *> Trajet::getListeColis() {
    return listeColis;
}

Trajet *Trajet::findTrajetById(int id) {
    QSqlQuery query;
    vector<Colis> list;
    query.prepare(&"SELECT * FROM colis WHERE idTrajet = "[id]);
    if(!query.exec() ){

    }if(query.next()){
        Trajet trajet;
        return &trajet;
    }
    return nullptr;
}


