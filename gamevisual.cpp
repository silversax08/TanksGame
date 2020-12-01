#include "gamevisual.h"
#include "ui_gamevisual.h"
#include <QDebug>

GameVisual::GameVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameVisual)
{
    ui->setupUi(this);
    game = new Game(scene);
    scene->setSceneRect(0,0,550,525);
}

GameVisual::~GameVisual()
{
    delete ui;
}

void GameVisual::setScene()
{
    ui->graphicsView2->setScene(scene);
}

void GameVisual::on_LaunchButton2_clicked()
{
    qDebug()<<"Test";

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
    ui->VelocitySlider2->setSliderPosition(10);
    ui->AngleSlider2->setSliderPosition(0);
}

void GameVisual::on_VelocitySlider2_sliderMoved(int position)
{
    velocity = position;
}

void GameVisual::on_AngleSlider2_sliderMoved(int position)
{
    angle  = position;
    if(playerNumber == 1)
        game->rotate_left_barrel(angle);
    else
        game->rotate_right_barrel(angle);
}

void GameVisual::on_VelocitySlider2_valueChanged(int value)
{
    velocity = value;
}

void GameVisual::on_AngleSlider2_valueChanged(int value)
{
    angle  = value;
    if(playerNumber == 1)
        game->rotate_left_barrel(angle);
    else
        game->rotate_right_barrel(angle);
}

void GameVisual::on_leftButton2_clicked()
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

void GameVisual::on_rightButton2_clicked()
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



