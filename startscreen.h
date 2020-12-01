#ifndef STARTSCREEN_H
#define STARTSCREEN_H

#include <QWidget>
#include <QGraphicsScene>

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
    Ui::StartScreen *ui;
    QGraphicsScene* scene{new QGraphicsScene};

signals:
    void startButton_clicked();

private slots:
    void on_StartButton_clicked();
};

#endif // STARTSCREEN_H
