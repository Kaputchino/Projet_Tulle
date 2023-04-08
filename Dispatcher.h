#ifndef PROJET_TULLE_DISPATCHER_H
#define PROJET_TULLE_DISPATCHER_H


#include "Personne.h"
#include "vector"
#include "Colis.h"
using namespace std;
class Dispatcher : public Personne{
public:
    Dispatcher(string nom, string prenom, string adresse, string telephone);
    bool remplir(int n);
    bool dispatch();
private:
    vector<Colis> listeColis;
};


#endif //PROJET_TULLE_DISPATCHER_H
