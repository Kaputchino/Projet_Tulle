#ifndef CHAUFFEURPANEL_H
#define CHAUFFEURPANEL_H

#include <QMainWindow>

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

private slots:
    void ajouterTrajet();
    void modifierTrajet();
    void supprimmerTrajet();
    void selectionnerColis();
    void selectionnerTrajet();
    void commencerLivraison();
    void finirLivraison();
};

#endif // CHAUFFEURPANEL_H
