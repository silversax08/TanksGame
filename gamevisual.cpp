#include "gamevisual.h"
#include "ui_gamevisual.h"

GameVisual::GameVisual(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameVisual)
{
    ui->setupUi(this);
}

GameVisual::~GameVisual()
{
    delete ui;
}
