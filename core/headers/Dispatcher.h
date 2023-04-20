#ifndef PROJET_TULLE_DISPATCHER_H
#define PROJET_TULLE_DISPATCHER_H
#include <vector>
#include "Errors.h"
#include "Personne.h"
#include "Colis.h"

using namespace std;
class Dispatcher : public Personne{
public:
    Dispatcher(const string& nom, const string& prenom, const string& adresse, const string& email, const string& password);
    bool remplir(int n);
    bool dispatch();
    bool attribueColis(Colis *c);
    int getNombreColisDispatchable();
    vector<Colis> getColisAttente();
private:
    vector<Colis *> listeColis;
};

#endif //PROJET_TULLE_DISPATCHER_H
