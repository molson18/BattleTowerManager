//
// Created by Matthew Olson on 6/13/20.
//

#ifndef BATTLETOWERMANAGER_MON_H
#define BATTLETOWERMANAGER_MON_H
#include <string>
#include <QSqlRecord>
#include "MoveFactory.h"

class Mon {
public:
    static std::vector<Mon> battleFactoryFac(const std::string &name);
    static int calcStat(int base, int level, int evs, int ivs, int nature);
    static int calcHpStat(int base, int level, int evs, int ivs);
    int getModAtk();
    int getModDef();
    int getModSpatk();
    int getModSpdef();
    int getModSpd();
    int level = 50;
    bool isStab(const std::string& type);
    double typeEffectiveness(const std::string& type);
    Mon();
    ~Mon();
private:
    Mon(const QSqlRecord &rec);

    std::string name;
    std::string ability;

    std::string type1;
    std::string type2;

    int hp, atk, def, spatk, spdef, spd;

    int currHp;
    int modatk;
    int moddef;
    int modspatk;
    int modspdef;
    int modspd;

    IMove *move1;
    IMove *move2;
    IMove *move3;
    IMove *move4;

    static int getModStat(int modifier, int stat);
};


#endif //BATTLETOWERMANAGER_MON_H
