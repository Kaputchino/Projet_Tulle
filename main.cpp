#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <iostream>
#include <QMessageBox>
#include <QWidget>
#include "core/headers/initDB.h"

using namespace std;

QSqlDatabase db;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    try {
    initDB::linkDB();
    } catch(const std::exception& err) {
        cout << err.what() << endl;
        QWidget w;
        QMessageBox::critical(&w, "Error!", err.what());
        return -1;
    }

    return 0;
    // return app.exec();
}




