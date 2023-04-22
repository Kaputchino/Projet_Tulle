#include "core/headers/Colis.h"
#include "core/headers/Trajet.h"
#include "core/headers/common.h"
#include <QtSql>


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
    this->statut = COLIS_CREATION;
    this->trajet = nullptr;
    addIntoDb();
}

Colis::Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut, int idTrajet) {
    this->villeArrivee = villeArivee;
    this->dateAjoutColis = dateAjout;
    this->poid = poid;
    this->idColis = ++nbColisTotal;
    this->statut = COLIS_CREATION;
    this->trajet = Trajet::findTrajetById(idTrajet);
}



Trajet* Colis::getTrajet() const {
    return trajet;
}

void Colis::setTrajet(Trajet *trajet) {
    Colis::trajet = trajet;
    updateTrajet();
}
vector<Colis *> Colis::getColisAttente(){
    QSqlQuery query;
    vector<Colis*> list;
    query.prepare( "SELECT * FROM colis WHERE idTrajet is Null " );
    if(!query.exec() ){
    }while(query.next()){
        int idColis = query.value( 0 ).toInt();
        double poids = query.value( 1 ).toDouble();
        string villeArrive = query.value(2).toString().toStdString();
        string date = query.value(3).toString().toStdString();
        int statut = query.value( COLIS_LIVRAISON_FAITE ).toInt();
        int idTrajet = query.value( 5 ).toDouble();
        auto* c = new Colis(idColis, poids, villeArrive, date, statut, idTrajet);
        list.push_back(c);
    }
     return list;
}




