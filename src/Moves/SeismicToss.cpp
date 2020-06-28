//
// Created by Matthew Olson on 6/27/20.
//

#include "SeismicToss.h"

SeismicToss::SeismicToss(const QSqlRecord &query) : IMove(query) {}

std::vector<int> SeismicToss::calcDamage(Mon* attacker, Mon* defender) const {
    std::vector<int> damage = std::vector<int>();
    if (defender->typeEffectiveness("fighting") != 0) {
        damage.push_back(attacker->level);
    }
    else {
        damage.push_back(0);
    }
    return damage;
}
