#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->comboBox->addItem("+");
    ui->comboBox->addItem("-");
    ui->comboBox->addItem("*");
    ui->comboBox->addItem("/");
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), this, SLOT(setValue()));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setValue()));

}

Widget::~Widget()
{
    delete ui;
}

void Widget::setValue()
{
    double a = ui->spinBox->text().toDouble();
    double b = ui->spinBox_2->text().toDouble();

    char operand = (char)ui->comboBox->currentText().toStdString()[0];

    QString ans = QString::number(calc.calculate(a, b, operand));

    ui->lineEdit->setText(ans);
}
