#include "Dispatcher.h"
#include "main.cpp"

Dispatcher::Dispatcher(string nom, string prenom, string adresse, string telephone) : Personne(nom, prenom, adresse, telephone) {
    for (size_t i = 0; i < 16; i++)
    {
        int indexVille = rand() % listeVille.size(); 
        int poidsRand = rand() % 16; 

        listeColis.push_back()
    }
    
}

bool Dispatcher::remplir(int n) {
    return false;
}

bool Dispatcher::dispatch() {
    return false;
}
