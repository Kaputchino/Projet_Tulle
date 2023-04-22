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

    AdminPanelInfo::init();
    updateChauffeurList();
    updateDispatcherList();
}

void AdminPanel::updateChauffeurList() {
    for (Chauffeur * chauffeur : AdminPanelInfo::getListeChauffeurs()) {
        QString label = QString::fromStdString(chauffeur->getNom() + " " + chauffeur->getPrenom() + " " + to_string(chauffeur->getIdPersonne()) );
        ui->listChauffeurs->addItem(label);
    }
}

void AdminPanel::updateDispatcherList() {
    for (Dispatcher * dispatcher : AdminPanelInfo::getListeDispatchers()) {
        QString label = QString::fromStdString(dispatcher->getNom() + " " + dispatcher->getPrenom() + " " + to_string(dispatcher->getIdPersonne()) );
        ui->selectDispatcher->addItem(label);
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

    int successfullyAddUser = Personne::addUserToDb(name, firstname, address, email, password, role);

    if (!successfullyAddUser) {
        QMessageBox::warning(this, "Ajout Utilisateur", QString::fromStdString(Errors::readErrors()));
    } else {
        ui->emailField->clear();
        ui->nameField->clear();
        ui->passField->clear();
        ui->firstnameField->clear();
        ui->addrField->clear();
        QMessageBox::information(this, "Ajout reussi!", "Bravo! Vous avez creer la vie.");

        if (role == ROLE_CHAUFFEUR) {
            AdminPanelInfo::addChauffeurToList(Chauffeur::constructChauffeurFromId(successfullyAddUser));
            updateChauffeurList();
        } else if (role == ROLE_DISPATCHER) {
            AdminPanelInfo::addDispatcherToList(Dispatcher::constructDispatcherFromId(successfullyAddUser));
            updateDispatcherList();
        }
    }
}

void AdminPanel::clearButton() {
        ui->emailField->clear();
        ui->nameField->clear();
        ui->passField->clear();
        ui->firstnameField->clear();
        ui->addrField->clear();
}

