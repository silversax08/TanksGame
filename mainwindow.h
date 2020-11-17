#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QtCore>
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
    QGraphicsScene* scene{new QGraphicsScene};
    Tank* tank{new Tank};
    Tank* tank2{new Tank(240,200)};
};

#endif // MAINWINDOW_H
