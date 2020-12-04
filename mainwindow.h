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

public slots:
    void on_actionExit_triggered();

private slots:
    void on_tank1_hit();
    void on_tank2_hit();
    void on_StartButton_clicked();
    void on_playMenu_clicked();

private:
    void set_winner_screen(int winningTank);
    void set_game_screen();
    Ui::MainWindowForm *mMainWindowUI;
};

#endif // MAINWINDOW_H
