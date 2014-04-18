#include "queue.h"

Queue::Queue(): m_size(0), begin(0), end(0)
{
}

void Queue::push(int d)
{
    if(!full()){
        array[end] = d;
        if(end + 1 >= MAX_SIZE)
            end = 0;
        else end++;
        m_size++;
    }
}

int Queue::pop()
{
    if(!isEmpty()){
        int ans = front();
        if(begin + 1 >= MAX_SIZE)
            begin = 0;
        else
            begin++;
        m_size--;
        return ans;
    }
    return -1;
}

int Queue::front()
{
    return array[begin];
}

void Queue::clear()
{
    m_size = 0;
    begin = 0;
    end = 0;
}

bool Queue::isEmpty()
{
    return (m_size == 0);
}
int Queue::size() const
{
    return m_size;
}

bool Queue::full()
{
    return (m_size == MAX_SIZE);
}

