//
// Created by shotg on 5/28/2020.
//

#ifndef BATTLETOWERMANAGER_MOVE_H
#define BATTLETOWERMANAGER_MOVE_H


#include <QtWidgets/QWidget>
#include "ui_Move.h"

namespace Ui{
    class Move;
}
class Move : public QWidget {
    Q_OBJECT

public:
    explicit Move(QWidget* parent);
    ~Move();
    void setMove(std::string move);
    void applyCss();
    void setFixedSize(int x, int y);
    void updateFontSize();
private:
    Ui::Move *ui;
    QLabel* moveName;
    QLabel* power;
    QLabel* acc;
    QFrame* bg;
};


#endif //BATTLETOWERMANAGER_MOVE_H
