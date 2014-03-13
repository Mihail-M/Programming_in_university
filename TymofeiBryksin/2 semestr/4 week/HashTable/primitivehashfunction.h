#pragma once
#include "hashfunction.h"

class PrimitiveHashFunction : public HashFunction
{
public:
    int calculateHashFunction(std::string s, int size);
};

