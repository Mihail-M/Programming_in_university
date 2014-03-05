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
    QString ans;
    if (ui->comboBox->currentText() == "+")
        ans = QString::number((ui->spinBox->text().toDouble() + ui->spinBox_2->text().toDouble()));
    if (ui->comboBox->currentText() == "-")
        ans = QString::number((ui->spinBox->text().toDouble() - ui->spinBox_2->text().toDouble()));
    if (ui->comboBox->currentText() == "*")
        ans = QString::number((ui->spinBox->text().toDouble() * ui->spinBox_2->text().toDouble()));
    if (ui->comboBox->currentText() == "/")
        ans = QString::number((ui->spinBox->text().toDouble() / ui->spinBox_2->text().toDouble()));

    ui->lineEdit->setText(ans);
}
