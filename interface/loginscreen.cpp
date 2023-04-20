#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QMessageBox>

LoginScreen::LoginScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_connectionButton_clicked()
{
    QString email =ui->emailEdit->text();
    QString password =ui->passEdit->text();

    if(email == "test" && password == "test") {
        QMessageBox::information(this, "Login", "Username & password corect");
        QMessageBox::warning(this, "Login", "Username & password incorect");
    }
}

