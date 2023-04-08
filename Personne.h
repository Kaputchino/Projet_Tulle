#include <iostream>
#include <string>
#ifndef PROJET_TULLE_PERSONNE_H
#define PROJET_TULLE_PERSONNE_H

using namespace std;

class Personne {
    private:
        static int totalPersonne;
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
        int getIdPersonne();
        void setNom(string nom);
        void setPrenom(string prenom);
        void setAdresse(string adresse);
        void setTelephone(string telephone);
        void afficherPersonne();
        static int getTotalPersonne();
};

int Personne::totalPersonne = 1;


#endif //PROJET_TULLE_PERSONNE_H
