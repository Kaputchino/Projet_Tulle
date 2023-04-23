#include "dispatcherpanel.h"
#include "ui_dispatcherpanel.h"
#include "core/headers/dispatcherPanelInfo.h"

DispatcherPanel::DispatcherPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DispatcherPanel)
{
    ui->setupUi(this);
    updaterFile();
    QObject::connect(ui->genNewPacketButton, &QPushButton::clicked, this, &DispatcherPanel::genererColis);
    QObject::connect(ui->dispatcherButton, &QPushButton::clicked, this, &DispatcherPanel::dispatcher);
}

DispatcherPanel::~DispatcherPanel()
{
    delete ui;
}

void DispatcherPanel::genererColis() {
    DispatcherPanelInfo::getLogged()->remplir(10);
    ui->listeColis->clear();
    updaterFile();
}

void DispatcherPanel::dispatcher() {
    DispatcherPanelInfo::getLogged()->dispatch();
    ui->listeColis->clear();
    updaterFile();
}

void DispatcherPanel::updaterFile() {
    for(Colis *  cl : DispatcherPanelInfo::getLogged()->getListColis()) {
        QString label = QString::fromStdString("Vers: " + cl->getVilleArrivee() + ", Poids: " + to_string(cl->getPoid()) + ", du " + cl->getDateAjoutColis());
        ui->listeColis->addItem(label);
    }
}
