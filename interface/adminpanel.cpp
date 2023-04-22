#include <QMessageBox>
#include "adminpanel.h"
#include "ui_adminpanel.h"
#include "core/headers/common.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);

    ui->roleField->addItems({ROLE_ADMIN, ROLE_DISPATCHER, ROLE_CHAUFFEUR});

    QObject::connect(ui->addUsrButton, &QPushButton::clicked, this, &AdminPanel::addPlayerButton);
    QObject::connect(ui->resetUserButton, &QPushButton::clicked, this, &AdminPanel::clearButton);

    for (Chauffeur * chauffeur : Chauffeur::getListAllChauffeur()) {
        QString label = QString::fromStdString(chauffeur->getNom());
        ui->listChauffeurs->addItem(label);
    }

}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::addPlayerButton() {
    Errors::init();

    string email = ui->emailField->text().toStdString();
    string name = ui->nameField->text().toStdString();
    string password = ui->passField->text().toStdString();
    string firstname = ui->firstnameField->text().toStdString();
    string address = ui->addrField->text().toStdString();
    string role = ui->roleField->currentText().toStdString();

    bool successfullyAddUser = Personne::addUserToDb(name, firstname, address, email, password, role);

    if (!successfullyAddUser) {
        QMessageBox::warning(this, "Ajout Utilisateur", QString::fromStdString(Errors::readErrors()));
    } else {
        ui->emailField->clear();
        ui->nameField->clear();
        ui->passField->clear();
        ui->firstnameField->clear();
        ui->addrField->clear();
        QMessageBox::information(this, "Ajout reussi!", "Bravo! Vous avez creer la vie.");
    }
}

void AdminPanel::clearButton() {
        ui->emailField->clear();
        ui->nameField->clear();
        ui->passField->clear();
        ui->firstnameField->clear();
        ui->addrField->clear();
}

