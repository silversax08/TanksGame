#include "winnerscreen.h"
#include "ui_winnerscreen.h"
#include <QPainter>
#include <QPaintEvent>

WinnerScreen::WinnerScreen(QWidget *parent) :
    QWidget(parent),
    ui3(new Ui::WinnerScreen)
{
    ui3->setupUi(this);
//    scene->addItem(winner1->scaled(790,578));
//    scene->setSceneRect(0,0,790,578);
//    ui3->graphicsView->setScene(scene);
//    int w = ui3->label->width();
//    int h = ui3->label->height();
//    ui3->label->setPixmap(winner1->scaled(w,h,Qt::KeepAspectRatio));
//    QPainter painter(this);
//    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
//    QPoint topLeftPosition(winner1.width()-1 - painter.viewport().width(), 0);
//    QRectF pixmapSourceRectangle(topLeftPosition, painter.viewport().size());
//    painter.drawPixmap(painter.viewport(), winner1, pixmapSourceRectangle);
//    paint_event(event);

}

WinnerScreen::~WinnerScreen()
{
    delete ui3;
}

void WinnerScreen::paint_event(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPoint topLeftPosition(winner1.width()-1 - painter.viewport().width(), 0);
    QRectF pixmapSourceRectangle(topLeftPosition, painter.viewport().size());
    painter.drawPixmap(painter.viewport(), winner1, pixmapSourceRectangle);
}

void WinnerScreen::on_menuButton_clicked()
{
    emit(menuButton_clicked());
}

void WinnerScreen::on_quitButton_clicked()
{

}
