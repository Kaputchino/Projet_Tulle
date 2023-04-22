#ifndef PROJET_TULLE_ADMINPANELINFO_H
#define PROJET_TULLE_ADMINPANELINFO_H

#include "Chauffeur.h"
#include "Dispatcher.h"

class Admin;

class AdminPanelInfo {
private:
    inline static vector<Chauffeur *> listeChauffeurs;
    inline static vector<Dispatcher *> listeDispatchers;
    inline static Admin * logged = nullptr;
    inline static int selectedChauffeurId;
    inline static int selectedTrajetId;
public:
    static void setLogged(int id);
    static void removeChauffeurFromList(int index);
    static void addChauffeurToList(Chauffeur * c);
    static void removeDispatcherFromList(int index);
    static void addDispatcherToList(Dispatcher * d);
    static vector<Chauffeur *> getListeChauffeurs();
    static vector<Dispatcher *> getListeDispatchers();
    static void init();
    static void setSelectedChauffeurId(int id);
    static void setSelectedTrajatId(int id);
    static int getSelectedTrajatId();
    static int getSelectedChauffeurId();
};
#endif //PROJET_TULLE_ADMINPANELINFO_H
