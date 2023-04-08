#ifndef PROJET_TULLE_CHAUFFEUR_H
#define PROJET_TULLE_CHAUFFEUR_H


#include "Personne.h"
#include "vector"
#include "Trajet.h"
#include "string"
using namespace std;
class Chauffeur : public Personne{
public:
    Chauffeur(string nom, string prenom, string adresse, string telephone);
    bool ajoutTrajet(Trajet t);
    bool supprimerTrajet(Trajet t);
    bool modifierTrajet(Trajet t, string villeDepart, string villeArrivee, string horaireDepart, string horaireArrivee, double poids, double prix);
    int getIndexTrajet(string villeArrivee);
private:
    vector<Trajet> listeTrajet;
    int idChauffeur;
public:
    int getIdChauffeur() const;
};


#endif //PROJET_TULLE_CHAUFFEUR_H
