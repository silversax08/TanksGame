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
    tank2->setRect(-10,0,100,100);
    scene->addItem(tank);
    scene->addItem(tank2);
    mMainWindowUI->graphicsView->setScene(scene);
//    mMainWindowUI->graphicsView->setFixedSize(750,650);
    scene->setSceneRect(0,0,550,525);
//    tank->setFlag(QGraphicsItem::ItemIsFocusable);
//    tank->setFocus();
//    mMainWindowUI->graphicsView->setFocusPolicy( Qt::StrongFocus );
    this->setFocusPolicy( Qt::StrongFocus );
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
//    qDebug() << "Key Pushed 1";
//    if (event->key() == Qt::Key_Left)
//        tank->setPos(x()-10,y());
}



void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_LaunchButton_clicked()
{
    Bullet* bullet{new Bullet};
    scene->addItem(bullet);
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
