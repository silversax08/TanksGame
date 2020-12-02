#ifndef WINNERSCREEN_H
#define WINNERSCREEN_H

#include <QWidget>
#include <QGraphicsScene>
#include <QPixmap>
#include <QPaintEvent>

namespace Ui {
class WinnerScreen;
}

class WinnerScreen : public QWidget
{
    Q_OBJECT

public:
    explicit WinnerScreen(QWidget *parent = nullptr);
    ~WinnerScreen();

private slots:
    void on_menuButton_clicked();

    void on_quitButton_clicked();

signals:
    void menuButton_clicked();

private:
    void paint_event(QPaintEvent* event);
    Ui::WinnerScreen *ui3;
    QGraphicsScene* scene{new QGraphicsScene};
    QPixmap winner1{QPixmap(":/myicons/Player1.png")};
//    QPaintEvent *event;

};

#endif // WINNERSCREEN_H
