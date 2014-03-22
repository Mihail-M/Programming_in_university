#pragma once
#include <iostream>

const int MinCapacity = 4;
using namespace std;
class StringBBC
{
public:
    StringBBC();
    StringBBC(char *str1);
    StringBBC(int size, int capacity);
    bool empty();
    void push_back(char c);
    void pop_back();

    int size();
    int capacity();
    void clear();
    void insert(int pos, char* str1);
    void erase(int pos, int count);
    friend ostream &operator<<(ostream &stream, const StringBBC &s);
    friend istream &operator>>(istream &stream, StringBBC &s);
    friend StringBBC operator +(StringBBC &a, StringBBC &b);
    StringBBC operator  += (StringBBC b);
    char &operator [](int i);
private:
    char *str;
    int mySize;
    int myCapacity;
    int getNewCapacity(int count);
    void rewrite(char *&newStr, char *str, int n);



};

