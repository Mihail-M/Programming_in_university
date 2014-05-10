#include <QtDebug>
#include <QMessageBox>
#include "time.h"
#include "crossesandzeros.h"
#include "ui_crossesandzeros.h"

CrossesAndZeros::CrossesAndZeros(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CrossesAndZeros),
    currentSize(0)
{
    ui->setupUi(this);
    generateField();

    qsrand(time(nullptr));

    connect(ui->genButton, SIGNAL(clicked()), this, SLOT(generateField()));
}

CrossesAndZeros::~CrossesAndZeros()
{
    delete ui;
}

void CrossesAndZeros::generateField()
{
    const unsigned int newSize = ui->spinBox->value();
    for (unsigned int i = 0; i < currentSize; i++)
    {
        for (unsigned int j = 0; j < currentSize; j++)
        {
            delete ui->gridLayout->itemAtPosition(i, j)->widget();
        }
    }
    field.clear();
    for (unsigned int i = 0; i < newSize; i++)
    {
        for (unsigned int j = 0; j < newSize; j++)
        {
            QPushButton* button = new QPushButton;
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            ui->gridLayout->addWidget(button, i, j);
            button->setText(" ");

            connect(button, SIGNAL(clicked()), this, SLOT(buttonClicked()));

            field[button] = 0;
        }
    }

    currentSize = newSize;
    turn = 0;
}

void CrossesAndZeros::buttonClicked()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    button->setEnabled(false);
    button->setIcon(QIcon(QPixmap("res/tic.jpg")));
    button->setIconSize(QSize(160,160));

    field[button] = 1;
    turn++;

    unsigned int pos = 0;
    while (qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(pos / currentSize, pos % currentSize)->widget()) != button)
    {
        pos++;
    }

    bool userWin = findWinner(pos, 1);
    if (!userWin && (currentSize * currentSize != turn))
    {
        computersTurn();
    }
    else if (userWin)
    {
        QMessageBox::information(this, "Win!", "You win!");
        generateField();
    }
    else
    {
        QMessageBox::information(this, "Draw!", "No one loose");
        generateField();
    }
}

bool CrossesAndZeros::isPart(int i, int j, unsigned int player)
{
    return ((i >= 0) && (i < static_cast<int>(currentSize))
            && (j >= 0) && (j < static_cast<int>(currentSize))
            && (field[qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget())] == player));
}

bool CrossesAndZeros::findWinner(unsigned int pos, unsigned int player)
{
    bool win = false;
    int i = pos / currentSize;
    int j = pos % currentSize;

    //vertical
    if (isPart(i - 1, j, player))
    {
        if (isPart(i - 2, j, player) || isPart(i + 1, j, player))
        {
            win = true;
        }
    }
    if (isPart(i + 1, j, player) && isPart(i + 2, j, player))
    {
        win = true;
    }
    //horisontal
    if (isPart(i, j - 1, player))
    {
        if (isPart(i, j - 2, player) || isPart(i, j + 1, player))
        {
            win = true;
        }
    }
    if (isPart(i, j + 1, player) && isPart(i, j + 2, player))
    {
        win = true;
    }
    //diag1
    if (isPart(i - 1, j - 1, player))
    {
        if (isPart(i - 2, j - 2, player) || isPart(i + 1, j + 1, player))
        {
            win = true;
        }
    }
    if (isPart(i + 1, j + 1, player) && isPart(i + 2, j + 2, player))
    {
        win = true;
    }
    //diag2
    if (isPart(i - 1, j + 1, player))
    {
        if (isPart(i - 2, j + 2, player) || isPart(i + 1, j - 1, player))
        {
            win = true;
        }
    }
    if (isPart(i + 1, j - 1, player) && isPart(i + 2, j - 2, player))
    {
        win = true;
    }

    return win;
}

void CrossesAndZeros::computersTurn()
{
    QPushButton* buttonForComputer = nullptr;
    do
    {
        unsigned int i = qrand() % currentSize;
        unsigned int j = qrand() % currentSize;
        buttonForComputer = qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(i, j)->widget());
    } while (field[buttonForComputer]);

    buttonForComputer->setEnabled(false);
    buttonForComputer->setIcon(QIcon(QPixmap("res/toe.jpg")));
    buttonForComputer->setIconSize(QSize(160,160));

    field[buttonForComputer] = 2;
    turn++;
    unsigned int pos = 0;
    while (qobject_cast<QPushButton*>(ui->gridLayout->itemAtPosition(pos / currentSize, pos % currentSize)->widget()) != buttonForComputer)
    {
        pos++;
    }

    bool compWin = findWinner(pos, 2);
    if (!compWin && (currentSize * currentSize != turn))
    {
    }
    else if (compWin)
    {
        QMessageBox::information(this, "Loose!", "Matan win!");
        generateField();
    }
    else
    {
        QMessageBox::information(this, "Draw!", "No one loose");
        generateField();
    }
}
