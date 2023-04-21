#ifndef CHAUFFEURPANEL_H
#define CHAUFFEURPANEL_H

#include <QMainWindow>

namespace Ui {
class chauffeurPanel;
}

class chauffeurPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit chauffeurPanel(QWidget *parent = nullptr);
    ~chauffeurPanel();

private:
    Ui::chauffeurPanel *ui;
};

#endif // CHAUFFEURPANEL_H
