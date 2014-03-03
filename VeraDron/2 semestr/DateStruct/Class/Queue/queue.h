#pragma once
const int MAX_SIZE = 1000;
class Queue
{
public:
    Queue();
    void push(int d);
    int pop();
    int front();
    bool clear();
    bool isEmpty();
    int size() const;

protected:
    int m_size;
    int array[MAX_SIZE];
private:
    int begin;
    int end;
};

