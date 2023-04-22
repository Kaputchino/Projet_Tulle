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

    QObject::connect(ui->listChauffeurs, &QListWidget::itemClicked, this, &AdminPanel::selectChauffeur);
    QObject::connect(ui->listTrajets, &QListWidget::itemClicked, this, &AdminPanel::selectTrajet);

    ui->statChauffeur->setReadOnly(true);
    ui->statDispatcher->setReadOnly(true);
    ui->statTrajet->setReadOnly(true);

    AdminPanelInfo::init();
    loadChauffeurList();
    loadDispatcherList();
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


