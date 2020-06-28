//
// Created by Matthew Olson on 6/13/20.
//

#ifndef BATTLETOWERMANAGER_MOVE_H
#define BATTLETOWERMANAGER_MOVE_H
#include <string>
#include <vector>
#include <src/Mon.h>


class Move {
public:
    Move(const std::string &name);
    ~Move();
    std::vector<int> calcDamage(Mon attacker, Mon defender);
private:
    std::string name;
    std::string effect;
    std::string type;
    int power;
    int acc;
};


#endif //BATTLETOWERMANAGER_MOVE_H
