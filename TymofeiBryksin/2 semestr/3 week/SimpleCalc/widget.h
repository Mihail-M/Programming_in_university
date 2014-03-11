#pragma once
#include "counter.h"
#include <QWidget>

namespace Ui {
/**
 *@Class Widger
 * отвечает за вывод на виджет информации, используя класс для вычисления Counter
 */

class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    ///@function setValue()
    ///записывает значение выражения в поле для вывода результата
    void setValue();


private:
    Ui::Widget *ui;
    Counter calc;

};

