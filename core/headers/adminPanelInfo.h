#ifndef PROJET_TULLE_ADMINPANELINFO_H
#define PROJET_TULLE_ADMINPANELINFO_H

#include "Chauffeur.h"
#include "Dispatcher.h"

class Admin;

class AdminPanelInfo {
private:
    inline static vector<Chauffeur *> listeChauffeurs;
    inline static vector<Dispatcher *> listeDispatchers;
    inline static vector<Colis *> colisEnAttente;
    inline static Admin * logged = nullptr;
    inline static Chauffeur * selectedChauffeur = nullptr;
    inline static Trajet * selectedTrajet = nullptr;
    inline static Dispatcher * selectedDispatcher = nullptr;
public:
    static void setLogged(int id);
    static void removeChauffeurFromList(int index);
    static void addChauffeurToList(Chauffeur * c);
    static void removeDispatcherFromList(int index);
    static void addDispatcherToList(Dispatcher * d);
    static vector<Chauffeur *> getListeChauffeurs();
    static vector<Dispatcher *> getListeDispatchers();
    static void init();
    static void setChauffeur(int index);
    static void setDispacher(int index);
    static void setTrajet(int index);
    static Chauffeur * currChauffeur();
    static Dispatcher * currDispacher();
    static Trajet * currTrajet();
    static void resetTrajet();
    static vector<Colis *> getColisEnAttente();
};
#endif //PROJET_TULLE_ADMINPANELINFO_H
