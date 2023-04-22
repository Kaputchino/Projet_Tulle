#ifndef ADMINPANEL_H
#define ADMINPANEL_H

#include <QMainWindow>
#include <QVariant>
#include "core/headers/Admin.h"
#include "core/headers/adminPanelInfo.h"
#include <QSettings>


namespace Ui {
    class AdminPanel;
}

class AdminPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit AdminPanel(QWidget *parent = nullptr);
    ~AdminPanel();
    AdminPanelInfo data;

private:
    Ui::AdminPanel *ui;
    void updateChauffeurList();
    void updateDispatcherList();
    void updateTrajet();

private slots:
    void addPlayerButton();
    void clearButton();
    void selectChauffeur();
};

#endif // ADMINPANEL_H
