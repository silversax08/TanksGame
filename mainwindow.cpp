#include "mainwindow.h"
#include "ui_mainwindowform.h"
#include "startscreen.h"
#include "gamevisual.h"
#include "winnerscreen.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
    StartScreen* startScreen{new StartScreen(this)};
    this->setCentralWidget(startScreen);
    connect(startScreen,SIGNAL(startButton_clicked()),SLOT(on_StartButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_tank1_hit()
{
    set_winner_screen(2);
}

void MainWindow::on_tank2_hit()
{
    set_winner_screen(1);
}

void MainWindow::on_StartButton_clicked()
{
    set_game_screen();
}

void MainWindow::on_playMenu_clicked()
{
    set_game_screen();
}

void MainWindow::set_winner_screen(int winningTank)
{
    delete this->centralWidget();
    WinnerScreen* winnerScreen{new WinnerScreen(this,winningTank)};
    this->setCentralWidget(winnerScreen);
    connect(winnerScreen,SIGNAL(playButton_clicked()),SLOT(on_playMenu_clicked()));
}

void MainWindow::set_game_screen()
{
    delete this->centralWidget();
    GameVisual* gameVisual{new GameVisual(this)};
    this->setCentralWidget(gameVisual);
    connect(gameVisual->game,SIGNAL(tank1_hit()),SLOT(on_tank1_hit()));
    connect(gameVisual->game,SIGNAL(tank2_hit()),SLOT(on_tank2_hit()));
}
