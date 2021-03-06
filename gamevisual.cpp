#include "gamevisual.h"
#include "ui_gamevisual.h"

GameVisual::GameVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameVisual)
{
    ui->setupUi(this);
    game = new Game(scene);
    game->set_active_tank(playerNumber);
    scene->setSceneRect(20,0,550,525);
    ui->graphicsView2->setScene(scene);
    set_turn_text();
}

GameVisual::~GameVisual()
{
    delete ui;
}

void GameVisual::fire_bullet()
{
    game->tank_fire(velocity,angle);
    if(playerNumber == 1)
        playerNumber = 2;
    else
        playerNumber = 1;
    set_turn_text();
    game->set_active_tank(playerNumber);
}

void GameVisual::rotate_barrel()
{
    game->rotate_barrel(angle);
}

void GameVisual::set_turn_text()
{
    if(playerNumber==1)
        ui->label->setText("Player: Left Tank");
    else
        ui->label->setText("Player: Right Tank");
}

void GameVisual::move_tank(std::string direction)
{
    if(moveCount<=maxMovementPerTurn)
    {
        game->move_tank(direction,playerNumber);
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



