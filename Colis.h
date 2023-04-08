//
// Created by andre on 08/04/2023.
//

#ifndef PROJET_TULLE_COLIS_H
#define PROJET_TULLE_COLIS_H
#include "string"
using namespace std;
class Colis {
public:
    Colis();

    int getIdColis() const;

    const string &getVilleArrivee() const;

    void setVilleArrivee(const string &villeArrivee);

    const string &getDateAjoutColis() const;

    void setDateAjoutColis(const string &dateAjoutColis);

    int getStatut() const;

    void setStatut(int statut);

private:
    int idColis;
    string villeArrivee;
    string dateAjoutColis;
    int statut;

};


#endif //PROJET_TULLE_COLIS_H
