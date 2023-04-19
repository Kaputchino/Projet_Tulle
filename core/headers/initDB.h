//
// Created by andre on 19/04/2023.
//

#ifndef PROJET_TULLE_INITDB_H
#define PROJET_TULLE_INITDB_H
#include "string"

using namespace std;
class initDB {
public:
    static string readDataBasePath();
    static void linkDB();
};


#endif //PROJET_TULLE_INITDB_H
