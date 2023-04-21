#ifndef PROJET_TULLE_COMMON_H
#define PROJET_TULLE_COMMON_H

#define COLIS_CREATION 0
#define COLIS_SOLICITATION_LIVRAISON 1
#define COLIS_VALIDATION_LIVRAISON 2
#define COLIS_LIVRAISON_EN_COURS 3
#define COLIS_LIVRAISON_FAITE 4

#define TRAJET_CREATION 0
#define TRAJET_SOLICITATION 1
#define TRAJET_VALIDATION 2
#define TRAJET_LIVRAISON_EN_COURS 3
#define TRAJET_LIVRAISON_FAITE 4

#include <string>
#include <vector>
#include <QSqlDatabase>
#include "core/headers/Chauffeur.h"

using namespace std;

extern vector<string> listeVille;
extern vector<Chauffeur *> listeChauffeur;
extern QSqlDatabase db;




#endif //PROJET_TULLE_COMMON_H
