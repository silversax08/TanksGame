#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

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
    void on_tank1_hit();
    void on_tank2_hit();
    void on_StartButton_clicked();
    void on_playMenu_clicked();

private:
    Ui::MainWindowForm *mMainWindowUI;
    int velocity{10};
    int angle{0};
    int playerNumber{1};
    int moveCount{0};
    int maxMovementPerTurn{5};
};

#endif // MAINWINDOW_H
