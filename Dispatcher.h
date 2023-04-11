#ifndef PROJET_TULLE_DISPATCHER_H
#define PROJET_TULLE_DISPATCHER_H

#include "Personne.h"
#include <vector>
#include "Colis.h"
using namespace std;
class Dispatcher : public Personne{
public:
    Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& telephone);
    bool remplir(int n);
    bool dispatch();
    void attribueColis(Colis *c);
    int getIdDispatcher();
private:
    vector<Colis *> listeColis;
    int idDispatcher;
};

#endif //PROJET_TULLE_DISPATCHER_H
