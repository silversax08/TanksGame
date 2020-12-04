#include "gamevisual.h"
#include "ui_gamevisual.h"

GameVisual::GameVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameVisual)
{
    ui->setupUi(this);
    game = new Game(scene);
    scene->setSceneRect(0,0,550,525);
//    scene->addItem(startScreen);
    ui->graphicsView2->setScene(scene);
}

GameVisual::~GameVisual()
{
    delete ui;
}

void GameVisual::fire_bullet()
{
    if(playerNumber == 1)
    {
        game->tank_fire(velocity,angle,1);
        playerNumber = 2;
    }
    else if(playerNumber == 2)
    {
        game->tank_fire(velocity,angle,2);
        playerNumber = 1;
    }
}

void GameVisual::rotate_barrel()
{
    if(playerNumber == 1)
        game->rotate_left_barrel(angle);
    else
        game->rotate_right_barrel(angle);
}

void GameVisual::move_tank(std::string direction)
{
    if(moveCount<=maxMovementPerTurn)
    {
        if(playerNumber == 1)
            game->move_left_tank(direction);
        else
            game->move_right_tank(direction);
        moveCount++;
        return;
    }
    else
        return;
}

void GameVisual::on_LaunchButton2_clicked()
{
    fire_bullet();
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
    rotate_barrel();
}

void GameVisual::on_VelocitySlider2_valueChanged(int value)
{
    velocity = value;
}

void GameVisual::on_AngleSlider2_valueChanged(int value)
{
    angle  = value;
    rotate_barrel();
}

void GameVisual::on_leftButton2_clicked()
{
    move_tank("Left");
}

void GameVisual::on_rightButton2_clicked()
{
    move_tank("Right");
}



