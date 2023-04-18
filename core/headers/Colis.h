#ifndef PROJET_TULLE_COLIS_H
#define PROJET_TULLE_COLIS_H
#include <string>
#include "shared/Errors.h"
using namespace std;
class Colis {
public:
    Colis(string &villeArrivee, double poid);

    int getIdColis() const;

    const string &getVilleArrivee() const;

    void setVilleArrivee(const string &villeArrivee);

    const string &getDateAjoutColis() const;

    void setDateAjoutColis(const string &dateAjoutColis);

    int getStatut() const;

    void setStatut(int statut);

    int getPoid() const;

    void setPoid(double poid);

private:
    int idColis;
    string villeArrivee;
    int poid;
    string dateAjoutColis;
    int statut;
    static inline int nbColisTotal = 0;

};

#endif //PROJET_TULLE_COLIS_H
