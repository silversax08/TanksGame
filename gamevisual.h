#ifndef GAMEVISUAL_H
#define GAMEVISUAL_H

#include <QWidget>

namespace Ui {
class GameVisual;
}

class GameVisual : public QWidget
{
    Q_OBJECT

public:
    explicit GameVisual(QWidget *parent = nullptr);
    ~GameVisual();

private:
    Ui::GameVisual *ui;
};

#endif // GAMEVISUAL_H
