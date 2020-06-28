//
// Created by shotg on 5/28/2020.
//

#ifndef BATTLETOWERMANAGER_UI_MOVE_H
#define BATTLETOWERMANAGER_UI_MOVE_H


#include <QtWidgets/QWidget>
#include "ui_Move.h"

namespace Ui{
    class Ui_Move;
}
class Move : public QWidget {
    Q_OBJECT

public:
    explicit Move(QWidget* parent);
    ~Move();
    void setMove(const std::string &move);
    void applyCss();
    void setFixedSize(int x, int y);
    void updateFontSize();
private:
    Ui::Ui_Move *ui;
    QLabel* moveName;
    QLabel* power;
    QLabel* acc;
    QFrame* bg;
};


#endif //BATTLETOWERMANAGER_UI_MOVE_H
