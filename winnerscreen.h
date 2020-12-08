#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class WinnerScreen;
}

class WinnerScreen : public QWidget
{
    Q_OBJECT
public:
    explicit WinnerScreen(QWidget *parent = nullptr, int winningTank = 1);
    ~WinnerScreen();

private slots:
    void on_playButton_clicked();
    void on_quitButton_clicked();

signals:
    void playButton_clicked();

private:
    void paintEvent(QPaintEvent *event);
    Ui::WinnerScreen *ui;
    QPixmap winner;
};

#endif // WINNERSCREEN_H
