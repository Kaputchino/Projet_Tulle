#ifndef PROJET_TULLE_PERSONNE_H
#define PROJET_TULLE_PERSONNE_H
#include <string>
#include <iostream>

using namespace std;

class Personne {
    private:
        static inline  int totalPersonne = 0;
        int idPersonne;
        string nom;
        string prenom;
        string adresse;
        string telephone;
    public:
        Personne(const string& nom, const string& prenom, const string& adresse, const string& telephone);

        string getNom();

        string getPrenom();

        string getAdresse();

        string getTelephone();

        int getIdPersonne() const;

        void setNom(const string &nom);

        void setPrenom(const string &prenom);

        void setAdresse(const string &adresse);

        void setTelephone(const string &telephone);

        void afficherPersonne();

        static int getTotalPersonne();
};

#endif //PROJET_TULLE_PERSONNE_H
