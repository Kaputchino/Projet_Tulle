#ifndef PROJET_TULLE_COMMON_H
#define PROJET_TULLE_COMMON_H


#include <string>
#include <vector>
#include <QtSql>
#include "core/headers/Chauffeur.h"

using namespace std;

extern vector<string> listeVille;
extern vector<Chauffeur *> listeChauffeur;
extern QSqlDatabase db;

#endif //PROJET_TULLE_COMMON_H
