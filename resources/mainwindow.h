#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include "Member.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void openActionTriggered();
    void addTeamTriggered();
    void monSelected();
    void test();
private:
    void setupSelector();
    Ui::MainWindow *ui;
    Member* member1;
    Member* member2;
    Member* member3;
    QComboBox *monSelector;
};

#endif // MAINWINDOW_H
