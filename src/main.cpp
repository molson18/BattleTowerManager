#include <iostream>
#include "../resources/mainwindow.h"
#include "Mon.h"
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
//    MainWindow mw;



    if (!ok) { std::cerr << "could not open db" << std::endl; }


//    mw.show();
    std::cout << "test1" << std::endl;
    std::vector<Mon> jolteons = Mon::battleFactoryFac("Jolteon");
    std::cout << "test2" << std::endl;
    return app.exec();
}
