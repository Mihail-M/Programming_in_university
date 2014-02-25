#pragma once

class Sorter
{
public:
    Sorter(int *A);

    virtual int *getSortArray(int l, int r) = 0;
    virtual int *getSortArray(int l, int r, bool (*comp)(int, int)) = 0;

protected:
    int *array;
<<<<<<< HEAD
    virtual void sort(int l, int r) = 0;
    virtual void sort(int l, int r, bool (*comp)(int, int) ) = 0;
=======
    virtual  void sort(int l, int r) = 0;
    virtual void sort(int l, int r, bool (*comp)(int, int) ) = 0;


};
>>>>>>> 3eea7b64449040fd47ba443484c01f724dafd2db

};
