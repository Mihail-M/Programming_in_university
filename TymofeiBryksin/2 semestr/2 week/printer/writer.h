#pragma once

class Writer
{

public:

    virtual ~Writer();
    ///print answer
    virtual void print(int n, int **array) = 0;

protected:
    ///get spiral walk
    int *getAns(int n, int **array);
    ///ger next step inspiral walk
    void getNext(int **array ,int x, int y, int r, int *ans, int &counter);// вывод очередного витка

};


