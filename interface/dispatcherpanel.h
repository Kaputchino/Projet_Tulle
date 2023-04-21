#ifndef DISPATCHERPANEL_H
#define DISPATCHERPANEL_H

#include <QMainWindow>

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
};

#endif // DISPATCHERPANEL_H
