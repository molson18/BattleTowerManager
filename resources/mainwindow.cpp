#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionOpen;
    ui->actionAdd_Team;


    this->member1 = ui->member1;
    this->member2 = ui->member2;
    this->member3 = ui->member3;

    this->monSelector = ui->MonSelector;

    QFile memberStyle("../css/Member.css");
    memberStyle.open(QFile::ReadOnly);
    QString style = memberStyle.readAll();
    member1->setStyleSheet(style);
    member2->setStyleSheet(style);
    member3->setStyleSheet(style);
    QObject::connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openActionTriggered()));
    QObject::connect(ui->actionAdd_Team, SIGNAL(triggered()), this, SLOT(addTeamTriggered()));
    QObject::connect(monSelector, SIGNAL(currentIndexChanged(int)), this, SLOT(monSelected()));
    QObject::connect(monSelector, SIGNAL(editTextChanged(const QString &)), this, SLOT(test()));

    ui->moveTest->setMoveSet("Yache Berry", "Swords Dance",
            "Outrage", "Earthquake", "Substitute");

    setupSelector();
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

void MainWindow::setupSelector() {
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    if (!query.exec(("Select Distinct Name From battleFrontier;"))) {
        std::cerr << "query failed" << std::endl;
        std::cerr << query.lastError().text().toStdString() << std::endl;
    }
    while(query.next()) {
        monSelector->addItem(query.value(0).toString());
    }
    monSelector->setMaxVisibleItems(10);
    monSelector->showPopup();
}

void MainWindow::monSelected() {
    QString mon = monSelector->currentText();
    std::cout << monSelector->currentText().toStdString() << std::endl;
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query;
    query.prepare(("Select * from battleFrontier Where name = :name;"));
    query.bindValue(":name", mon);
    if (!query.exec()) {
        std::cerr << "query failed" << std::endl;
        std::cerr << query.lastError().text().toStdString() << std::endl;
    }
    while(query.next()) {
        std::cout << "Name: " + query.value("move1").toString().toStdString() << std::endl;
    }
}

void MainWindow::test() {
    monSelector->showPopup();
    monSelector->lineEdit()->setFocus();
    std::cout << "test" << std::endl;
}
