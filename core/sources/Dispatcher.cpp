#include <random>
#include "core/headers/Dispatcher.h"
#include "shared/common.h"

Dispatcher::Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& telephone) : Personne(nom, prenom, adresse, telephone) {
    this->idDispatcher = getIdPersonne();
}

bool Dispatcher::remplir(int n) {
    random_device rseed;
    mt19937 rgen(rseed());
    uniform_int_distribution<int> randomPoids(0,16);
    uniform_int_distribution<int> randomVille(0, listeVille.size() -1);

    for (size_t i = 0; i < n; i++) {
        Colis * colis = new Colis(listeVille.at(randomVille(rgen)), randomPoids(rgen));
        colis->setStatut(1);
        listeColis.push_back(
                colis
        );
    }

    return true;
}

bool Dispatcher::dispatch() {
    vector<Colis *> unattributed;
    vector<Trajet *> solicited;
    for(Colis * colis : listeColis) {
        unattributed.push_back(colis);
        for (Chauffeur * ch : listeChauffeur) {
            int indexTrajet = ch->getIndexTrajet(colis->getVilleArrivee());

            if (indexTrajet != -1) {
                Trajet * trajet = ch->getTrajetByIndex(indexTrajet);
                if (trajet->colieAjoutable(colis)) {
                    colis->setStatut(2);
                    trajet->ajouterColis(colis);
                    unattributed.pop_back();
                    break;
                }
            }
        }
    }

    listeColis = unattributed;
    return unattributed.empty();
}

bool Dispatcher::attribueColis(Colis *c) {

    if (c->getStatut() != 0) {
        return false;
    }

    c->setStatut(1);
    listeColis.push_back(c);

    return true;
}

int Dispatcher::getNombreColisDispatchable() {
    return listeColis.size();
}
