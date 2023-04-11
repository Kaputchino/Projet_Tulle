#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H

#include "Personne.h"
#include "Chauffeur.h"

class Admin : public Personne{
public:
    Admin();
    Admin(const string& nom, const string& prenom, const string& adresse, const string& telephone);
    static double gainChauffeur(Chauffeur *c);
    static int coliesLivree(Chauffeur* c);
    static int coliesEnCoursLibraison(Chauffeur* c);
    static int coliesEnAttenteLivraison(Chauffeur* c);
    static int coliesEnValidationLivraison(Chauffeur* c);
    int getIdAdmin();
    static int nombreTrajets(Chauffeur* c);
    static double gainMoyenParTrajet(Chauffeur* c);
    static int nombreColis(Chauffeur* c);
    static double colisMoyenParTrajet(Chauffeur* c);
    static double poidTotal(Chauffeur* c);
    static double poidMoyenParTrajet(Chauffeur* c);
private:
    int idAdmin;
};


#endif //PROJET_TULLE_ADMIN_H
