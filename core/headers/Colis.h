#ifndef PROJET_TULLE_COLIS_H
#define PROJET_TULLE_COLIS_H
#include <string>
#include "Errors.h"

class Trajet;
class Dispatcher;
using namespace std;
class Colis {
public:
    Colis(string &villeArrivee, double poid);

    Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut, int idTrajet, int idDispatcher);
    Colis(int id, double poid, const string& villeArivee, const string& dateAjout, int statut);
    Colis(int id, double poid, const string &villeArivee, const string &dateAjout, int statut, int idDispatcher);

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

    Dispatcher *getDispatcher() const;

    void setDispatcher(Dispatcher *dispatcher);

    static string currentDate();

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
    Dispatcher* dispatcher;

    bool updateDispatcher();
};

#endif //PROJET_TULLE_COLIS_H
