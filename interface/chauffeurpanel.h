#ifndef CHAUFFEURPANEL_H
#define CHAUFFEURPANEL_H

#include <QMainWindow>
#include "core/headers/chauffeurPanelInfo.h"

namespace Ui {
class ChauffeurPanel;
}

class ChauffeurPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit ChauffeurPanel(QWidget *parent = nullptr);
    ~ChauffeurPanel();

private:
    Ui::ChauffeurPanel *ui;
    void loaderListeTrajet();
    void loaderListeColis();
    void setStateListeColis();
    void setStateButtons();

private slots:
    void ajouterTrajet();
    void modifierTrajet();
    void supprimmerTrajet();
    void selectionnerTrajet();
    void commencerLivraison();
    void finirLivraison();
    void validerTrajet();
};

#endif // CHAUFFEURPANEL_H
