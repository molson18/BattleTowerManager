//
// Created by shotg on 5/28/2020.
//

#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <iostream>
#include <QtCore/QFile>
#include <cmath>
#include "UMove.h"
#include "UMove.h"

Move::Move(QWidget* parent) :
    QWidget(parent),
    ui(new Ui::UMove) {
    ui->setupUi(this);

    this->moveName = ui->moveName;
    this->acc = ui->acc;
    this->power = ui->power;
    this->bg = ui->bg;

    applyCss();
}

Move::~Move() {
    delete ui;
}

void Move::setMove(const std::string &move) {

    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    if (!query.exec(("Select Name, Type, Power, Accuracy From Moves where name='" + move + "';").c_str())) {
        std::cerr << "query failed" << std::endl;
    }
    query.next();
    this->moveName->setText(query.value(0).toString());
    const char* type = (const char*) query.value(1).toString().toLocal8Bit();
    std::cout << type << std::endl;
    this->bg->setObjectName(type);
    this->power->setText(query.value(2).toString());
    this->acc->setText(query.value(3).toString());
}

void Move::applyCss() {
    QFile memberStyle("../css/UMove.css");
    memberStyle.open(QFile::ReadOnly);
    QString style = memberStyle.readAll();
    this->setStyleSheet(style);
}

void Move::setFixedSize(int x, int y) {
    int nameHeight = this->moveName->fontMetrics().height();
    QFont newNameFont("MS Shell Dlg 2", 32);
    QFont newRestFont("MS Shell Dlg 2", 24);
    double newNameHeight = (double)nameHeight / 300;
    std::cout << this->height() << std::endl;
    newNameHeight *= y;
    newNameFont.setPixelSize(newNameHeight);
    this->moveName->setFont(newNameFont);
    this->acc->setFont(newNameFont);
    this->power->setFont(newNameFont);

    QWidget::setFixedSize(x, y);
}

void Move::updateFontSize() {
    QFont newNameFont("MS Shell Dlg 2", 32);
    QFont newRestFont("MS Shell Dlg 2", 24);
//    this->moveName->wi
    std::cout << 126. / 300 * this->height()<< std::endl;
    newNameFont.setPixelSize(126. / 300 * this->height() / 2.5);
    newRestFont.setPointSize(this->acc->height() / 2.1);

    this->moveName->setFont(newNameFont);
    this->acc->setFont(newRestFont);
    this->power->setFont(newRestFont);

//    std::cout << newNameFont.pointSize() << std::endl;
}




