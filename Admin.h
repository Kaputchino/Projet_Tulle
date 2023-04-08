#ifndef PROJET_TULLE_ADMIN_H
#define PROJET_TULLE_ADMIN_H


#include "Personne.h"

class Admin : public Personne{
public:
    Admin(string nom, string prenom, string adresse, string telephone);
};


#endif //PROJET_TULLE_ADMIN_H
