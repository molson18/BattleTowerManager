//
// Created by Matthew Olson on 6/24/20.
//

#ifndef BATTLETOWERMANAGER_IMOVE_H
#define BATTLETOWERMANAGER_IMOVE_H

#include <vector>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QSql>
#include <iostream>
#include "src/Mon.h"

class Mon;
class IMove {
//    IMove(const std::string &name);
protected:
    int normInitDamage(int level, int A, int D) const;
    std::vector<int> applyModifiers(int baseD, Mon* attacker, Mon* defender) const;

    std::string name;
    std::string effect;
    std::string type;
    int power;
    int acc;
public:
    virtual std::vector<int> calcDamage(Mon* attacker, Mon* Defender) const = 0;
    ~IMove() = default;
    explicit IMove(const std::string &name);
    explicit IMove(const QSqlRecord &record);
    void setUsingRecord(const QSqlRecord &record);
};


#endif //BATTLETOWERMANAGER_IMOVE_H
