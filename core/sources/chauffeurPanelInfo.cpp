#include "core/headers/chauffeurPanelInfo.h"

Chauffeur * ChauffeurPanelInfo::getLogged() {
    return logged;
}

void ChauffeurPanelInfo::setLogged(int idDispatcher) {
    logged = Chauffeur::constructChauffeurFromId(idDispatcher);
    logged->loadTrajetFromDB();
}

Trajet * ChauffeurPanelInfo::getSelelectedTrajet() {
    return selectedTrajet;
}

Trajet *ChauffeurPanelInfo::setSelectedTrajet(Trajet *trajet) {
    selectedTrajet = trajet;
}
