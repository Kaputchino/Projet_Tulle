#include <string>
#ifndef PROJET_TULLE_PERSONNE_H
#define PROJET_TULLE_PERSONNE_H

using namespace std;

class Personne {
    static int totalPersonnes;
    private:
        int idPersonne;
        string nom;
        string premom;
        string adresse;
        string telephone;
    public:
        Personne(string nom, string prenom, string adresse, string telephone);
        string getNom();
        string getPrenom();
        string getAdresse();
        string getTelephone();
        void setNom(string nom);
        void setPrenom(string prenom);
        void setAdresse(string adresse);
        void setTelephone(string telephone);
};

int Personne::totalPersonnes = 1;


#endif //PROJET_TULLE_PERSONNE_H
