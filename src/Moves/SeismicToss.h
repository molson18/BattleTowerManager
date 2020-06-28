//
// Created by Matthew Olson on 6/27/20.
//

#ifndef BATTLETOWERMANAGER_SEISMICTOSS_H
#define BATTLETOWERMANAGER_SEISMICTOSS_H

#include "src/Mon.h"

class SeismicToss : public IMove {
public:
    std::vector<int> calcDamage(Mon* attacker, Mon* defender) const;
    explicit SeismicToss(const QSqlRecord &query);
};


#endif //BATTLETOWERMANAGER_SEISMICTOSS_H
