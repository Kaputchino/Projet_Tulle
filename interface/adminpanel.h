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
    void loadChauffeurList();
    void loadDispatcherList();
    void loadColisDispacher();
    void loadListeColis();
    void loadTrajetList();
    void updateStatChauffeur();
    void updateStatTrajet();
    void updateStatDispacher();

private slots:
    void addPlayerButton();
    void attribuerColisBoutton();
    void clearButton();
    void selectChauffeur();
    void selectTrajet();
    void selectColisDispatcher();
    void selectDispacher();
    void selectColis();
};

#endif // ADMINPANEL_H
