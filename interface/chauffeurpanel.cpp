#include <QMessageBox>
#include "chauffeurpanel.h"
#include "ui_chauffeurpanel.h"
#include "core/headers/chauffeurPanelInfo.h"
#include "core/headers/common.h"

ChauffeurPanel::ChauffeurPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChauffeurPanel)
{
    ui->setupUi(this);
    loaderListeTrajet();
    QObject::connect(ui->listTrajets, &QListWidget::clicked, this, &ChauffeurPanel::selectionnerTrajet);
    QObject::connect(ui->deliverPackageButton, &QPushButton::clicked, this, &ChauffeurPanel::commencerLivraison);
    QObject::connect(ui->markDeliveredButton, &QPushButton::clicked, this, &ChauffeurPanel::finirLivraison);
    QObject::connect(ui->validateTrajetButton, &QPushButton::clicked, this, &ChauffeurPanel::validerTrajet);
    QObject::connect(ui->addTraButton, &QPushButton::clicked, this, &ChauffeurPanel::ajouterTrajet);

    setStateButtons();

    for (string str : listeVille) {
        ui->fromField->addItem(QString::fromStdString(str));
        ui->toField->addItem(QString::fromStdString(str));
    }

    ui->poidsField->setMaximum(1000000);
    ui->prixField->setMaximum(1000000);
}

ChauffeurPanel::~ChauffeurPanel()
{
    delete ui;
}

void ChauffeurPanel::loaderListeTrajet() {
    for (Trajet * tr : ChauffeurPanelInfo::getLogged()->getListTrajets()) {
        QString label = QString::fromStdString(to_string(tr->getIdTrajet()) + " - " + tr->getVilleDepart() + " vers " + tr->getVilleArrivee() + " de " + tr->getHoraireDepart() + " a " + tr->getHoraireArrivee() + " | Statut: " + Trajet::translateStatus(tr->getStatuts()));
        ui->listTrajets->addItem(label);
    }
}

void ChauffeurPanel::loaderListeColis() {
    for (Colis * cl : ChauffeurPanelInfo::getSelelectedTrajet()->getListeColis()) {
        QString label = QString::fromStdString("Vers: " + cl->getVilleArrivee() + ", Poids: " + to_string(cl->getPoid()) + ", du " + cl->getDateAjoutColis());
        ui->listColis->addItem(label);
    }
}

void ChauffeurPanel::ajouterTrajet() {
    Errors::init();
    string villeDepart = ui->fromField->currentText().toStdString();
    string villeArrivee = ui->toField->currentText().toStdString();
    string heureDepart = ui->beginField->text().toStdString();
    string heureArrivee = ui->endField->text().toStdString();
    double poids = ui->poidsField->value();
    double prix = ui->prixField->value();

    if (heureDepart == heureArrivee) {
        Errors::appendError("L'heure de depart ne peut etre egal a l'heure d'arrivee");
    }

    if (poids <= 0) {
        Errors::appendError("Le poids doit etre positif.");
    }

    if (prix <= 0) {
        Errors::appendError("Le prix ne peut etre negatif.");
    }

    if (Errors::hasErrors()) {
        QMessageBox::warning(this, "Ajout Trajet", QString::fromStdString(Errors::readErrors()));
    } else {
        Trajet * trajet = new Trajet(
                ChauffeurPanelInfo::getLogged()->getIdPersonne(),
                villeDepart, villeArrivee, heureDepart, heureArrivee, poids, prix
        );
        ChauffeurPanelInfo::getLogged()->ajoutTrajet(trajet);
        ui->listTrajets->clear();
        setStateButtons();
        loaderListeTrajet();
        ui->beginField->update(0, 0, 0, 0);
        ui->endField->update(0, 0, 0, 0);
        ui->poidsField->setValue(0);
        ui->prixField->setValue(0);
    }
}

void ChauffeurPanel::modifierTrajet() {

}

void ChauffeurPanel::supprimmerTrajet() {

}



void ChauffeurPanel::selectionnerTrajet() {
    int index = ui->listTrajets->currentRow();
    ChauffeurPanelInfo::setSelectedTrajet(ChauffeurPanelInfo::getLogged()->getListTrajets().at(index));
    setStateButtons();
    setStateListeColis();
    ui->listColis->clear();
    loaderListeColis();
}

void ChauffeurPanel::commencerLivraison() {
    ChauffeurPanelInfo::getLogged()->delancheLivraison(ChauffeurPanelInfo::getSelelectedTrajet());
    setStateButtons();
    ui->listTrajets->clear();
    setStateListeColis();
    loaderListeTrajet();
}

void ChauffeurPanel::finirLivraison() {
    ChauffeurPanelInfo::getLogged()->declareLivraison(ChauffeurPanelInfo::getSelelectedTrajet());
    ui->listTrajets->clear();
    setStateButtons();
    setStateListeColis();
    loaderListeTrajet();
}

void ChauffeurPanel::validerTrajet() {
    ChauffeurPanelInfo::getLogged()->validerTrajet(ChauffeurPanelInfo::getSelelectedTrajet());
    ui->listTrajets->clear();
    setStateButtons();
    setStateListeColis();
    loaderListeTrajet();
}

void ChauffeurPanel::setStateListeColis() {
    if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() >= TRAJET_LIVRAISON_EN_COURS) {
        ui->listColis->setDisabled(true);
    } else {
        ui->listColis->setDisabled(false);
    }
}

void ChauffeurPanel::setStateButtons() {
    ui->deliverPackageButton->setEnabled(false);
    ui->validateTrajetButton->setEnabled(false);
    ui->markDeliveredButton->setEnabled(false);
    ui->editTraButton->setEnabled(false);
    ui->delTraButton->setEnabled(false);

    if (ChauffeurPanelInfo::getSelelectedTrajet() != nullptr) {
        if (!ChauffeurPanelInfo::getSelelectedTrajet()->getListeColis().empty()) {
            if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() == TRAJET_VALIDATION) {
                ui->deliverPackageButton->setEnabled(true);
                ui->editTraButton->setEnabled(true);
                ui->delTraButton->setEnabled(true);
                ui->validateTrajetButton->setEnabled(false);
            } else if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() == TRAJET_SOLICITATION) {
                ui->validateTrajetButton->setEnabled(true);
            } else if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() == TRAJET_LIVRAISON_EN_COURS) {
                ui->markDeliveredButton->setEnabled(true);
            }
        }
    }
}

