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
private:
    vector<Colis> listeColis;
};

#endif //PROJET_TULLE_DISPATCHER_H
