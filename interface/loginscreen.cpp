#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "core/headers/initDB.h"
#include "core/headers/Personne.h"
#include "core/headers/common.h"
#include "adminpanel.h"
#include "chauffeurpanel.h"
#include "dispatcherpanel.h"
#include <QMessageBox>


LoginScreen::LoginScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    QObject::connect(ui->connectionButton, &QPushButton::clicked, this, &LoginScreen::connectClicked);
    QObject::connect(ui->quitButton, &QPushButton::clicked, this, &LoginScreen::quitClicked);
    QObject::connect(ui->resetButton, &QPushButton::clicked, this, &LoginScreen::resetClicked);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::connectClicked()
{
    QString email =ui->emailEdit->text();
    QString password =ui->passEdit->text();

    int id = initDB::getIdFromLogin(email.toStdString(), password.toStdString());
    if(id != -1) {
        string role = initDB::getRoleFromId(id);

        if (role == ROLE_ADMIN) {
            hide();
            AdminPanelInfo::setLogged(id);
            AdminPanel * adminUI = new AdminPanel();
            adminUI->show();
            close();
        } else if (role == ROLE_CHAUFFEUR) {
            hide();
            ChauffeurPanel * chauffeurUI = new ChauffeurPanel();
            chauffeurUI->show();
            close();
        } else if (role == ROLE_DISPATCHER) {
            hide();
            DispatcherPanelInfo::setLogged(id);
            DispatcherPanel * dispatcherUi = new DispatcherPanel();
            dispatcherUi->show();
            close();
        } else {
            QMessageBox::information(this, "Woopps!", "Vous avez un role non prevu! Woopsy.");
            this->close();
        }
    } else {
        QMessageBox::warning(this, "Login", "Il semblerait que votre email ou votre mot de passe soit incorrecte."
                                            "\nContactez un administrateur si l'erreur persiste.");
    }
}

void LoginScreen::resetClicked()
{
    ui->emailEdit->clear();
    ui->passEdit->clear();
}

void LoginScreen::quitClicked()
{
    int res = QMessageBox::question(this, "Confirmation", "Souhaitez-vous quitter l'application?", "Oui", "Non");

    if ( res == 0 ) {
        this->close();
    }
}


