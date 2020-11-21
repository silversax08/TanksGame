#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <array>
#include "TankL.h"
#include "TankR.h"
#include "BarrelL.h"
#include "BarrelR.h"
#include "Game.h"

namespace Ui {
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void keyPressEvent( QKeyEvent* event );
public slots:
    void on_actionExit_triggered();
private slots:
    void on_LaunchButton_clicked();
    void on_VelocitySlider_sliderMoved(int position);
    void on_AngleSlider_sliderMoved(int position);
    void on_VelocitySlider_valueChanged(int value);
    void on_AngleSlider_valueChanged(int value);
    void on_leftButton_clicked();

    void on_rightButton_clicked();

private:
    Ui::MainWindowForm *mMainWindowUI;
    int velocity{10};
    int angle{0};
    int playerNumber{1};
    int moveCount{0};
    int maxMovementPerTurn{5};
    QGraphicsScene* scene{new QGraphicsScene};
    Game* game;
};

#endif // MAINWINDOW_H
