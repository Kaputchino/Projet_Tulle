#include "chauffeurpanel.h"
#include "ui_chauffeurpanel.h"

ChauffeurPanel::ChauffeurPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ChauffeurPanel)
{
    ui->setupUi(this);
}

ChauffeurPanel::~ChauffeurPanel()
{
    delete ui;
}
