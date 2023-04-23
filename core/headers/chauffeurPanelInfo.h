#ifndef PROJET_TULLE_CHAUFFEURPANELINFO_H
#define PROJET_TULLE_CHAUFFEURPANELINFO_H

#include "core/headers/Chauffeur.h"

class ChauffeurPanelInfo {
private:
    inline static Chauffeur * logged;
public:
    static Chauffeur * getLogged();
    static void setLogged(int idChauffeur);
};


#endif //PROJET_TULLE_CHAUFFEURPANELINFO_H
