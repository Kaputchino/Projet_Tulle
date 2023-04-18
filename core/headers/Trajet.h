#ifndef PROJET_TULLE_TRAJET_H
#define PROJET_TULLE_TRAJET_H
#include <string>
#include "core/headers/Colis.h"
#include <vector>
#include "shared/Errors.h"
using namespace std;
class Trajet {
private:
    int idTrajet;
    int idChauffeur;
    string villeDepart;
    string villeArrivee;
    string horaireDepart;
    string horaireArrivee;
    double poids;
    double prix;
    int statuts;
    vector<Colis *> listeColis;
    static inline int totalTrajets = 0;
public:
    Trajet(int idChauffeur, const string &VilleDepart, const string &villeArrivee, const string &horaireDepart, const string &horaireArrivee, double poids, double prix);

    int getIdTrajet() const;

    int getIdChauffeur() const;

    void setIdChauffeur(int idChauffeur);

    const string &getVilleDepart() const;

    void setVilleDepart(const string &villeDepart);

    const string &getVilleArrivee() const;

    void setVilleArrivee(const string &villeArrivee);

    const string &getHoraireDepart() const;

    void setHoraireDepart(const string &horaireDepart);

    const string &getHoraireArrivee() const;

    void setHoraireArrivee(const string &horaireArrivee);

    double getPoids() const;

    void setPoids(double poids);

    double getPrix() const;

    void setPrix(double prix);

    int getStatuts() const;

    void setStatuts(int statuts);

    double getPoidEnCharge();

    void ajouterColis(Colis *colis);

    bool colieAjoutable(Colis *colis);

    int nbColis();

    void afficherTrajet();

    vector<Colis *> getListeColis();

};

#endif //PROJET_TULLE_TRAJET_H
