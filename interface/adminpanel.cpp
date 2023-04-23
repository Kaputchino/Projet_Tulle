#include <QMessageBox>
#include <iostream>
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
    QObject::connect(ui->listChauffeurs, &QListWidget::itemClicked, this, &AdminPanel::selectChauffeur);
    QObject::connect(ui->listTrajets, &QListWidget::itemClicked, this, &AdminPanel::selectTrajet);
    QObject::connect(ui->selectDispatcher, &QComboBox::textActivated, this, &AdminPanel::selectDispacher);
    QObject::connect(ui->packetQueue, &QListWidget::itemClicked, this, &AdminPanel::selectColisDispatcher);
    QObject::connect(ui->unattributedPacketList, &QListWidget::itemClicked, this, &AdminPanel::selectColis);
    QObject::connect(ui->givePacketButton, &QPushButton::clicked, this, &AdminPanel::attribuerColisBoutton);

    ui->statChauffeur->setReadOnly(true);
    ui->statDispatcher->setReadOnly(true);
    ui->statTrajet->setReadOnly(true);
    ui->givePacketButton->setDisabled(true);

    loadChauffeurList();
    loadDispatcherList();
    loadListeColis();
}

void AdminPanel::selectChauffeur() {
    AdminPanelInfo::setChauffeur(ui->listChauffeurs->currentRow());
    ui->listTrajets->clear();
    ui->statTrajet->clear();
    loadTrajetList();
    updateStatChauffeur();
}

void AdminPanel::selectTrajet() {
    AdminPanelInfo::setTrajet(ui->listTrajets->currentRow());
    updateStatTrajet();
}

void AdminPanel::selectDispacher() {
    AdminPanelInfo::setDispacher(ui->selectDispatcher->currentIndex());
    ui->packetQueue->clear();
    loadColisDispacher();
    updateStatDispacher();

}

void AdminPanel::selectColisDispatcher() {
    ui->givePacketButton->setDisabled(true);
}

void AdminPanel::attribuerColisBoutton() {
    int index = ui->unattributedPacketList->currentRow();
    Colis * cl = AdminPanelInfo::getColisEnAttente().at(index);
    AdminPanelInfo::removeColisEnAttente(index);
    AdminPanelInfo::currDispacher()->attribueColis(cl);
    ui->unattributedPacketList->clear();
    ui->packetQueue->clear();
    loadColisDispacher();
    loadListeColis();
    ui->givePacketButton->setDisabled(true);
}

void AdminPanel::selectColis() {
    if (ui->selectDispatcher->currentText() != "") {
        ui->givePacketButton->setDisabled(false);
    }
}

void AdminPanel::loadChauffeurList() {
    int prev = ui->listChauffeurs->currentRow();
    ui->listChauffeurs->clear();
    for (Chauffeur * chauffeur : AdminPanelInfo::getListeChauffeurs()) {
        QString label = QString::fromStdString(chauffeur->getNom() + " " + chauffeur->getPrenom() + " " + to_string(chauffeur->getIdPersonne()) );
        ui->listChauffeurs->addItem(label);
    }
    ui->listChauffeurs->setCurrentRow(prev);
}
void AdminPanel::loadDispatcherList() {
    int prev = ui->selectDispatcher->currentIndex();
    ui->selectDispatcher->clear();
    for (Dispatcher * dispatcher : AdminPanelInfo::getListeDispatchers()) {
        QString label = QString::fromStdString(dispatcher->getNom() + " " + dispatcher->getPrenom() + " " + to_string(dispatcher->getIdPersonne()) );
        ui->selectDispatcher->addItem(label);
    }
    ui->selectDispatcher->setCurrentIndex(prev);
}

void AdminPanel::loadTrajetList() {
    int prev = ui->listTrajets->currentRow();
    Chauffeur * ch = AdminPanelInfo::currChauffeur();

    for (Trajet * tr : ch->getListTrajets()) {
        ui->listTrajets->addItem(QString::fromStdString(to_string(tr->getIdTrajet()) + " - " + tr->getVilleDepart() + " vers " + tr->getVilleArrivee() + " de " + tr->getHoraireDepart() + " a " + tr->getHoraireArrivee() + " | Statut: " + to_string(tr->getStatuts())));
    }
    ui->listTrajets->setCurrentRow(prev);
}

void AdminPanel::loadColisDispacher() {
    for(Colis * cl : AdminPanelInfo::currDispacher()->getListColis()) {
        QString label = QString::fromStdString("Vers: " + cl->getVilleArrivee() + ", Poids: " + to_string(cl->getPoid()) + ", du " + cl->getDateAjoutColis());
        ui->packetQueue->addItem(label);
    }
}

void AdminPanel::loadListeColis() {
    for(Colis * cl : AdminPanelInfo::getColisEnAttente()) {
        QString label = QString::fromStdString("Vers: " + cl->getVilleArrivee() + ", Poids: " + to_string(cl->getPoid()) + ", du " + cl->getDateAjoutColis());
        ui->unattributedPacketList->addItem(label);
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
            loadChauffeurList();
        } else if (role == ROLE_DISPATCHER) {
            AdminPanelInfo::addDispatcherToList(Dispatcher::constructDispatcherFromId(successfullyAddUser));
            loadDispatcherList();
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

void AdminPanel::updateStatChauffeur() {
    QString stats = QString::fromStdString(Admin::printInfoChauffeur(AdminPanelInfo::currChauffeur()));
    ui->statChauffeur->setPlainText(stats);
}

void AdminPanel::updateStatDispacher() {
    QString stats = QString::fromStdString(Admin::printInfoDispatcher(AdminPanelInfo::currDispacher()));
    ui->statDispatcher->setPlainText(stats);
}

void AdminPanel::updateStatTrajet() {
    QString stats = QString::fromStdString(Admin::printInfoTrajet(AdminPanelInfo::currTrajet()));
    ui->statTrajet->setPlainText(stats);
}

