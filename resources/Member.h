//
// Created by shotg on 5/22/2020.
//

#ifndef BATTLETOWERMANAGER_MEMBER_H
#define BATTLETOWERMANAGER_MEMBER_H
#include <QtWidgets/QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QDebug>
//#include <string>
#include <utility>
#include <QtWidgets/QLabel>
#include <iostream>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
//#include <cstdlib>
#include <cmath>
#include "UMove.h"

using namespace std;

namespace Ui {
    class Member;
}

class Member : public QWidget {
    Q_OBJECT


public:
    explicit Member(QWidget *parent);
    void mousePressEvent(QMouseEvent *e);
    ~Member();

    void setName(std::string mon);
    void setStats(int hp, int atk, int def, int spatk, int spdef, int spd);

signals:
    void Mouse_Pressed();
public slots:
    void hpInputted();
private:
    QWidget* parent;
    std::string mon;
    QLabel *nameLabel;
    std::string moves[4];
    int stats[6];

    QLineEdit* hpInput;
    QProgressBar* hpBar;

    QLabel* statLabels[6];

    Move *move1;
    Move *move2;
    Move *move3;
    Move *move4;


    void updateStats();
    Ui::Member *ui;

    static string intToString(int a);
};


#endif //BATTLETOWERMANAGER_MEMBER_H
