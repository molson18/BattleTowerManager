//
// Created by Matthew Olson on 6/27/20.
//

#ifndef BATTLETOWERMANAGER_STATUSMOVE_H
#define BATTLETOWERMANAGER_STATUSMOVE_H


#include "src/IMove.h"

class StatusMove : public IMove {
public:
    StatusMove(const QSqlRecord &query);
    std::vector<int> calcDamage(Mon *attacker, Mon *defender) const;
};


#endif //BATTLETOWERMANAGER_STATUSMOVE_H
