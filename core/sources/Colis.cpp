#include "core/headers/Colis.h"
#include "core/headers/Trajet.h"
#include "core/headers/Dispatcher.h"

#include "core/headers/common.h"
#include <QtSql>
#include <ctime>


bool Colis::updateDate() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET dataAjout = :dataAjout WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":dataAjout", QString::fromStdString(dateAjoutColis));
    return query.exec();
}

bool Colis::updateStatut() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET statut = :statut WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":statut", QVariant(statut));
    return query.exec();
}

bool Colis::updateTrajet() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET idTrajet = :idTrajet WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":idTrajet", QVariant(trajet->getIdTrajet()));
    return query.exec();
}
bool Colis::updateDispatcher() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET idDispatcher = :idDispatcher WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":idDispatcher", QVariant(dispatcher->getIdPersonne()));
    return query.exec();
}

bool Colis::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO colis (poids, villeArivee, dataAjout, statut) "
                  "VALUES (:poids, :villeArivee, :dataAjout, :statut)");
    query.bindValue(":poids", QVariant(poid));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    query.bindValue(":dataAjout", QString::fromStdString(dateAjoutColis));
    query.bindValue(":statut", QVariant(statut));
    query.exec();
    this->idColis = query.lastInsertId().toInt();

    return true;
}

bool Colis::updatePoid() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET poids = :poids WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":poids", QVariant(poid));
    return query.exec();
}
bool Colis::updateVille() {
    QSqlQuery query;
    query.prepare("UPDATE colis SET villeArivee = :villeArivee WHERE idColis = :idColis");
    query.bindValue(":idColis", QVariant(idColis));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
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
    this->dateAjoutColis = currentDate();
    this->statut = COLIS_CREATION;
    this->trajet = nullptr;
    this->dispatcher = nullptr;
    addIntoDb();
    ++nbColisTotal;
}

Colis::Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut, int idTrajet, int idDispatcher) {
    this->idColis = id;
    this->villeArrivee = villeArivee;
    this->dateAjoutColis = dateAjout;
    this->poid = poid;
    this->statut = statut;
    this->trajet = Trajet::findTrajetById(idTrajet);
    this->dispatcher = Dispatcher::constructDispatcherFromId(idDispatcher);
    ++nbColisTotal;
}

Colis::Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut, int idDispatcher) {
    this->idColis = id;
    this->villeArrivee = villeArivee;
    this->dateAjoutColis = dateAjout;
    this->poid = poid;
    this->statut = statut;
    this->dispatcher = Dispatcher::constructDispatcherFromId(idDispatcher);
    ++nbColisTotal;
}

Colis::Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut) {
    this->idColis = id;
    this->villeArrivee = villeArivee;
    this->dateAjoutColis = dateAjout;
    this->poid = poid;
    this->statut = statut;
    ++nbColisTotal;
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
    query.prepare( "SELECT * FROM colis WHERE idDispatcher IS NULL" );
    if(!query.exec() ){
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique lors d'une requete");
    }while(query.next()){
        int idColis = query.value( 0 ).toInt();
        double poids = query.value( 1 ).toDouble();
        string villeArrive = query.value(2).toString().toStdString();
        string date = query.value(3).toString().toStdString();
        int statut = query.value( 4 ).toInt();
        auto* c = new Colis(idColis, poids, villeArrive, date, statut);
        list.push_back(c);
    }
     return list;
}

Dispatcher *Colis::getDispatcher() const {
    return dispatcher;
}

void Colis::setDispatcher(Dispatcher *dispatcher) {
    Colis::dispatcher = dispatcher;
    updateDispatcher();
}

string Colis::currentDate() {
    time_t times_struct;
    struct tm * now;
    char result[80];
    time (&times_struct);
    now = localtime(&times_struct);
    strftime(result,sizeof(result),"%d-%m-%Y",now);
    return result;
}




