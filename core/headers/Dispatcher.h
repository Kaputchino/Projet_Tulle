#ifndef PROJET_TULLE_DISPATCHER_H
#define PROJET_TULLE_DISPATCHER_H

#include "core/headers/Personne.h"
#include <vector>
#include "core/headers/Colis.h"
#include "shared/Errors.h"
using namespace std;
class Dispatcher : public Personne{
public:
    Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password);
    bool remplir(int n);
    bool dispatch();
    bool attribueColis(Colis *c);
    int getNombreColisDispatchable();
private:
    vector<Colis *> listeColis;
    int idDispatcher;
};

#endif //PROJET_TULLE_DISPATCHER_H
