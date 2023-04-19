#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include "core/headers/initDB.h"

using namespace std;

QSqlDatabase db;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QPushButton button("Hello world !");
    button.show();
    initDB::linkDB();

    return app.exec();
}




