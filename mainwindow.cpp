#include "mainwindow.h"
#include "ui_mainwindowform.h"

#include <QGraphicsRectItem>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow{parent},
    mMainWindowUI{new Ui::MainWindowForm}
{
    mMainWindowUI->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete mMainWindowUI;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_LaunchButton_clicked()
{
    QGraphicsScene* scene = new QGraphicsScene;
    QGraphicsRectItem* rect = new QGraphicsRectItem;
    rect->setRect(0,0,100,100);
    scene->addItem(rect);
//    QGraphicsView* view = new QGraphicsView(scene);
//    view->show();
//    mMainWindowUI->graphicsView->scene();
    mMainWindowUI->graphicsView->setScene(scene);
//    mMainWindowUI->graphicsView->show();
//    mMainWindowUI->OSGOutput->sphere_setup(velocity, angle);
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
