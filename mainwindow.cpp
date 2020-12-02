#include "mainwindow.h"
#include "startscreen.h"
#include "gamevisual.h"
#include "ui_mainwindowform.h"

#include "TankL.h"
#include "TankR.h"
#include "Bullet.h"
#include "Game.h"
#include "winnerscreen.h"
#include <QGraphicsView>
#include <QKeyEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
//    game = new Game(scene);
//    gameVisual->setFocusPolicy(Qt::StrongFocus);

//    gameVisual->scene=this->scene;
//    gameVisual->setScene();
//    scene->setSceneRect(0,0,550,525);
//    gameVisual->hide();
    StartScreen* startScreen{new StartScreen(this)};
    this->setCentralWidget(startScreen);
    connect(startScreen,SIGNAL(startButton_clicked()),SLOT(on_StartButton_clicked()));
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
//                game->move_left_tank("Left");
                moveCount++;
            }
            else if(playerNumber == 2)
            {
//                game->move_right_tank("Left");
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
//                game->move_left_tank("Right");
                moveCount++;
            }
            else if(playerNumber == 2)
            {
//                game->move_right_tank("Right");
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
        delete this->centralWidget();
//        StartScreen* startScreen2{new StartScreen(this)};

        StartScreen* startScreen{new StartScreen(this)};
        this->setCentralWidget(startScreen);
        connect(startScreen,SIGNAL(startButton_clicked()),SLOT(on_StartButton_clicked()));

//        this->setCentralWidget(startScreen);
//        gameVisual->hide();
//        startScreen->show();
        if(playerNumber == 1)
        {
//            game->left_tank_fire(velocity,angle);
            playerNumber = 2;
        }
        else if(playerNumber == 2)
        {
//            game->right_tank_fire(velocity,angle);
            playerNumber = 1;
        }
        moveCount = 0;
//        mMainWindowUI->VelocitySlider->setSliderPosition(10);
//        mMainWindowUI->AngleSlider->setSliderPosition(0);
    }
    else if(event->key() == Qt::Key_1)
    {
//        mMainWindowUI->VelocitySlider->setSliderPosition(velocity-1);
    }
    else if(event->key() == Qt::Key_3)
    {
//        mMainWindowUI->VelocitySlider->setSliderPosition(velocity+1);
    }
//    else if(event->key() == Qt::Key_4)
//    {
//        mMainWindowUI->AngleSlider->setSliderPosition(angle-1);
//        if(playerNumber == 1)
//            game->rotate_left_barrel(angle-1);
//        else
//            game->rotate_right_barrel(angle-1);
//    }
//    else if(event->key() == Qt::Key_6)
//    {
//        mMainWindowUI->AngleSlider->setSliderPosition(angle+1);
//        if(playerNumber == 1)
//            game->rotate_left_barrel(angle+1);
//        else
//            game->rotate_right_barrel(angle+1);
//    }
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}



void MainWindow::on_StartButton_clicked()
{
    qDebug()<<"Test";
    delete this->centralWidget();
//    GameVisual* gameVisual{new GameVisual(this)};
//    gameVisual->setScene();
//    this->setCentralWidget(gameVisual);
    WinnerScreen* winnerScreen{new WinnerScreen};
    this->setCentralWidget(winnerScreen);
}
