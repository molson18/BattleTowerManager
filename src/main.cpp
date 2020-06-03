#include <iostream>
#include "../resources/mainwindow.h"
#include <QApplication>
#include <resources/Member.h>
#include <QtSql>



int main(int argc, char** argv) {
    QApplication app(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../database/gen4.db");
    bool ok = db.open();
    QSqlQuery query;
    if (!query.exec("Select * From moves")) {
        std::cerr << "Not working here" << std::endl;
    }
    MainWindow mw;



    if (!ok) { std::cerr << "could not open db" << std::endl; }


    mw.show();

    return app.exec();
}
