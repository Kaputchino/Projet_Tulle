#include <QtSql>
#include "core/headers/Admin.h"
#include "core/headers/common.h"

Admin::Admin(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password) : Personne(nom, prenom, adresse, email, password, ROLE_ADMIN) {

}

int Admin::nombreTrajets(Chauffeur *c) {
    return c->getNbTrajet();
}

double Admin::gainChauffeur(Chauffeur *c) {
    return c->gain();
}

double Admin::gainMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return c->gain()/nbTrajet;
    }
    return 0;
}

int Admin::nombreColis(Chauffeur *c) {
    return c->nbColis();
}

double Admin::colisMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return (double) c->nbColis()/nbTrajet;
    }
    return 0;
}

double Admin::poidTotal(Chauffeur *c) {
    return c->poidTotal();
}

double Admin::poidMoyenParTrajet(Chauffeur *c) {
    int nbTrajet = c->getNbTrajet();
    if(nbTrajet > 0){
        return c->poidTotal()/nbTrajet;
    }
    return 0;
}

int Admin::coliesLivree(Chauffeur *c) {
    return c->getNbcoliesLivree();
}

int Admin::coliesEnCoursLivraison(Chauffeur *c) {
    return c->getNbColiesEnCoursLivraison();
}

int Admin::coliesEnAttenteLivraison(Chauffeur *c) {
    return c->getNbColiesEnAttenteLivraison();
}

int Admin::coliesEnDemandeLivraison(Dispatcher * d) {
    return d->getNombreColisDispatchable();
}

Admin * Admin::constructAdminFromId(int id) {
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
    auto * admin = new Admin(nom,prenom,adresse,email,password);
    admin->setIdPersonne(idPersonne);

    return admin;
}

double Admin::poidTotalDispatcher(Dispatcher *d){
    double sum = 0;
    for(auto i : d->getListeColis()){
        sum += i->getPoid();
    }
    return sum;
}
double Admin::poidMoyenDispatcher(Dispatcher *d){
    double nb = coliesEnDemandeLivraison(d);
    if(coliesEnDemandeLivraison(d) != 0){
        nb = poidTotalDispatcher(d) / nb;
    }
    return nb;
}

string Admin::printInfoDispatcher(Dispatcher *c) {
    string str = c->printPersonne();
    str += "nombre de colis: " + to_string(coliesEnDemandeLivraison(c)) +"\n";
    str += "poid total des colis: " + to_string(poidTotalDispatcher(c)) +"\n";
    str += "poid moyen des colis: " + to_string(poidMoyenDispatcher(c)) +"\n";

    return str;
}
double Admin::poidTotal(Trajet* t){
    double sum = 0;
    for(int i = 0;  i < t->nbColis(); i++){
        sum += t->getListeColis().at(i)->getPoid();
    }
    return sum;
}

double Admin::poidMoyenParTrajet(Trajet *t) {
    double nb = t->nbColis();
    if(nb != 0){
        nb = poidTotal(t) / nb;
    }
    return nb;
}

string Admin::printInfoTrajet(Trajet *t) {
    string str = t->printTrajet();
    str += "nombre de colis: " + to_string(t->nbColis()) +"\n";
    str += "poid moyen par trajet: "+ to_string(poidMoyenParTrajet(t)) + "\n";
    str += "poid total: "+ to_string(poidTotal(t)) + "\n";
    return str;
}

string Admin::printInfoChauffeur(Chauffeur *c) {
    string str = c->printPersonne();
    str += "nombre de trajet: " + to_string(c->getNbTrajet()) +"\n";
    str += "nombre de colis: " + to_string(c->nbColis()) +"\n";

    str += "poid total des colis: " + to_string(c->poidTotal()) +"\n";
    str += "gain total: " + to_string(c->gain()) +"\n";

    str += "colis en attente: " + to_string(c->getNbColiesEnAttenteLivraison()) +"\n";
    str += "colis en cours: " + to_string(c->getNbColiesEnCoursLivraison()) +"\n";

    str += "colis livrés: " + to_string(c->getNbcoliesLivree()) +"\n";
    str += "nombre de colis moyen par trajet: " + to_string(colisMoyenParTrajet(c)) +"\n";

    str += "gain moyen par trajet: " + to_string(gainMoyenParTrajet(c)) +"\n";
    str += "poid moyen par trajet: " + to_string(poidMoyenParTrajet(c)) +"\n";

    return str;
}


