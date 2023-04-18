#ifndef PROJET_TULLE_CHAUFFEUR_H
#define PROJET_TULLE_CHAUFFEUR_H

#include "core/headers/Personne.h"
#include "core/headers/Trajet.h"
#include "core/headers/Colis.h"
#include <string>
#include <vector>

using namespace std;

class Chauffeur : public Personne{
public:
    Chauffeur(const string& nom, const string& prenom, const string& adresse, const string& telephone, const string& password);
    bool ajoutTrajet(Trajet *t);
    bool supprimerTrajet(Trajet *t);
    bool modifierTrajet(const Trajet* t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee, double poids, double prix);
    int getIndexTrajet(const string& villeArrivee);
    Trajet * getTrajetByIndex(int index);
    int getIdChauffeur() const;
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

private:
    vector<Trajet *> listeTrajet;
    int idChauffeur;
    vector <Colis *> getAllColis();
};

#endif //PROJET_TULLE_CHAUFFEUR_H
