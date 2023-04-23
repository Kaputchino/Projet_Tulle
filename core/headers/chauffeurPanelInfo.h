#ifndef PROJET_TULLE_CHAUFFEURPANELINFO_H
#define PROJET_TULLE_CHAUFFEURPANELINFO_H

#include "core/headers/Chauffeur.h"

class ChauffeurPanelInfo {
private:
    inline static Chauffeur * logged;
    inline static Trajet * selectedTrajet;
public:
    static Chauffeur * getLogged();
    static void setLogged(int idChauffeur);
    static Trajet * getSelelectedTrajet();
    static void setSelectedTrajet(Trajet * trajet);
};


#endif //PROJET_TULLE_CHAUFFEURPANELINFO_H
