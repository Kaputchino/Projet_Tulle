#include "loginscreen.h"
#include "ui_loginscreen.h"
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

    if(email == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username & password correct");
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


