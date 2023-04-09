#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H

#include "Personne.h"
#include "Chauffeur.h"

class Admin : public Personne{
public:
    Admin();

    Admin(string nom, string prenom, string adresse, string telephone);

    static double gainChauffeur(Chauffeur *c);
    int trajetChauffeur(Chauffeur c);
    int coliesLivree(Chauffeur c);
    int coliesEnCours(Chauffeur c);
    int coliesEnAttente(Chauffeur c);
    int coliesEnValidation(Chauffeur c);
    static int nombreTrajets(Chauffeur* c);
};


#endif //PROJET_TULLE_ADMIN_H
