//
// Created by Matthew Olson on 6/13/20.
//

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <iostream>
#include <QSqlRecord>
#include <QSqlField>

#include "Mon.h"

std::vector<Mon> Mon::battleFactoryFac(const std::string &name) {
    std::vector<Mon> sets = std::vector<Mon>();

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("Select * from battleFrontier join gen4 on battleFrontier.name = gen4.name where gen4.name = :name");
    query.bindValue(":name", QString::fromStdString(name));
    if (!query.exec()) {
        std::cerr << query.lastError().text().toStdString() << std::endl;
        exit(1);
    }
    while(query.next()) {
        sets.push_back(Mon(query.record()));
    }
    std::vector<int> test = sets[0].move1->calcDamage(&sets[0], &sets[1]);
    for (int i = 0; i < test.size(); i++) {
        printf("%i ", test[i]);
    }
    printf("\n");
    return sets;
}


Mon::Mon(const QSqlRecord &rec) {
    this->name = rec.value("gen4.name").toString().toStdString();
    this->ability = rec.value("gen4.ability1").toString().toStdString();

    MoveFactory *mfactory = MoveFactory::getFactory();
    this->move1 = mfactory->getMove(rec.value("move1").toString().toStdString());
    this->move2 = mfactory->getMove(rec.value("move2").toString().toStdString());
    this->move3 = mfactory->getMove(rec.value("move3").toString().toStdString());
    this->move4 = mfactory->getMove(rec.value("move4").toString().toStdString());

    this->type1 = rec.value("gen4.type1").toString().toStdString();
    this->type2 = rec.value("gen4.type2").toString().toStdString();

    int natk = 0, ndef = 0, nspatk = 0, nspdef = 0, nspd = 0;

    this->hp = calcHpStat(rec.value("gen4.hp").toInt(), 50, rec.value("battleFrontier.hp").toInt(), 31);
    this->atk = calcStat(rec.value("gen4.atk").toInt(), 50, rec.value("battleFrontier.atk").toInt(), 31, natk);
    this->def = calcStat(rec.value("gen4.def").toInt(), 50, rec.value("battleFrontier.def").toInt(), 31, ndef);
    this->spatk = calcStat(rec.value("gen4.spatk").toInt(), 50, rec.value("battleFrontier.spatk").toInt(), 31, nspatk);
    this->spdef = calcStat(rec.value("gen4.spdef").toInt(), 50, rec.value("battleFrontier.spdef").toInt(), 31, nspdef);
    this->spd = calcStat(rec.value("gen4.spd").toInt(), 50, rec.value("battleFrontier.spd").toInt(), 31, nspd);
    this->currHp = this->hp;
    this->modatk = 0;
    this->moddef = 0;
    this->modspatk = 0;
    this->modspdef = 0;
    this->modspd = 0;
}

int Mon::calcStat(int base, int level, int evs, int ivs, int nature) {
    int stat = 2 * base + ivs;
    stat += evs / 4;
    stat *= level;
    stat /= 100;
    stat += 5;
    if (nature > 0) { stat *= 1.1; }
    else if (nature < 0) { stat *= .9; }
    return stat;
}

int Mon::calcHpStat(int base, int level, int evs, int ivs){
    int stat = 2 * base + ivs;
    stat += evs / 4;
    stat *= level;
    stat /= 100;
    stat += level + 10;
    return stat;
}


int Mon::getModAtk() {
    return getModStat(modatk, atk);
}
int Mon::getModDef() {
    return getModStat(moddef, def);
}
int Mon::getModSpatk() {
    return getModStat(modspatk, spatk);
}
int Mon::getModSpdef() {
    return getModStat(modspdef, spdef);
}
int Mon::getModSpd() {
    return getModStat(modspd, spd);
}

int Mon::getModStat(int modifier, int stat) {
    double modifiers[6] = {1.5, 2, 2.5, 3, 3.5, 4};
    if (modifier > 0) {
        return (int)(stat * modifiers[modifier - 1]);
    }
    else if (modifier < 0) {
        return (int)(stat * modifiers[-1 * modifier - 1]);
    }
    else return stat;
}

bool Mon::isStab(const std::string& type) {
    // TODO: Make this not abuse or returning without checking the entire expression
    return this->type1 == type || type == this->type2;
}

double Mon::typeEffectiveness(const std::string& type) {
    // TODO change this to one query if theres 2 types
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    // TODO figure out how to do this with bindings rather than appending strings
    query.prepare(QString::fromStdString("Select " + type + " from types where type = :defender;"));
    query.bindValue(":move", QString::fromStdString(type));
    query.bindValue(":defender", QString::fromStdString(this->type1));
    query.exec();
    query.next();
    QSqlRecord record = query.record();
    for(int i=0;i<record.count();i++){
        QSqlField field=record.field(i);
        std::cout << field.name().toStdString() <<field.value().toString().toStdString() << std::endl;
    }
    double effectiveness = query.value(0).toDouble();
    if (!this->type2.empty()) {
        query.prepare(QString::fromStdString("Select " + type + " from types where type = :defender"));
        query.bindValue(":move", QString::fromStdString(type));
        query.bindValue(":defender", QString::fromStdString(this->type2));
        query.exec();
        effectiveness *= query.value(0).toDouble();
    }
    return effectiveness;
}

Mon::~Mon() = default;
