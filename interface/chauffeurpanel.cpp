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

    setStateButtons();
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

