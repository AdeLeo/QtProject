#include "starwidget.h"
#include "ui_starwidget.h"

StarWidget::StarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StarWidget)
{
    ui->setupUi(this);
    for(int i = 0; i < 100; i++)
    {
        x[i] = qrand() % width();
        y[i] = -(qrand() % height());
    }
    dayTimeFlag = true;
    startTimer(80);
    moonFlag = false;
    resize(1024, 768);
}

StarWidget::~StarWidget()
{
    delete ui;
}

void StarWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e)

    QPainter p(this);

    if(moonFlag && !dayTimeFlag)
    {
        p.setBrush(Qt::white);
        p.setPen(Qt::black);
        p.drawEllipse(100, 100, 80, 80);
        p.setBrush(Qt::black);
        p.setPen(Qt::black);
        p.drawEllipse(90, 80, 80, 80);
    }

    if(dayTimeFlag)
    {
        setStyleSheet("background-color: rgb(255, 255, 255);");
        p.setPen(Qt::black);
    }
    else
    {
        setStyleSheet("background-color: rgb(0, 0, 0);");
        p.setPen(Qt::white);
    }



    for(int i = 0; i < 100; i++)
    {
        p.drawText(x[i], y[i], "*");
    }

}

void StarWidget::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e)

    for(int i = 0; i < 100; i++)
    {
        y[i] += 10;
        if(y[i] > height() - 10)
        {
            y[i] = -(qrand() % height());
            x[i] = qrand() % width();
        }
    }

    update();
}

void StarWidget::on_radioButtonDaytime_clicked()
{
    dayTimeFlag = true;
}

void StarWidget::on_radioButtonNight_clicked()
{
    dayTimeFlag = false;
}

void StarWidget::on_checkBox_clicked()
{
    moonFlag = !moonFlag;
}
