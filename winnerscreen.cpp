#include "winnerscreen.h"
#include "ui_winnerscreen.h"
#include <QPainter>

WinnerScreen::WinnerScreen(QWidget *parent, int winningTank) :
    QWidget(parent),
    ui3(new Ui::WinnerScreen)
{
    ui3->setupUi(this);
    if(winningTank == 1)
        winner = QPixmap(":/myicons/Player12.png");
    else
        winner = QPixmap(":/myicons/Player22.png");
}

WinnerScreen::~WinnerScreen()
{
    delete ui3;
}

void WinnerScreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPoint topLeftPosition(winner.width()-1 - painter.viewport().width(), 0);
    QRectF pixmapSourceRectangle(topLeftPosition, painter.viewport().size());
    painter.drawPixmap(painter.viewport(), winner, pixmapSourceRectangle);
}

void WinnerScreen::on_playButton_clicked()
{
    emit(playButton_clicked());
}

void WinnerScreen::on_quitButton_clicked()
{

}
