#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen;
    ui->actionAdd_Team;

    ui->moveTest->updateFontSize();

    this->member1 = ui->member1;
    this->member2 = ui->member2;
    this->member3 = ui->member3;

    QFile memberStyle("../css/Member.css");
    memberStyle.open(QFile::ReadOnly);
    QString style = memberStyle.readAll();
    member1->setStyleSheet(style);
    member2->setStyleSheet(style);
    member3->setStyleSheet(style);
    ui->moveTest->setMove("Wake-up Slap");
    QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openActionTriggered()));
    QObject::connect(ui->actionAdd_Team, SIGNAL(triggered()), this, SLOT(addTeamTriggered()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionTriggered() {
    std::cout << "open pressed!" << std::endl;
}


void MainWindow::addTeamTriggered() {
    std::cout << "New Team Entered" << std::endl;
    member1->setName("Vaporean");
    member2->setName("Abomasnow");
    member3->setName("Glaceon");
    member1->setStats(150, 100, 100, 100, 100, 100);
    member2->setStats(100, 100, 100, 100, 100, 100);
    member3->setStats(100, 100, 100, 100, 100, 100);
}
