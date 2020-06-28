//
// Created by Matthew Olson on 6/5/20.
//

#include "MoveSet.h"
#include <cstdlib>


MoveSet::MoveSet(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MoveSet) {
    ui->setupUi(this);
    this->moves[0] = ui->move1;
    this->moves[1] = ui->move2;
    this->moves[2] = ui->move3;
    this->moves[3] = ui->move4;
    for (auto & move : moves) {
        move->applyCss();
    }
    this->item = ui->item;
}

MoveSet::~MoveSet() {
    delete ui;
}

void MoveSet::setMoveSet(const std::string &item, const std::string &move1, const std::string &move2,
                    const std::string &move3, const std::string &move4) {
    this->item->setText(item.c_str());
    moves[0]->setMove(move1);
    moves[1]->setMove(move2);
    moves[2]->setMove(move3);
    moves[3]->setMove(move4);
}
