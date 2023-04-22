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
   listeChauffeurs = Chauffeur::getListAllChauffeur();
   listeDispatchers = Dispatcher::getListAllDispatcher();
}
