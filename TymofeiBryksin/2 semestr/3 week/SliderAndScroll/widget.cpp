#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(sliderMoved(int)), ui->verticalScrollBar, SLOT(setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}
