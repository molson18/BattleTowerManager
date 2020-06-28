
#include "Member.h"
#include "ui_Member.h"


Member::Member(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Member)
{
    ui->setupUi(this);

    this->nameLabel = ui->name;
    this->hpBar = ui->health;
    this->hpInput = ui->hpInput;

    statLabels[0] = ui->hpLabel;
    statLabels[1] = ui->atkLabel;
    statLabels[2] = ui->defLabel;
    statLabels[3] = ui->spatkLabel;
    statLabels[4] = ui->spdefLabel;
    statLabels[5] = ui->spdLabel;

    Move *move1 = ui->move1;
    Move *move2 = ui->move2;
    Move *move3 = ui->move3;
    Move *move4 = ui->move4;

    move1->setMove("Sludge");
    move1->applyCss();
    move2->applyCss();
    move3->applyCss();
    move4->applyCss();
    move1->updateFontSize();

    QObject::connect(hpInput, SIGNAL(editingFinished()), this, SLOT(hpInputted()));

    this->parent = parent;
    this->mon = "";
    std::cout << "Testessss" << std::endl;
}

Member::~Member() {
   delete ui;
}

void Member::mousePressEvent(QMouseEvent *e) {
    this->setStyleSheet(this->styleSheet() + "background-color:yellow;");
    this->resize(this->width() + 100, this->height());
    this->nameLabel->resize(nameLabel->width() + 100, nameLabel->height());
    QFrame* frame = ui->frame;
    frame->resize(frame->width() + 100, frame->height());
}

void Member::setName(std::string mon) {
    this->mon = mon;
    nameLabel->setText(QString(mon.c_str()));
}

void Member::setStats(int hp, int atk, int def, int spatk, int spdef, int spd) {
    stats[0] = hp;
    stats[1] = atk;
    stats[2] = def;
    stats[3] = spatk;
    stats[4] = spdef;
    stats[5] = spd;
    updateStats();
}

void Member::updateStats() {
    for (int i = 0; i < 6; i++) {
        statLabels[i]->setText(intToString(stats[i]).c_str());
    }
}

string Member::intToString(int a) {
    string b = string("");
    while (a != 0) {
        char c = (a % 10) + '0';
        b.insert(0, &c);
        a /= 10;
    }
    return b;
}

void Member::hpInputted() {
    bool noError;
    int currHp = hpInput->text().toInt(&noError, 10);
    if (noError) {
        double p = (double) currHp / (double) stats[0];
        hpBar->setValue((int)round(p * 10000));
    }
}


