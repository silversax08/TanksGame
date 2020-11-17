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
    tank->setRect(-10,0,100,100);
//    tank2->setRect(-10,0,100,100);
    scene->addItem(tank);
//    scene->addItem(tank2);
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
        tank->move_tank_left();
        return;
    }
    else if(event->key() == Qt::Key_Right)
    {
        tank->move_tank_right();
        return;
    }
    else if(event->key() == Qt::Key_Space)
    {
        Bullet* bullet{new Bullet(tank->get_position(),velocity,angle)};
        bullet->setRect(-10,0,10,10);
        tank->scene()->addItem(bullet);
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
    Bullet* bullet{new Bullet(tank->get_position(),velocity,angle)};
    bullet->setRect(-10,0,10,10);
    tank->scene()->addItem(bullet);
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
    tank->move_tank_left();
}

void MainWindow::on_rightButton_clicked()
{
    tank->move_tank_right();
}
