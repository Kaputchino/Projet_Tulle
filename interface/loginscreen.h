#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>

namespace Ui {
class LoginScreen;
}

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginScreen(QWidget *parent = nullptr);
    ~LoginScreen();

private:
    Ui::LoginScreen *ui;

private slots:
    void on_connectionButton_clicked();
    void on_quitButton_clicked();
    void on_resetButton_clicked();
};

#endif // LOGINSCREEN_H
