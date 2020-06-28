//
// Created by Matthew Olson on 6/17/20.
//

#include "src/Moves/SeismicToss.h"
#include "src/Moves/StatusMove.h"
#include "src/Moves/PhysMove.h"
#include "src/Moves/SpecialMove.h"
#include "MoveFactory.h"

MoveFactory *MoveFactory::_factory = nullptr;
MoveFactory::MoveFactory() {
    this->moves = std::map<std::string, IMove*>();
}

IMove * MoveFactory::getMove(const std::string& move) {
    if (moves.count(move) == 0) {
        moves[move] = makeMove(move);
    }
    return moves[move];
}

// This is the fat oof
IMove *MoveFactory::makeMove(const std::string &move) {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare("Select * from Moves Where name = :name");
    query.bindValue(":name", QVariant(QString::fromStdString(move)));
    if (!query.exec()) {
        std::cerr << query.lastError().text().toStdString() << std::endl;
    }
    query.next();
    std::string name = query.value("Name").toString().toStdString();
    std::string category = query.value("category").toString().toStdString();
    if (move == "Seismic Toss") {
        return new SeismicToss(query.record());
    }
    else if (category == "Physical") {
        return new PhysMove(query.record());
    }
    else if (category == "Special") {
        return new SpecialMove(query.record());
    }
    else {
        return new StatusMove(query.record());
    }
}


