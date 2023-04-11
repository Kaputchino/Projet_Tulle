#include <iostream>
#include <string>
#include <vector>
#include "Chauffeur.h"
#include "Dispatcher.h"
#include "Trajet.h"
#include "Colis.h"
#include "common.h"
using namespace std;

vector<string> listeVille = {"Tours","St-Pierre-Des-Corps","Tulle","Valence","Nouméa","Arachon","Casablanca","Bonifacio","Colmar","Montparnasse","Narbonne","Strasbourg","Brumath","Hoerdt","Haguenau","Mulhouse","Breuschwickersheim","Illkirch-Graffenstaden","Oberschaeffolsheim","Souffelweyersheim","Breuschwickersheim","Geispolsheim","Agullana","Lake Mary","Milwaukee"};
vector<Dispatcher *> listeDispatcher;
vector<Chauffeur *> listeChauffeur;

int main(int argc, char const *argv[]) {
    srand((unsigned) time(0)); // seeding for random number generation

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

    listeChauffeur.push_back(&chauffeurA);
    listeChauffeur.push_back(&chauffeurB);

    Trajet trajetA = Trajet(chauffeurA.getIdChauffeur(), "Orlean", listeVille.at(1), "12h20", "15h20", 20, 150);
    Trajet trajetB = Trajet(chauffeurB.getIdChauffeur(), "Rouen", listeVille.at(1), "10h20", "14h40", 34, 500);
    chauffeurA.ajoutTrajet(&trajetA);
    chauffeurA.ajoutTrajet(&trajetB);
    cout << "Apres addition de 2 trajets chauffeurA possede " << chauffeurA.getNbTrajet() << " trajets" << endl;
    chauffeurA.supprimerTrajet(trajetB);
    cout << "Apres suppression de 1 trajets chauffeurA possede " << chauffeurA.getNbTrajet() << " trajet" << endl;
    chauffeurB.ajoutTrajet(&trajetB);
    cout << "\nAvant modification du trajetA: " << endl;
    trajetA.afficherTrajet();

    cout << "\nApres modification du trajetA: " << endl;
    chauffeurA.modifierTrajet(trajetA, "Blois", listeVille.at(0), "13h10", "16h20", 50, 250);
    trajetA.afficherTrajet();

    Colis colisA = Colis(villeArriveeA, 10.2);
    Colis colisB = Colis(villeArriveeB, 2.7);
    Colis colisBA = Colis(villeArriveeB, 3.1);
    Colis colisBB = Colis(villeArriveeB, 1.2);

    Dispatcher dispatcherA = Dispatcher("Jean", "Pierre", "32 rue esquimot", "09879809");
    dispatcherA.remplir(50);
    dispatcherA.dispatch();
    Dispatcher dispatcherB = Dispatcher("Jean2", "Pierre2", "322 rue esquimot2", "02379509");
    dispatcherB.remplir(50);
    dispatcherB.dispatch();

    cout << "Poids en charge trajet A: " << trajetA.getPoidEnCharge() << endl;
    cout << "Poids en charge trajet B: " << trajetB.getPoidEnCharge() << endl;

    return 0;
}
