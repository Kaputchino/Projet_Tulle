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
};

#endif // CHAUFFEURPANEL_H
