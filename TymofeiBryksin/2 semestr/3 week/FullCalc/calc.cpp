#include "calc.h"
#include "ui_widget.h"

Calc::Calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc)
{
    ui->setupUi(this);
    numbersMapper = new QSignalMapper(this);
    connect(ui->button0, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button0, 0);
    connect(ui->button1, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button1, 1);
    connect(ui->button2, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button2, 2);
    connect(ui->button3, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button3, 3);
    connect(ui->button4, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button4, 4);
    connect(ui->button5, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button5, 5);
    connect(ui->button6, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button6, 6);
    connect(ui->button7, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button7, 7);
    connect(ui->button8, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button8, 8);
    connect(ui->button9, SIGNAL(pressed()), numbersMapper, SLOT(map()));
    numbersMapper->setMapping(ui->button9, 9);

    connect(numbersMapper, SIGNAL(mapped(int)), this, SLOT(numberPressed(int)));
    connect(ui->buttonDot, SIGNAL(pressed()), this, SLOT(dotPressed()));

    operationMapper = new QSignalMapper(this);
    connect(ui->buttonAddition, SIGNAL(pressed()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->buttonAddition, 1);
    connect(ui->buttonSubtraction, SIGNAL(pressed()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->buttonSubtraction, 2);
    connect(ui->buttonMultiplication, SIGNAL(pressed()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->buttonMultiplication, 3);
    connect(ui->buttonDivision, SIGNAL(pressed()), operationMapper, SLOT(map()));
    operationMapper->setMapping(ui->buttonDivision, 4);

    connect(operationMapper, SIGNAL(mapped(int)), this, SLOT(operandPressed(int)));

    connect(ui->buttonEqually, SIGNAL(pressed()), this, SLOT(equalPressed()));
    connect(ui->buttonClear, SIGNAL(pressed()), this, SLOT(clearCalc()));

}

Calc::~Calc()
{
    delete ui;
}

void Calc::numberPressed(const int number)
{
    ui->result->setText(calcRobot.appendNumber(number));
    return;
}

void Calc::dotPressed()
{
    ui->result->setText(calcRobot.appendDot());
    return;
}

void Calc::equalPressed()
{
    ui->result->setText(calcRobot.calculate());

}

void Calc::operandPressed(int operand)
{
    calcRobot.addOperand(operand);
    ui->result->setText("");
}

void Calc::clearCalc()
{
    ui->result->setText("");
    calcRobot.clear();
}

