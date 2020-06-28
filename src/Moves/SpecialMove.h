//
// Created by Matthew Olson on 6/26/20.
//

#ifndef BATTLETOWERMANAGER_SPECIALMOVE_H
#define BATTLETOWERMANAGER_SPECIALMOVE_H


#include "src/IMove.h"

class SpecialMove : public IMove {
public:
    explicit SpecialMove(const std::string& name);
    explicit SpecialMove(const QSqlRecord &query);
    ~SpecialMove() = default;
    std::vector<int> calcDamage(Mon* attacker, Mon* defender) const;
};


#endif //BATTLETOWERMANAGER_SPECIALMOVE_H
