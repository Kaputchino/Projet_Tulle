#include "core/headers/Trajet.h"
#include "core/headers/common.h"
#include <iostream>
#include <QtSql>

bool Trajet::updateStatut() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET statut = :statut WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":statut", QVariant(statut));
    return query.exec();
}
bool Trajet::updateChauffeur() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET idPersonne = :idPersonne WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":idPersonne", QVariant(idChauffeur));
    return query.exec();
}
bool Trajet::updateVilleDepart() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET villeDepart = :villeDepart WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":villeDepart", QString::fromStdString(villeDepart));
    return query.exec();
}
bool Trajet::updateVilleArrivee() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET villeArivee = :villeArivee WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":villeArivee", QString::fromStdString(villeArrivee));
    return query.exec();
}
bool Trajet::updateHoraireDepart() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET horaireDepart = :horaireDepart WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":horaireDepart", QString::fromStdString(horaireDepart));
    return query.exec();
}
bool Trajet::updateHoraireArrivee() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET horaireArrive e= :horaireArrivee WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":horaireArrivee", QString::fromStdString(horaireArrivee));
    return query.exec();
}
bool Trajet::updatePoid() {
    QSqlQuery query;
    query.prepare("UPDATE trajet SET poids = :poids WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":poids", QVariant(poids));
    return query.exec();
}
bool Trajet::updatePrix(){
    QSqlQuery query;
    query.prepare("UPDATE trajet SET prix = :prix WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(idTrajet));
    query.bindValue(":prix", QVariant(prix));
    return query.exec();
}
bool Trajet::addIntoDb() {
    QSqlQuery query;
    query.prepare("INSERT INTO trajet (villeDepart, villeArrivee, horaireDepart, horaireArrivee, poids, prix, statut, idPersonne) "
                  "VALUES (:villeDepart, :villeArrivee, :horaireDepart, :horaireArrivee, :poids, :prix, :statut, :idPersonne)");
    query.bindValue(":villeDepart", QString::fromStdString(villeDepart));
    query.bindValue(":villeArrivee", QString::fromStdString(villeArrivee));
    query.bindValue(":horaireDepart", QString::fromStdString(horaireDepart));
    query.bindValue(":horaireArrivee", QString::fromStdString(horaireArrivee));
    query.bindValue(":poids", QVariant(poids));
    query.bindValue(":prix", QVariant(prix));
    query.bindValue(":statut", QVariant(statut));
    query.bindValue(":idPersonne", QVariant(idChauffeur));
    query.exec();

    qDebug() << query.lastError();

    this->idTrajet = query.lastInsertId().toInt();
    return true;
}

Trajet::Trajet(int idChauffeur, const string &villeDepart, const string & villeArrivee, const string &horaireDepart, const string &horaireArrivee, double poids, double prix) {
    ++totalTrajets;
    this->idChauffeur= idChauffeur;
    this->villeDepart = villeDepart;
    this->villeArrivee = villeArrivee;
    this->horaireDepart = horaireDepart;
    this->horaireArrivee = horaireArrivee;
    this->poids = poids;
    this->prix = prix;
    this->statut = TRAJET_CREATION;
    addIntoDb();
}

Trajet::Trajet(int idChauffeur, const string &VilleDepart, const string &villeArrivee, const string &horaireDepart,
               const string &horaireArrivee, double poids, double prix, int idTrajet, int statut) {
    this->idTrajet = idTrajet;
    this->idChauffeur = idChauffeur;
    this->villeDepart = VilleDepart;
    this->villeArrivee = villeArrivee;
    this->horaireDepart = horaireDepart;
    this->horaireArrivee = horaireArrivee;
    this->poids = poids;
    this->prix = prix;
    this->statut = statut;
    ++totalTrajets;
}

Trajet *Trajet::findTrajetById(int id) {
    QSqlQuery query;
    vector<Colis> list;
    query.prepare("SELECT * FROM trajet WHERE idTrajet = :idTrajet");
    query.bindValue(":idTrajet", QVariant(id));
    if(!query.exec() ){

    }if(query.next()){
        int idTrajet = query.value( 0 ).toInt();
        string VilleDepart = query.value(1).toString().toStdString();
        string villeArrivee = query.value(2).toString().toStdString();
        string horaireDepart = query.value(3).toString().toStdString();
        string horaireArrivee = query.value(4).toString().toStdString();
        double poid = query.value(5).toDouble();
        double prix = query.value(6).toDouble();
        int idChauffeur = query.value(8).toInt();
        int statut = query.value(7).toInt();
        auto *t = new Trajet(idChauffeur,VilleDepart, villeArrivee, horaireDepart, horaireArrivee, poid, prix, idTrajet, statut);
        return t;
    }
    return nullptr;
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
    this->setStatuts(TRAJET_SOLICITATION);
    colis->setTrajet(this);
}

bool Trajet::colieAjoutable(Colis *colis) {
    double prochainPoid = (colis->getPoid() + getPoidEnCharge());

    if (prochainPoid <= poids && this->statut <= TRAJET_SOLICITATION) {
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
vector<Colis *> Trajet::loadColisOfTrajetFromDB(){
    QSqlQuery query;
    query.prepare( "SELECT * FROM colis WHERE idTrajet = :id" );
    query.bindValue(":id", QVariant(idTrajet));
    if(!query.exec() ){
    }while(query.next()){
        int idColis = query.value( 0 ).toInt();
        double poids = query.value( 1 ).toDouble();
        string villeArrive = query.value(2).toString().toStdString();
        string date = query.value(3).toString().toStdString();
        int statut = query.value( COLIS_LIVRAISON_FAITE ).toInt();
        int idTrajet = query.value( 5 ).toDouble();
        int idDispatcher = query.value( 6 ).toInt();
        auto* c = new Colis(idColis, poids, villeArrive, date, statut, idTrajet, idDispatcher);
        listeColis.push_back(c);
    }
    return listeColis;
}
string Trajet::printTrajet(){
    string str;
    str += "idTrajet: " + to_string(this->idTrajet) + "\n";
    str += "idChauffeur: " + to_string(this->idChauffeur) + "\n";
    str += "poid: " + to_string(this->poids) + "\n";
    str += "statut: " + to_string(this->statut) + "\n";
    str += "prix: " + to_string(this->prix) + "\n";

    str += "villeDepart: " + this->villeDepart + "\n";
    str += "villeArrivee: " + this->villeArrivee + "\n";
    str += "horaireDepart: " + this->horaireDepart + "\n";
    str += "horaireArrivee: " + this->horaireArrivee + "\n";

    return str;
}

string Trajet::translateStatus(int status) {
    if (status == TRAJET_CREATION) {
        return "Trajet en base";
    }

    if (status == TRAJET_SOLICITATION) {
        return "File d'attente chauffeur";
    }

    if (status == TRAJET_VALIDATION) {
        return "Trajet en attente de livraison";
    }

    if (status == TRAJET_LIVRAISON_EN_COURS) {
        return "Livraison en cours";
    }

    if (status == TRAJET_LIVRAISON_FAITE) {
        return "Trajet livree";
    }

    return "";
}






