#ifndef DISPATCHERPANEL_H
#define DISPATCHERPANEL_H

#include <QMainWindow>
#include "core/headers/dispatcherPanelInfo.h"

namespace Ui {
class DispatcherPanel;
}

class DispatcherPanel : public QMainWindow
{
    Q_OBJECT

public:
    explicit DispatcherPanel(QWidget *parent = nullptr);
    ~DispatcherPanel();

private:
    Ui::DispatcherPanel *ui;
    void updaterFile();

private slots:
    void genererColis();
    void dispatcher();

};

#endif // DISPATCHERPANEL_H
