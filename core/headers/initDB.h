#ifndef PROJET_TULLE_INITDB_H
#define PROJET_TULLE_INITDB_H
#include <string>
#include "Personne.h"
#include "Admin.h"
#include "Chauffeur.h"
#include "Dispatcher.h"

using namespace std;
class initDB {
public:
    static string readDataBasePath();
    static void linkDB();
    static int getIdFromLogin(string email, string password);
    static string getRoleFromId(int id);
    static string toHash(const string& password);
};


#endif //PROJET_TULLE_INITDB_H
