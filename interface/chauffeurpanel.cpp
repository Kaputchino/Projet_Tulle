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
    ui->editTraButton->setEnabled(false);
    ui->delTraButton->setEnabled(false);
    ui->deliverPackageButton->setEnabled(false);
    ui->markDeliveredButton->setEnabled(false);
}

ChauffeurPanel::~ChauffeurPanel()
{
    delete ui;
}

void ChauffeurPanel::loaderListeTrajet() {
    for (Trajet * tr : ChauffeurPanelInfo::getLogged()->getListTrajets()) {
        QString label = QString::fromStdString(to_string(tr->getIdTrajet()) + " - " + tr->getVilleDepart() + " vers " + tr->getVilleArrivee() + " de " + tr->getHoraireDepart() + " a " + tr->getHoraireArrivee() + " | Statut: " + to_string(tr->getStatuts()));
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
    ui->deliverPackageButton->setEnabled(false);
    ui->markDeliveredButton->setEnabled(false);

    int index = ui->listTrajets->currentRow();
    ChauffeurPanelInfo::setSelectedTrajet(ChauffeurPanelInfo::getLogged()->getListTrajets().at(index));
    ui->editTraButton->setEnabled(true);
    ui->delTraButton->setEnabled(true);

    if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() <= TRAJET_VALIDATION) {
        ui->deliverPackageButton->setEnabled(true);
    } else if (ChauffeurPanelInfo::getSelelectedTrajet()->getStatuts() == TRAJET_LIVRAISON_EN_COURS) {
        ui->markDeliveredButton->setEnabled(true);
    }

    ui->listColis->clear();
    loaderListeColis();
}

void ChauffeurPanel::commencerLivraison() {
    ui->deliverPackageButton->setEnabled(false);
    ui->markDeliveredButton->setEnabled(true);
    ChauffeurPanelInfo::getSelelectedTrajet()->setStatuts(3);
    loaderListeTrajet();
    loaderListeColis();
}

void ChauffeurPanel::finirLivraison() {
    ui->markDeliveredButton->setEnabled(false);
    ChauffeurPanelInfo::getSelelectedTrajet()->setStatuts(4);
    loaderListeTrajet();
    loaderListeColis();
}
