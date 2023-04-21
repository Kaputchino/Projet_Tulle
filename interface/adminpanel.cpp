#include "adminpanel.h"
#include "ui_adminpanel.h"

AdminPanel::AdminPanel(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminPanel)
{
    ui->setupUi(this);
}

AdminPanel::~AdminPanel()
{
    delete ui;
}

void AdminPanel::setLoggedUser(Admin * loggedUser) {
    this->loggedUser = loggedUser;
}