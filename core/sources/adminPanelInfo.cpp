#include "core/headers/adminPanelInfo.h"
#include "core/headers/admin.h"

void AdminPanelInfo::setLogged(int id) {
    AdminPanelInfo::logged = Admin::constructAdminFromId(id);
}

void AdminPanelInfo::removeChauffeurFromList(int index) {
    listeChauffeurs.erase(listeChauffeurs.begin() + index);
}

void AdminPanelInfo::addChauffeurToList(Chauffeur * c) {
    listeChauffeurs.push_back(c);
}

void AdminPanelInfo::removeDispatcherFromList(int index) {
    listeDispatchers.erase(listeDispatchers.begin() + index);
}

void AdminPanelInfo::addDispatcherToList(Dispatcher * d) {
    listeDispatchers.push_back(d);
}

vector<Chauffeur *> AdminPanelInfo::getListeChauffeurs() {
    return listeChauffeurs;
}

vector<Dispatcher *> AdminPanelInfo::getListeDispatchers() {
    return listeDispatchers;
}

void AdminPanelInfo::init() {
   listeChauffeurs = Chauffeur::getListAllChauffeurAndLoad();
   listeDispatchers = Dispatcher::getListAllDispatcherAndLoad();
   colisEnAttente = Colis::getColisAttente();
}

void AdminPanelInfo::setChauffeur(int index) {
    selectedChauffeur = listeChauffeurs.at(index);
}

void AdminPanelInfo::setDispacher(int index) {
    selectedDispatcher = listeDispatchers.at(index);
}

void AdminPanelInfo::setTrajet(int index) {
    selectedTrajet = selectedChauffeur->getListTrajets().at(index);
}

Chauffeur * AdminPanelInfo::currChauffeur() {
    return selectedChauffeur;
}

Dispatcher *AdminPanelInfo::currDispacher() {
    return selectedDispatcher;
}

Trajet *AdminPanelInfo::currTrajet() {
    return selectedTrajet;
}

void AdminPanelInfo::resetTrajet() {
    selectedTrajet = nullptr;
}

vector<Colis *> AdminPanelInfo::getColisEnAttente() {
    return colisEnAttente;
}

void AdminPanelInfo::removeColisEnAttente(int index) {
    colisEnAttente.erase(colisEnAttente.begin() + index);
}



