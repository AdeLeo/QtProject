#ifndef STARWIDGET_H
#define STARWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QTimer>

namespace Ui {
class StarWidget;
}

class StarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StarWidget(QWidget *parent = 0);
    ~StarWidget();
    void paintEvent(QPaintEvent *e);
    void timerEvent(QTimerEvent *e);

private slots:
    void on_radioButtonDaytime_clicked();

    void on_radioButtonNight_clicked();

    void on_checkBox_clicked();

private:
    Ui::StarWidget *ui;
    bool dayTimeFlag;
    bool moonFlag;
    int x[100];
    int y[100];
};

#endif // STARWIDGET_H
