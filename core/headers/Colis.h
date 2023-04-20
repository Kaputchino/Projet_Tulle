#ifndef PROJET_TULLE_COLIS_H
#define PROJET_TULLE_COLIS_H
#include <string>
#include "Errors.h"

class Trajet;

using namespace std;
class Colis {
public:
    Colis(string &villeArrivee, double poid);

    Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut, int idTrajet);

    int getIdColis() const;

    const string &getVilleArrivee() const;

    void setVilleArrivee(const string &villeArrivee);

    const string &getDateAjoutColis() const;

    void setDateAjoutColis(const string &dateAjoutColis);

    int getStatut() const;

    void setStatut(int statut);

    double getPoid() const;

    void setPoid(double poid);

    Trajet* getTrajet() const;

    void setTrajet(Trajet *trajet);

    static vector<Colis *> getColisAttente();


private:
    int idColis;
    string villeArrivee;
    double poid;
    string dateAjoutColis;
    int statut;
    static inline int nbColisTotal = 0;
    bool addIntoDb();
    bool updatePoid();
    bool updateVille();
    bool updateDate();
    bool updateStatut();
    bool updateTrajet();
    Trajet* trajet;

};

#endif //PROJET_TULLE_COLIS_H
