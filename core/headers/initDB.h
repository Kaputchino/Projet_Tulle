#ifndef PROJET_TULLE_INITDB_H
#define PROJET_TULLE_INITDB_H
#include <string>
#include "Personne.h"

using namespace std;
class initDB {
public:
    static string readDataBasePath();
    static void linkDB();
    static Personne* login(string email, string password);
    static string toHash(const string& password);
};


#endif //PROJET_TULLE_INITDB_H
