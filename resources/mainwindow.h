#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
private:
    Ui::MainWindow *ui;
    Member* member1;
    Member* member2;
    Member* member3;
};

#endif // MAINWINDOW_H
