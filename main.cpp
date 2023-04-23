#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include <QWidget>
#include "core/headers/initDB.h"
#include "interface/loginscreen.h"
#include "core/headers/Chauffeur.h"
#include <string>
#include <vector>
using namespace std;

//
// Ceci fut l'ancien main avant l'implementation de la BDD
// et de l'UI.
//

vector<string> listeVille = {"Tours","St-Pierre-Des-Corps","Tulle", "Strasbourg","Mulhouse",
                             "Breuschwickersheim","Illkirch-Graffenstaden","Oberschaeffolsheim","Souffelweyersheim","Breuschwickersheim","Geispolsheim","Agullana"};
vector<Chauffeur *> listeChauffeur;

QSqlDatabase db;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    try {
    initDB::linkDB();
    } catch(const std::exception& err) {
        cout << err.what() << endl;
        QWidget w;
        QMessageBox::critical(&w, "Error!", err.what());
        return -1;
    }

    LoginScreen loginPage;
    loginPage.show();

    return app.exec();
}




