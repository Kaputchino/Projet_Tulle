#include "Dispatcher.h"
#include "common.h"

Dispatcher::Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& telephone) : Personne(nom, prenom, adresse, telephone) {

}

bool Dispatcher::remplir(int n) {
    for (size_t i = 0; i < n; i++) {
        int indexVille = rand() % listeVille.size();
        int poidsRand = rand() % 16;
        Colis * colis = new Colis(listeVille.at(indexVille), poidsRand);

        listeColis.push_back(
                colis
        );
    }

    return true;
}

bool Dispatcher::dispatch() {
    vector<Colis *> unattributed;
    for(Colis * colis : listeColis) {
        unattributed.push_back(colis);
        for (Chauffeur * ch : listeChauffeur) {
            int indexTrajet = ch->getIndexTrajet(colis->getVilleArrivee());

            if (indexTrajet != -1) {
                Trajet * trajet = ch->getTrajetByIndex(indexTrajet);
                if (trajet->colieAjoutable(colis)) {
                    trajet->ajouterColis(colis);
                    unattributed.pop_back();
                    break;
                }
            }
        }
    }

    return unattributed.empty();
}

void Dispatcher::attribueColis(Colis *c) {
    listeColis.push_back(c);
}
