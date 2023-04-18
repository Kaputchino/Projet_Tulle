#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H

#include "Personne.h"
#include "Chauffeur.h"
#include "Dispatcher.h"

class Admin : public Personne{
public:
    Admin(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password);
    static double gainChauffeur(Chauffeur *c);
    static int coliesLivree(Chauffeur* c);
    static int coliesEnCoursLivraison(Chauffeur* c);
    static int coliesEnAttenteLivraison(Chauffeur* c);
    static int coliesEnDemandeLivraison(Dispatcher * d);
    int getIdAdmin() const;
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
