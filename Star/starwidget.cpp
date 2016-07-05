#include "starwidget.h"
#include "ui_starwidget.h"

StarWidget::StarWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StarWidget)
{
    ui->setupUi(this);
}

StarWidget::~StarWidget()
{
    delete ui;
}
