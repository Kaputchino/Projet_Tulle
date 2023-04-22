#include "dispatcherpanel.h"
#include "ui_dispatcherpanel.h"

DispatcherPanel::DispatcherPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DispatcherPanel)
{
    ui->setupUi(this);
}

DispatcherPanel::~DispatcherPanel()
{
    delete ui;
}
