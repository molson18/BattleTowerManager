//
// Created by Matthew Olson on 6/13/20.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <iostream>
#include "Move.h"

Move::Move(const std::string &name) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("Select * from Moves Where name = :name");
    query.bindValue(":name", QVariant(QString::fromStdString(name)));
    if (!query.exec()) {
        std::cerr << query.lastError().text().toStdString() << std::endl;
    }
    query.next();

    this->name = name;
    this->effect = query.value("effect").toString().toStdString();
    this->power = query.value("power").toInt();
    this->acc = query.value("accuracy").toInt();
    this->type = query.value("type").toString().toStdString();

}

Move::~Move() = default;

std::vector<int> Move::calcDamage(Mon attacker, Mon defender) {

}
