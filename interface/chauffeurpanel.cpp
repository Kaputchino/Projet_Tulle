#include "chauffeurpanel.h"
#include "ui_chauffeurpanel.h"

chauffeurPanel::chauffeurPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::chauffeurPanel)
{
    ui->setupUi(this);
}

chauffeurPanel::~chauffeurPanel()
{
    delete ui;
}
