#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
#include <array>
#include "Tank.h"

namespace Ui {
class MainWindowForm;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    virtual void keyPressEvent( QKeyEvent* event );
public slots:
    void on_actionExit_triggered();
private slots:
    void on_LaunchButton_clicked();
    void on_VelocitySlider_sliderMoved(int position);
    void on_AngleSlider_sliderMoved(int position);
    void on_VelocitySlider_valueChanged(int value);
    void on_AngleSlider_valueChanged(int value);
    void on_leftButton_clicked();

    void on_rightButton_clicked();

private:
    Ui::MainWindowForm *mMainWindowUI;
    int velocity{10};
    int angle{0};
    std::array<int,2> tank1Position{50,350};
    std::array<int,2> tank2Position{450,350};
    QGraphicsScene* scene{new QGraphicsScene};
    Tank* tank{new Tank(tank1Position[0],tank1Position[1])};
    Tank* tank2{new Tank(tank2Position[0],tank2Position[1])};
};

#endif // MAINWINDOW_H
