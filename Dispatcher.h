#ifndef PROJET_TULLE_DISPATCHER_H
#define PROJET_TULLE_DISPATCHER_H


#include "Personne.h"
#include "vector"
#include "Colis.h"
using namespace std;
class Dispatcher : public Personne{
public:
    Dispatcher();
    bool remplir(int n);
    bool dispatch();
private:
    vector<Colis> listColis;
};


#endif //PROJET_TULLE_DISPATCHER_H
