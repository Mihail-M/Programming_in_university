#pragma once

class Writer
{

public:

    virtual ~Writer();
    ///print answer
    virtual void print(int n, int **array) = 0;
    int *getAns(int n, int **array);

protected:
    ///get spiral walk
    ///ger next step inspiral walk
    void getNext(int **array ,int x, int y, int r, int *ans, int &counter);// вывод очередного витка

};


