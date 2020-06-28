//
// Created by Matthew Olson on 6/24/20.
//

#include "IMove.h"

IMove::IMove(const std::string &name) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("Select * from Moves Where name = :name");
    query.bindValue(":name", QVariant(QString::fromStdString(name)));
    if (!query.exec()) {
        std::cerr << query.lastError().text().toStdString() << std::endl;
    }
    query.next();
    setUsingRecord(query.record());
}

IMove::IMove(const QSqlRecord &query) {
    setUsingRecord(query);
}

void IMove::setUsingRecord(const QSqlRecord &query) {
    this->name = query.value("name").toString().toStdString();
    this->effect = query.value("effect").toString().toStdString();
    this->power = query.value("power").toInt();
    this->acc = query.value("accuracy").toInt();
    this->type = query.value("type").toString().toStdString();
}

int IMove::normInitDamage(int level, int A, int D) const {
    int baseD = 2 * level;
    baseD /= 5;
    baseD += 2;
    baseD *= this->power;
    baseD = (int)(baseD * ((double)A / (double)D));
    baseD /= 50;
    baseD += 2;
    return baseD;
}

std::vector<int> IMove::applyModifiers(int baseD, Mon *attacker, Mon *defender) const {
    // targets
    // Weather handeling
    std::string weather = "none";
    double modifier = 1;
    if (weather == "rain") {
        if (this->type == "water") {
            modifier *= 3;
            modifier /= 2;
        }
        else if (this->type == "fire") {
            modifier /= 2;
        }
    }
    else if (weather == "sun" && this->type == "fire") {
        if (this->type == "fire") {
            modifier *= 3;
            modifier /= 2;
        }
        else if (this->type == "water") {
            modifier /= 2;
        }
    }
    // crits, TODO: must also be handled earlier with getting modified stats
    bool crit = false;
    if (crit) {
        modifier *= 2;
    }
    // STAB
    if (attacker->isStab(this->type)) {
        modifier *= 3;
        modifier /= 2;
    }
    // Ho boy type checking
    modifier *= defender->typeEffectiveness(this->type);

    // apply rolls
    std::vector<int> damage = std::vector<int>();
    for (int i = 85; i <= 100; i++) {
        double temp = modifier * (double)i / 100.;
        damage.push_back(temp * baseD);
    }
    return damage;
}
