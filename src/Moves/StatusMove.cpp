//
// Created by Matthew Olson on 6/27/20.
//

#include "StatusMove.h"

StatusMove::StatusMove(const QSqlRecord &query) : IMove(query) {}

std::vector<int> StatusMove::calcDamage(Mon *attacker, Mon *defender) const {
    std::vector<int> damage = std::vector<int>();
    damage.push_back(0);
    return damage;
}
