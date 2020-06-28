//
// Created by shotg on 5/28/2020.
//

#ifndef BATTLETOWERMANAGER_UMOVE_H
#define BATTLETOWERMANAGER_UMOVE_H


#include <QtWidgets/QWidget>
#include "ui_UMove.h"

namespace Ui{
    class UMove;
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
    Ui::UMove *ui;
    QLabel* moveName;
    QLabel* power;
    QLabel* acc;
    QFrame* bg;
};


#endif //BATTLETOWERMANAGER_UMOVE_H
