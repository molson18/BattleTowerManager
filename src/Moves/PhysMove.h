//
// Created by Matthew Olson on 6/13/20.
//

#ifndef BATTLETOWERMANAGER_PHYSMOVE_H
#define BATTLETOWERMANAGER_PHYSMOVE_H
#include "../IMove.h"
#include <string>
#include <vector>
#include "src/Mon.h"


class PhysMove : public IMove {
public:
    explicit PhysMove(const std::string &name);
    explicit PhysMove(const QSqlRecord &query);
    ~PhysMove();
    std::vector<int> calcDamage(Mon* attacker, Mon* defender) const;
private:
};


#endif //BATTLETOWERMANAGER_PHYSMOVE_H
