#include <iostream>
#include <QApplication>
#include <QPushButton>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <fstream>


using namespace std;

string *readDataBasePath(){
    ifstream myfile ("../config");
    string mystring;
    if ( myfile.is_open() ) {
        myfile >> mystring;
        return &mystring;
    }
}



int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QPushButton button("Hello world !");
    button.show();
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString::fromStdString(*readDataBasePath()));
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
    QString


    return app.exec();
}

