#include "Dispatcher.h"
#include "main.cpp"

Dispatcher::Dispatcher(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {

}

bool Dispatcher::remplir(int n) {
    for (size_t i = 0; i < n; i++) {
        int indexVille = rand() % listeVille.size(); 
        int poidsRand = rand() % 16; 

        listeColis.push_back(
            Colis(listeVille.at(indexVille), poidsRand)
        );
    }
}

bool Dispatcher::dispatch() {
    for(Colis colis : listeColis) {
        for (Chauffeur ch : listeChauffeur) {
            int indexTrajet = ch.getIndexTrajet(colis.getVilleArrivee());
            if (indexTrajet != -1) {
                Trajet trajet = ch.getTrajetByIndex(indexTrajet);
                if (trajet.colieAjoutable(colis)) {
                    trajet.ajouterColis(colis);
                    break;
                }
            }
        }
    }

    return false;
}
