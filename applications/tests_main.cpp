#include <iostream>
#include <string>
#include <vector>
#include "core/headers/Chauffeur.h"
#include "core/headers/Dispatcher.h"
#include "core/headers/Trajet.h"
#include "core/headers/Colis.h"

using namespace std;

vector<string> listeVille = {"Tours","St-Pierre-Des-Corps","Tulle","Valence","Nouméa","Arachon","Casablanca","Bonifacio","Colmar","Montparnasse","Narbonne","Strasbourg","Brumath","Hoerdt","Haguenau","Mulhouse","Breuschwickersheim","Illkirch-Graffenstaden","Oberschaeffolsheim","Souffelweyersheim","Breuschwickersheim","Geispolsheim","Agullana","Lake Mary","Milwaukee"};
vector<Dispatcher *> listeDispatcher;
vector<Chauffeur *> listeChauffeur;

int main(int argc, char** argv) {
    string villeArriveeA = "Tours";
    string villeArriveeB = "Paris";

    listeVille.push_back(villeArriveeA);
    listeVille.push_back(villeArriveeB);

    string nomA = "Perout";
    string prenomA = "Fred";
    string addrA = "105 Rue Constantinople";
    string emailA = "email@email.com";
    string passA = "1234";
    Chauffeur chauffeurA = Chauffeur(nomA, prenomA, addrA, emailA, passA);
    Chauffeur chauffeurB = Chauffeur("Benito", "Benoit", "3 place Vandome", "ben@protonmail.org", "ABCD");
    listeChauffeur.push_back(&chauffeurA);
    listeChauffeur.push_back(&chauffeurB);

    cout << "Chauffeur A: " << endl;
    chauffeurA.afficherPersonne();
    cout << "\nChauffeur B: " << endl;
    chauffeurB.afficherPersonne();

    cout << "\n------------\n" << endl;

    Trajet trajetA = Trajet(chauffeurA.getIdChauffeur(), "Orlean", listeVille.at(1), "12h20", "15h20", 20, 150);
    Trajet trajetB = Trajet(chauffeurB.getIdChauffeur(), "Rouen", listeVille.at(1), "10h20", "14h40", 34, 500);
    Trajet trajetC = Trajet(chauffeurA.getIdChauffeur(), "Charleroi", listeVille.at(2), "2h10", "5h34", 45, 1312);
    chauffeurA.ajoutTrajet(&trajetA);
    chauffeurA.ajoutTrajet(&trajetC);
    cout << "Addition de 2 trajets, chauffeurA a " << chauffeurA.getNbTrajet() << " trajets" << endl;
    chauffeurA.supprimerTrajet(&trajetC);
    cout << "Suppression de 1 trajets, chauffeurA a " << chauffeurA.getNbTrajet() << " trajet" << endl;
    chauffeurA.ajoutTrajet(&trajetB);
    cout << "Ajout d'un trajet qui ne lui appartient pas, chauffeurA a tjrs  " << chauffeurA.getNbTrajet() << " trajet" << endl;
    chauffeurA.supprimerTrajet(&trajetB);
    cout << "Deletion d'un trajet qui n'est pas dans sa liste, chauffeurA a tjrs " << chauffeurA.getNbTrajet() << " trajet" << endl;
    chauffeurB.ajoutTrajet(&trajetB);

    cout << "\n------------\n" << endl;

    cout << "\nAvant modification du trajetA: " << endl;
    trajetA.afficherTrajet();
    cout << "\nApres modification du trajetA: " << endl;
    chauffeurA.modifierTrajet(&trajetA, "Blois", listeVille.at(0), "13h10", "16h20", 50, 250);
    trajetA.afficherTrajet();

    cout << "\n------------\n" << endl;
    Dispatcher dispatcherA = Dispatcher("Jean", "Pierre", "32 rue esquimot", "pierre.qui.roule@gmail.com", "789");
    Dispatcher dispatcherB = Dispatcher("Jean2", "Pierre2", "322 rue esquimot2", "pierre2@gmail.com", "234");
    Colis colisA = Colis(villeArriveeA, 10.2);
    cout << "Status colisA: " << colisA.getStatut()  << endl;
    dispatcherA.attribueColis(&colisA);
    cout << "Status colisA apres attribution au dispatcherA: " << colisA.getStatut()  << endl;
    cout << "Taille lise colis du dispatcherB: " << dispatcherB.getNombreColisDispatchable()  << endl;
    dispatcherB.attribueColis(&colisA);
    cout << "Taille lise colis du dispatcherB apres attribution d'un coli qui est deja dans le dispatcher A: " << dispatcherB.getNombreColisDispatchable() << endl;
    cout << "\n------------\n" << endl;

    cout << "Taille lise colis du dispatcherA: " << dispatcherA.getNombreColisDispatchable() << endl;
    cout << "Taille lise colis du dispatcherB: " << dispatcherB.getNombreColisDispatchable() << endl;
    cout << "Creation aleatoire de 50 colis pour le dispatcher A et B" << endl;
    dispatcherA.remplir(50);
    dispatcherB.remplir(50);
    cout << "Taille lise colis du dispatcherA: " << dispatcherA.getNombreColisDispatchable() << endl;
    cout << "Taille lise colis du dispatcherB: " << dispatcherB.getNombreColisDispatchable() << endl;
    cout << "\n------------\n" << endl;

    cout << "Dispatchage automatique des colis en fonction des poids, destinations et statuts." << endl;
    dispatcherA.dispatch();
    dispatcherB.dispatch();
    cout << "Taille lise colis du dispatcherA: " << dispatcherA.getNombreColisDispatchable() << endl;
    cout << "Taille lise colis du dispatcherB: " << dispatcherB.getNombreColisDispatchable() << endl;
    cout << "Poids en charge trajetA: " << trajetA.getPoidEnCharge() << endl;
    cout << "Poids en charge trajetB: " << trajetB.getPoidEnCharge() << endl;

    return 1;
}
