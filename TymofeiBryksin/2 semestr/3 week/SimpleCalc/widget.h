#pragma once
#include "counter.h"
#include <QWidget>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
public slots:
    void setValue();


private:
    Ui::Widget *ui;
    Counter calc;

};

