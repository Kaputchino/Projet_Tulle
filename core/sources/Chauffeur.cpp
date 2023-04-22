#include <QSqlQuery>
#include <QtSql>
#include "core/headers/Chauffeur.h"
#include "core/headers/common.h"

bool Chauffeur::ajoutTrajet(Trajet *t) {

    if (t->getIdChauffeur() != getIdPersonne()) {
        Errors::appendError("Le Trajet " + to_string(t->getIdTrajet()) + "appartient deja au chauffeur " + to_string(t->getIdChauffeur()));
        return false;
    }

    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {
        Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + "introuvable pour le chauffeur " + to_string(getIdPersonne()));
        return false;
    }

    listeTrajet.push_back(t);
    return true;
}

bool Chauffeur::supprimerTrajet(Trajet *t) {

    int indexTrajet = indexTrajetDansListe(t->getIdTrajet());

    if (indexTrajet != -1) {
        listeTrajet.erase(listeTrajet.begin() + indexTrajet);
        return true;
    }

    Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + "introuvable pour le chauffeur " + to_string(getIdPersonne()));
    return false;
}

bool
Chauffeur::modifierTrajet(const Trajet* t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee,
                          double poids, double prix) {

    if (t->getIdChauffeur() != getIdPersonne()) {
        Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + "n'appartient pas au chauffeur n " + to_string(getIdPersonne()));
        return false;
    }

    int index = indexTrajetDansListe(t->getIdTrajet());
    if (index == -1) {
        Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + "introuvable pour le chauffeur " + to_string(getIdPersonne()));
        return false;
    }

    Trajet* trajetPtr = listeTrajet.at(index);
    if(!villeDepart.empty()){
        trajetPtr->setVilleDepart(villeDepart);
    }
    if(!villeArrivee.empty()){
        trajetPtr->setVilleArrivee(villeArrivee);
    }
    if(!horaireArrivee.empty()){
        trajetPtr->setHoraireArrivee(horaireArrivee);
    }
    if(!horaireDepart.empty()){
        trajetPtr->setHoraireDepart(horaireDepart);
    }
    if(poids > 0){
        trajetPtr->setPoids(poids);
    }
    if(prix >= 0){
        trajetPtr->setPrix(prix);
    }

    return true;
}

Chauffeur::Chauffeur(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password) : Personne(nom, prenom, adresse, email, password, ROLE_CHAUFFEUR) {
}
Chauffeur::Chauffeur(int idChauffeur, const string& nom, const string& prenom, const string& adresse, const string& email, const string& password) : Personne(idChauffeur, nom, prenom, adresse, email, password, ROLE_CHAUFFEUR) {
}

Trajet * Chauffeur::getTrajetByIndex(int index) {
    return listeTrajet.at(index);
}

int Chauffeur::getIndexTrajet(const string& villeArrivee) {
    for (int i = 0; i < listeTrajet.size(); i++)
    {
        if (listeTrajet.at(i)->getVilleArrivee() == villeArrivee) {
            return i;
        }
    }

    return -1;
}

int Chauffeur::getNbTrajet() {
    return listeTrajet.size();
}

double Chauffeur::gain() {
    double amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->getPrix();
    }

    return amount;
}

int Chauffeur::nbColis() {
    int amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->nbColis();
    }

    return amount;
}

double Chauffeur::poidTotal() {
    double amount = 0;
    for(Trajet * tr : listeTrajet){
        amount += tr->getPoidEnCharge();
    }

    return amount;
}

bool Chauffeur::validerTrajet(Trajet *t) {
    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {

        for (Colis * colis : getAllColis()) {
            colis->setStatut(COLIS_VALIDATION_LIVRAISON);
        }

        t->setStatuts(TRAJET_VALIDATION);
        return true;
    }

    Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + " introuvable pour le chauffeur " + to_string(getIdPersonne()));
    return false;
}

bool Chauffeur::delancheLivraison(Trajet *t) {

    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {

        for (Colis * colis : getAllColis()) {
            colis->setStatut(COLIS_LIVRAISON_EN_COURS);
        }

        t->setStatuts(TRAJET_LIVRAISON_EN_COURS);
        return true;
    }

    Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + " introuvable pour le chauffeur " + to_string(getIdPersonne()));
    return false;
}

bool Chauffeur::declareLivraison(Trajet *t) {

    if (indexTrajetDansListe(t->getIdTrajet()) != -1) {

        for (Colis * colis : getAllColis()) {
            colis->setStatut(COLIS_LIVRAISON_FAITE);
        }

        t->setStatuts(TRAJET_LIVRAISON_FAITE);
        return true;
    }

    Errors::appendError("Trajet " + to_string(t->getIdTrajet()) + " introuvable pour le chauffeur " + to_string(getIdPersonne()));
    return false;
}

int Chauffeur::indexTrajetDansListe(int idTrajet) {
    for(int i = 0; i < listeTrajet.size(); i++){
        if(listeTrajet.at(i)->getIdTrajet() == idTrajet){
            return i;
        }
    }

    return -1;
}

int Chauffeur::getNbcoliesLivree() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == COLIS_LIVRAISON_FAITE) {
            sum++;
        }
    }

    return sum;
}

vector<Colis *> Chauffeur::getAllColis() {
    vector<Colis *> resultat;

    for (Trajet * tr : listeTrajet) {
        for (Colis * colis : tr->getListeColis()) {
            resultat.push_back(colis);
        }
    }

    return resultat;
}

int Chauffeur::getNbColiesEnCoursLivraison() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == COLIS_LIVRAISON_EN_COURS) {
            sum++;
        }
    }

    return sum;
}

int Chauffeur::getNbColiesEnAttenteLivraison() {
    int sum = 0;
    for (Colis * colis : this->getAllColis()) {
        if (colis->getStatut() == COLIS_VALIDATION_LIVRAISON) {
            sum++;
        }
    }

    return sum;
}

Chauffeur * Chauffeur::constructChauffeurFromId(int id) {
    QSqlQuery query;

    query.prepare(QString::fromStdString("SELECT * FROM personne WHERE idPersonne = :idPersonne"));
    query.bindValue(":idPersonne", QVariant(id));
    query.exec();

    query.next();
    int idPersonne = query.value( 0 ).toInt();
    string nom = query.value(1).toString().toStdString();
    string prenom = query.value(2).toString().toStdString();
    string adresse = query.value(3).toString().toStdString();
    string email = query.value(4).toString().toStdString();
    string password = query.value(5).toString().toStdString();
    auto * chauffeur = new Chauffeur(nom,prenom,adresse,email,password);
    chauffeur->setIdPersonne(idPersonne);

    return chauffeur;
}

bool Chauffeur::loadTrajetFromDB() {
    QSqlQuery query;
    query.prepare( "SELECT * FROM trajet WHERE idPersonne = :id");
    query.bindValue(":id", QVariant(idPersonne));

    if(!query.exec() ){
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique lors d'une requete");
    }

    while(query.next()){
        int idChauffeur = query.value( 0 ).toInt();
        string VilleDepart = query.value(1).toString().toStdString();
        string villeArrivee = query.value(2).toString().toStdString();
        string horaireDepart = query.value(3).toString().toStdString();
        string horaireArrivee = query.value(4).toString().toStdString();
        double poid = query.value(5).toDouble();
        double prix = query.value(5).toDouble();
        int idTrajet = query.value(5).toInt();
        int statut = query.value(5).toInt();
        auto *t = new Trajet(idChauffeur,VilleDepart, villeArrivee, horaireDepart, horaireArrivee, poid, prix, idTrajet, statut);
        listeTrajet.push_back(t);
    }
    return true;
}

vector<Chauffeur *> Chauffeur::getListAllChauffeur() {
    vector<Chauffeur *> list;
    QSqlQuery query;
    query.prepare( "SELECT * FROM personne WHERE role = :role");
    query.bindValue(":role", QString::fromStdString(ROLE_CHAUFFEUR));

    if(!query.exec() ){
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique lors d'une requete");
    }

    while(query.next()){
        int idPersonne = query.value( 0 ).toInt();
        string nom = query.value(1).toString().toStdString();
        string prenom = query.value(2).toString().toStdString();
        string adresse = query.value(3).toString().toStdString();
        string email = query.value(4).toString().toStdString();
        string password = query.value(5).toString().toStdString();
        string role = query.value(6).toString().toStdString();
        auto* c = new Chauffeur(idPersonne,nom,prenom,adresse,email,password);
        list.push_back(c);
    }
    return list;
}




