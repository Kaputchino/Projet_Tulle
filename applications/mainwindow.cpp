#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>


using namespace std;

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QPushButton button("Hello world !");
    button.show();

    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("projet_tulle");
    db.setUserName("root");
    db.setPort(3306);
    db.setPassword("");
    if(!db.open())
    {
        cout << "Can't Connect to DB !";
    }
    else
    {
        cout << "Connected Successfully to DB !";
        QSqlQuery query;
        query.prepare("QUERY TO BE SENT TO THE DB");
        if(!query.exec())
        {
            cout << "Can't Execute Query !";
        }
        else
        {
            cout << "Query Executed Successfully !";
        }
    }



    return app.exec();
}
