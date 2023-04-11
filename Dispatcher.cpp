#include "Dispatcher.h"
#include "sharedVariables.h"

Dispatcher::Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& telephone) : Personne(nom, prenom, adresse, telephone) {
    this->idDispatcher = getIdPersonne();
}

int Dispatcher::getIdDispatcher() {
    return idDispatcher;
}

bool Dispatcher::remplir(int n) {
    for (size_t i = 0; i < n; i++) {
        int indexVille = rand() % listeVille.size(); 
        int poidsRand = rand() % 16; 

        listeColis.push_back(
            Colis(listeVille.at(indexVille), poidsRand)
        );
    }

    return true;
}

bool Dispatcher::dispatch() {
    vector<Colis> unattributed;

    for(Colis colis : listeColis) {
        unattributed.push_back(colis);
        for (Chauffeur ch : listeChauffeur) {
            int indexTrajet = ch.getIndexTrajet(colis.getVilleArrivee());
            if (indexTrajet != -1) {
                Trajet * trajet = ch.getTrajetByIndex(indexTrajet);
                if (trajet->colieAjoutable(colis)) {
                    trajet->ajouterColis(colis);
                    unattributed.pop_back();
                    break;
                }
            }
        }
    }

    listeColis = unattributed;
    return unattributed.empty(); // true si tout est dispatchable
}

void Dispatcher::attribueColis(Colis c) {
    listeColis.push_back(c);
}
