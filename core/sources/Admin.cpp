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

string Admin::printInfoDispatcher(Dispatcher *c) {

    return "Sample info dispatcher \n oui oui.";
}

string Admin::printInfoTrajet(Trajet *t) {
    return "Sample info trajet \n oui oui.";
}

string Admin::printInfoChauffeur(Chauffeur *c) {
    string str = "";
    c->afficherPersonne();
    cout<<"nombre de trajet:"<<c->getNbTrajet()<<endl;
    cout<<"nombre de colis: "<<c->nbColis()<<endl;
    cout<<"poid total des colis: "<<c->poidTotal()<<endl;
    cout<<"gain total: "<<c->gain()<<endl;
    cout<<"colis en attente: "<<c->getNbColiesEnAttenteLivraison()<<endl;
    cout<<"colis en cours: "<<c->getNbColiesEnCoursLivraison()<<endl;
    cout<<"colis livrés: "<<c->getNbcoliesLivree();
    cout<<"nombre de colis moyen par trajet: "<<Admin::colisMoyenParTrajet(c)<<endl;
    cout<<"gain moyen par trajet: "<<Admin::gainMoyenParTrajet(c)<<endl;
    cout<<"poid moyen par trajet: "<<Admin::poidMoyenParTrajet(c)<<endl;
    return "Sample info chauffeur \n oui oui.";
}


