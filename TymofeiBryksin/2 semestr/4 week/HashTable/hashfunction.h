#pragma once
#include <string>

class HashFunction
{
public:
    virtual int calculateHashFunction(std::string s, int size) = 0;
};

HashFunction *getHashFunction(int n);

