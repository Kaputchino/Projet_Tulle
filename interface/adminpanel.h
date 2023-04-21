#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include "core/headers/Admin.h"

namespace Ui {
class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();
    void setLoggedUser(Admin * adm);

private:
    Ui::AdminPanel *ui;
    Admin * loggedUser;
};

#endif // ADMINPANEL_H
