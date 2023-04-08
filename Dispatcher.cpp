#include "Dispatcher.h"

Dispatcher::Dispatcher(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {

}

bool Dispatcher::remplir(int n) {
    return false;
}

bool Dispatcher::dispatch() {
    return false;
}
