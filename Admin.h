#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H

#include "Personne.h"
#include "Chauffeur.h"

class Admin : public Personne{
public:
    Admin();
    double gainChauffeur(Chauffeur c);
    int trajetChauffeur(Chauffeur c);
    int coliesLivree(Chauffeur c);
    int coliesEnCours(Chauffeur c);
    int coliesEnAttente(Chauffeur c);
    int coliesEnValidation(Chauffeur c);
    int nombreTrajets(Chauffeur c);
};


#endif //PROJET_TULLE_ADMIN_H
