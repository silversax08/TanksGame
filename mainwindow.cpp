#include "mainwindow.h"
#include "ui_mainwindowform.h"

#include "TankL.h"
#include "TankR.h"
#include "Bullet.h"
#include "Game.h"
#include <QGraphicsView>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
    game = new Game(scene);

    mMainWindowUI->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,550,525);
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString keyString   = event->text();

    if( event->key() == Qt::Key_Left )
    {
        if(moveCount<=maxMovementPerTurn)
        {
            if(playerNumber == 1)
            {
                game->move_left_tank("Left");
                moveCount++;
            }
            else if(playerNumber == 2)
            {
                game->move_right_tank("Left");
                moveCount++;
            }
            return;
        }
        else
        {
            return;
        }
    }
    else if(event->key() == Qt::Key_Right)
    {
        if(moveCount<=maxMovementPerTurn)
        {
            if(playerNumber == 1)
            {
                game->move_left_tank("Right");
                moveCount++;
            }
            else if(playerNumber == 2)
            {
                game->move_right_tank("Right");
                moveCount++;
            }
            return;
        }
        else
        {
            return;
        }
    }
    else if(event->key() == Qt::Key_Space)
    {
        if(playerNumber == 1)
        {
            game->left_tank_fire(velocity,angle);
            playerNumber = 2;
        }
        else if(playerNumber == 2)
        {
            game->right_tank_fire(velocity,angle);
            playerNumber = 1;
        }
        moveCount = 0;
        mMainWindowUI->VelocitySlider->setSliderPosition(10);
        mMainWindowUI->AngleSlider->setSliderPosition(0);
    }
    else if(event->key() == Qt::Key_1)
    {
        mMainWindowUI->VelocitySlider->setSliderPosition(velocity-1);
    }
    else if(event->key() == Qt::Key_3)
    {
        mMainWindowUI->VelocitySlider->setSliderPosition(velocity+1);
    }
    else if(event->key() == Qt::Key_4)
    {
        mMainWindowUI->AngleSlider->setSliderPosition(angle-1);
        if(playerNumber == 1)
            game->rotate_left_barrel(angle-1);
        else
            game->rotate_right_barrel(angle-1);
    }
    else if(event->key() == Qt::Key_6)
    {
        mMainWindowUI->AngleSlider->setSliderPosition(angle+1);
        if(playerNumber == 1)
            game->rotate_left_barrel(angle+1);
        else
            game->rotate_right_barrel(angle+1);
    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_LaunchButton_clicked()
{
    if(playerNumber == 1)
    {
        game->left_tank_fire(velocity,angle);
        playerNumber = 2;
    }
    else if(playerNumber == 2)
    {
        game->right_tank_fire(velocity,angle);
        playerNumber = 1;
    }
    moveCount = 0;
    mMainWindowUI->VelocitySlider->setSliderPosition(10);
    mMainWindowUI->AngleSlider->setSliderPosition(0);
}

void MainWindow::on_VelocitySlider_sliderMoved(int position)
{
    velocity = position;
}

void MainWindow::on_AngleSlider_sliderMoved(int position)
{
    angle  = position;
    if(playerNumber == 1)
        game->rotate_left_barrel(angle);
    else
        game->rotate_right_barrel(angle);
}

void MainWindow::on_VelocitySlider_valueChanged(int value)
{
    velocity = value;
}

void MainWindow::on_AngleSlider_valueChanged(int value)
{
    angle  = value;
    if(playerNumber == 1)
        game->rotate_left_barrel(angle);
    else
        game->rotate_right_barrel(angle);
}

void MainWindow::on_leftButton_clicked()
{
    if(moveCount<=maxMovementPerTurn)
    {
        if(playerNumber == 1)
        {
            game->move_left_tank("Left");
            moveCount++;
        }
        else if(playerNumber == 2)
        {
            game->move_right_tank("Left");
            moveCount++;
        }
        return;
    }
    else
    {
        return;
    }
}

void MainWindow::on_rightButton_clicked()
{
    if(moveCount<=maxMovementPerTurn)
    {
        if(playerNumber == 1)
        {
            game->move_left_tank("Right");
            moveCount++;
        }
        else if(playerNumber == 2)
        {
            game->move_right_tank("Right");
            moveCount++;
        }
        return;
    }
    else
    {
        return;
    }
}
