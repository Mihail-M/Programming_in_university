#pragma once

class Calc
{
public:
    Calc();
    double calculate(char *input);

private:
    bool isOperator(char a);
    bool isStaple(char a);
    int priority(char c);
    void makePolishNotation(char *inputStr, char *queueOut);
};

