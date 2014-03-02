#pragma once

class Writer
{

public:

    Writer();
    virtual ~Writer();
    virtual void print(int n, int **array) = 0;

protected:

    int *getAns(int n, int **array);
    void getNext(int **array ,int x, int y, int r, int *ans, int &counter);// вывод очередного витка

};


