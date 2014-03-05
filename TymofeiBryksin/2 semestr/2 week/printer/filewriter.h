#pragma once
#include "writer.h"

class FileWriter : public Writer
{
public:
     ~FileWriter();
    ///print spiral walk in file
    void print(int n, int **array);

};

