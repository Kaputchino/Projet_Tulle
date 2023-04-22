#ifndef PROJET_TULLE_CHAUFFEUR_H
#define PROJET_TULLE_CHAUFFEUR_H
#include "Errors.h"
#include <string>
#include <vector>
#include "Personne.h"
#include "Trajet.h"
#include "Colis.h"

using namespace std;

class Chauffeur : public Personne {
public:
    Chauffeur(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password);

    Chauffeur(int idChauffeur, const string &nom, const string &prenom, const string &adresse, const string &email,
              const string &password);
    
    bool ajoutTrajet(Trajet *t);
    bool supprimerTrajet(Trajet *t);
    bool modifierTrajet(const Trajet* t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee, double poids, double prix);
    int getIndexTrajet(const string& villeArrivee);
    Trajet * getTrajetByIndex(int index);
    int getNbTrajet();
    double gain();
    int nbColis();
    double poidTotal();
    bool validerTrajet(Trajet *t);
    bool delancheLivraison(Trajet *t);
    bool declareLivraison(Trajet *t);
    int  indexTrajetDansListe(int idTrajet);
    int getNbcoliesLivree();
    int getNbColiesEnCoursLivraison();
    int getNbColiesEnAttenteLivraison();
    static Chauffeur* constructChauffeurFromId(int id);
    bool loadTrajetFromDB();
    static vector<Chauffeur*> getListAllChauffeurAndLoad();
    vector<Trajet *> getListTrajets();
private:
    vector<Trajet *> listeTrajet;
    vector <Colis *> getAllColis();
};

#endif //PROJET_TULLE_CHAUFFEUR_H
