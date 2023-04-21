#ifndef PROJET_TULLE_PERSONNE_H
#define PROJET_TULLE_PERSONNE_H
#include <string>
#include <iostream>
#include "Errors.h"
using namespace std;

class Personne {
    private:
        string* toHash(string password);
        static inline int totalPersonne = 0;
        string nom;
        string prenom;
        string adresse;
        string email;
        string password;
        string role;
        bool updateNom();
        bool updatePrenom();
        bool updateAdresse();
        bool updateEmail();
        bool updatePassword();
        bool updateRole();
        bool addIntoDb();
    public:
    int idPersonne;

    Personne(const string& nom,
                 const string& prenom,
                 const string& adresse,
                 const string& email,
                 const string& password,
                 const string& role
                 );
    Personne(int id,
             const string& nom,
             const string& prenom,
             const string& adresse,
             const string& email,
             const string& password,
             const string& role
    );

        string getNom();

        string getPrenom();

        string getAdresse();

        string getEmail();

        string getPassword();

        string getRole();

        int getIdPersonne() const;

        void setNom(const string &nom);

        void setPrenom(const string &prenom);

        void setAdresse(const string &adresse);

        void setEmail(const string &email);

        void setPassword(const string &email);

        void setIdPersonne(int id);

        void afficherPersonne();

        static int getTotalPersonne();

    Personne *findPersonneById(int id);
};

#endif //PROJET_TULLE_PERSONNE_H
