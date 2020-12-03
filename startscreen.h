#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QPainter>

namespace Ui {
class StartScreen;
}

class StartScreen : public QWidget
{
    Q_OBJECT

public:
    explicit StartScreen(QWidget *parent = nullptr);
    ~StartScreen();

private:
    void paintEvent(QPaintEvent* event);
    QPixmap startScreen{QPixmap(":/myicons/startscreen.png")};
    Ui::StartScreen *ui;

signals:
    void startButton_clicked();

private slots:
    void on_StartButton_clicked();
};

#endif // STARTSCREEN_H
