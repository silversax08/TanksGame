#include "startscreen.h"
#include "ui_startscreen.h"

StartScreen::StartScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartScreen)
{
    ui->setupUi(this);
}

StartScreen::~StartScreen()
{
    delete ui;
}

void StartScreen::on_StartButton_clicked()
{
    emit(startButton_clicked());
}

void StartScreen::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    QPoint topLeftPosition(startScreen.width()-1 - painter.viewport().width(), 0);
    QRectF pixmapSourceRectangle(topLeftPosition, painter.viewport().size());
    painter.drawPixmap(painter.viewport(), startScreen, pixmapSourceRectangle);
}
