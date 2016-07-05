#ifndef STARWIDGET_H
#define STARWIDGET_H

#include <QWidget>

namespace Ui {
class StarWidget;
}

class StarWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StarWidget(QWidget *parent = 0);
    ~StarWidget();

private:
    Ui::StarWidget *ui;
};

#endif // STARWIDGET_H
