#include "core/headers/Dispatcher.h"
#include <memory>
#include <random>
#include <QtSql>
#include "core/headers/common.h"

Dispatcher::Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password) : Personne(nom, prenom, adresse, email, password, ROLE_DISPATCHER) {

}
Dispatcher::Dispatcher(int id, const string& nom, const string& prenom, const string& adresse, const string& email, const string& password) : Personne(id,nom, prenom, adresse, email, password, ROLE_DISPATCHER) {

}

bool Dispatcher::remplir(int n) {
    random_device rseed;
    mt19937 rgen(rseed());
    uniform_int_distribution<int> randomPoids(1,100);
    uniform_int_distribution<int> randomVille(0, listeVille.size() -1);

    for (size_t i = 0; i < n; i++) {
        Colis * colis = new Colis(listeVille.at(randomVille(rgen)), randomPoids(rgen));

        colis->setStatut(COLIS_SOLICITATION_LIVRAISON);
        listeColis.push_back(
                colis
        );
        colis->setDispatcher(this);
    }

    return true;
}

bool Dispatcher::dispatch() {
    vector<Colis *> unattributed;
    vector<Trajet *> solicited;
    for(Colis * colis : listeColis) {
        unattributed.push_back(colis);
        for (Chauffeur * ch : Chauffeur::getListAllChauffeurAndLoad()) {
            int indexTrajet = ch->getIndexTrajet(colis->getVilleArrivee());
            if (indexTrajet != -1) {
                Trajet * trajet = ch->getTrajetByIndex(indexTrajet);
                if (trajet->colieAjoutable(colis)) {
                    colis->setStatut(COLIS_VALIDATION_LIVRAISON);
                    trajet->ajouterColis(colis);
                    unattributed.pop_back();
                    break;
                }
            }
        }
    }

    listeColis = unattributed;
    return unattributed.empty();
}

bool Dispatcher::attribueColis(Colis *c) {
    c->setStatut(COLIS_SOLICITATION_LIVRAISON);
    listeColis.push_back(c);
    c->setDispatcher(this);
    return true;
}

int Dispatcher::getNombreColisDispatchable() {
    return listeColis.size();
}

Dispatcher * Dispatcher::constructDispatcherFromId(int id) {
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
    Dispatcher * dispatcher = new Dispatcher(nom,prenom,adresse,email,password);
    dispatcher->setIdPersonne(idPersonne);

    return dispatcher;
}

vector<Dispatcher *> Dispatcher::getListAllDispatcherAndLoad() {
    vector<Dispatcher *> list;
    QSqlQuery query;
    query.prepare( "SELECT * FROM personne WHERE role = :role");
    query.bindValue(":role", QString::fromStdString(ROLE_DISPATCHER));

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
        auto* d = new Dispatcher(idPersonne,nom,prenom,adresse,email,password);
        d->loadColisOfDispatcherFromDB();
        list.push_back(d);
    }
    return list;
}

vector<Colis *> Dispatcher::loadColisOfDispatcherFromDB(){
    QSqlQuery query;
    query.prepare( "SELECT * FROM colis WHERE idDispatcher = :id" );
    query.bindValue(":id", QVariant(idPersonne));

    if(!query.exec() ){
        qDebug() << query.lastError();
        throw std::runtime_error("Erreur critique lors d'une requete");
    } while(query.next()){
        int idColis = query.value( 0 ).toInt();
        double poids = query.value( 1 ).toDouble();
        string villeArrive = query.value(2).toString().toStdString();
        string date = query.value(3).toString().toStdString();
        int statut = query.value( 4 ).toInt();
        int idDispatcher = query.value( 6 ).toInt();
        auto* c = new Colis(idColis, poids, villeArrive, date, statut, idDispatcher);
        listeColis.push_back(c);
    }

    return listeColis;
}


vector<Colis *> Dispatcher::getListColis() {
    return listeColis;
}
