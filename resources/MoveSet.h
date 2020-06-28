//
// Created by Matthew Olson on 6/5/20.
//

#ifndef BATTLETOWERMANAGER_MOVESET_H
#define BATTLETOWERMANAGER_MOVESET_H


#include <QWidget>
#include <QLabel>
#include "UMove.h"
#include "ui_MoveSet.h"

namespace Ui{
    class MoveSet;
}

class MoveSet : public QWidget {
    Q_OBJECT

public:
    MoveSet(QWidget *parent);
    ~MoveSet();
    void setMoveSet(const std::string &item, const std::string &move1, const std::string &move2,
            const std::string &move3, const std::string &move4);

private:
    Ui::MoveSet *ui;
    QLabel *item;
    Move *moves[4];
};


#endif //BATTLETOWERMANAGER_MOVESET_H
