#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H

#include "Personne.h"
#include "Chauffeur.h"

class Admin : public Personne{
public:
    Admin(const string& nom, const string& prenom, const string& adresse, const string& telephone);

    static double gainChauffeur(Chauffeur *c);
    int coliesLivree(Chauffeur c);
    int coliesEnCours(Chauffeur c);
    int coliesEnAttente(Chauffeur c);
    int coliesEnValidation(Chauffeur c);
    static int nombreTrajets(Chauffeur* c);
    static double gainMoyenParTrajet(Chauffeur* c);
    static int nombreColis(Chauffeur* c);
    static double colisMoyenParTrajet(Chauffeur* c);
    static double poidTotal(Chauffeur* c);
    static double poidMoyenParTrajet(Chauffeur* c);
};


#endif //PROJET_TULLE_ADMIN_H
