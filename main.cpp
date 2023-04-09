#include <iostream>
#include <string>
#include <vector>
#include "Chauffeur.h"
#include "Dispatcher.h"
#include "Trajet.h"
#include "Colis.h"
using namespace std;

static vector<string> listeVille;
static vector<Dispatcher> listeDispatcher;
static vector<Chauffeur> listeChauffeur;

int main(int argc, char const *argv[]) {
    string villeArriveeA = "Tours";
    string villeArriveeB = "Paris";
    
    listeVille.push_back(villeArriveeA);
    listeVille.push_back(villeArriveeB);
    
    string nomA = "Perout";
    string prenomA = "Fred";
    string addrA = "105 Rue Constantinople";
    string telepA = "0103040506";
    Chauffeur chauffeurA = Chauffeur(nomA, prenomA, addrA, telepA);
    Chauffeur chauffeurB = Chauffeur("Benito", "Benoit", "3 place Vandome", "0909997867");

    chauffeurA.afficherPersonne();
    chauffeurB.afficherPersonne();

    Colis colisA = Colis(villeArriveeA, 10.2);
    Colis colisB = Colis(villeArriveeB, 2.7);
    Colis colisBA = Colis(villeArriveeB, 3.1);
    Colis colisBB = Colis(villeArriveeB, 1.2);

    Trajet trajetA = Trajet(chauffeurA.getIdChauffeur(), "Orlean", villeArriveeA, "12h20", "15h20", 20, 150);
    Trajet trajetB = Trajet(chauffeurB.getIdChauffeur(), "Rouen", villeArriveeB, "10h20", "14h40", 34, 500);

    return 0;
}
