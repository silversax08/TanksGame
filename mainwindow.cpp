#include "mainwindow.h"
#include "ui_mainwindowform.h"

#include "Tank.h"
#include "Bullet.h"
#include <QGraphicsView>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
//    tank->setRect(0,0,30,30);
//    tank2->setRect(0,0,30,30);
    scene->addItem(tank);
    scene->addItem(tank2);
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
                tank->move_tank_left();
                moveCount++;
            }
            else if(playerNumber == 2)
            {
                tank2->move_tank_left();
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
                tank->move_tank_right();
                moveCount++;
            }
            else if(playerNumber == 2)
            {
                tank2->move_tank_right();
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
            Bullet* bullet{new Bullet(tank->get_position(),velocity,angle)};
            bullet->setRect(-10,0,5,5);
            tank->scene()->addItem(bullet);
            playerNumber = 2;
        }
        else if(playerNumber == 2)
        {
            Bullet* bullet{new Bullet(tank2->get_position(),velocity,angle)};
            bullet->setRect(-10,0,5,5);
            tank->scene()->addItem(bullet);
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
    }
    else if(event->key() == Qt::Key_6)
    {
        mMainWindowUI->AngleSlider->setSliderPosition(angle+1);
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
        Bullet* bullet{new Bullet(tank->get_position(),velocity,angle)};
        bullet->setRect(-10,0,5,5);
        tank->scene()->addItem(bullet);
        playerNumber = 2;
    }
    else if(playerNumber == 2)
    {
        Bullet* bullet{new Bullet(tank2->get_position(),velocity,angle)};
        bullet->setRect(-10,0,5,5);
        tank->scene()->addItem(bullet);
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
}

void MainWindow::on_VelocitySlider_valueChanged(int value)
{
    velocity = value;
}

void MainWindow::on_AngleSlider_valueChanged(int value)
{
    angle  = value;
}

void MainWindow::on_leftButton_clicked()
{
    if(moveCount<=maxMovementPerTurn)
    {
        if(playerNumber == 1)
        {
            tank->move_tank_left();
            moveCount++;
        }
        else if(playerNumber == 2)
        {
            tank2->move_tank_left();
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
            tank->move_tank_right();
            moveCount++;
        }
        else if(playerNumber == 2)
        {
            tank2->move_tank_right();
            moveCount++;
        }
        return;
    }
    else
    {
        return;
    }
}
