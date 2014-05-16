#pragma once
#include "hashfunction.h"

class PowerHashFunction : public HashFunction
{
public:
    int calculateHashFunction(std::string s, int size);
};

