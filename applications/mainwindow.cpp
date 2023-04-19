#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <string>
#include "shared/common.h"
#include "shared/conf.h"
#include <vector>
#include <filesystem>

using namespace std;

QSqlDatabase db;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QPushButton button("Hello world !");
    button.show();

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(path_to_main_db);

    if (!db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }

    return app.exec();
}
