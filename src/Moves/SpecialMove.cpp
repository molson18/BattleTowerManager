//
// Created by Matthew Olson on 6/26/20.
//

#include "SpecialMove.h"

SpecialMove::SpecialMove(const std::string &name) : IMove(name) {}

SpecialMove::SpecialMove(const QSqlRecord &query) : IMove(query) {}

std::vector<int> SpecialMove::calcDamage(Mon* attacker, Mon* defender) const {
    int baseD = IMove::normInitDamage(attacker->level, attacker->getModSpatk(), attacker->getModSpdef());
    return IMove::applyModifiers(baseD, attacker, defender);
}
