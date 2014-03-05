#pragma once

#include "writer.h"

class ConsoleWriter : public Writer
{
public:
    ~ConsoleWriter();

    ///print spiral walk in console
    void print(int n, int **array);
};
