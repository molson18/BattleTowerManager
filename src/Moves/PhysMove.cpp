//
// Created by Matthew Olson on 6/13/20.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <iostream>
#include "PhysMove.h"

PhysMove::PhysMove(const std::string &name) : IMove(name) {}

PhysMove::PhysMove(const QSqlRecord &query) : IMove(query) {}

PhysMove::~PhysMove() = default;

std::vector<int> PhysMove::calcDamage(Mon* attacker, Mon* defender) const {
    int baseD = IMove::normInitDamage(attacker->level, attacker->getModAtk(), attacker->getModDef());
    return IMove::applyModifiers(baseD, attacker, defender);
}
