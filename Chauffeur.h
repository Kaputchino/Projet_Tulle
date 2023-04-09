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
    bool modifierTrajet(const Trajet& t, const string& villeDepart, const string& villeArrivee, const string& horaireDepart, const string& horaireArrivee, double poids, double prix);
    int getIndexTrajet(string villeArrivee);
    Trajet getTrajetByIndex(int index);
    int getIdChauffeur() const;
    int getNbTrajet();
    double gain();

private:
    vector<Trajet> listeTrajet;
    int idChauffeur;
};


#endif //PROJET_TULLE_CHAUFFEUR_H
