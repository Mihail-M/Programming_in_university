#include "array.h"

template <class T>
Array<T>::Array()
{
}

template <class T> Array<T>(int m_size)
{
    size = m_size;
    p = new T[m_size];
}

template <class T>
Array<T>(Array<T> &a)
{
    size = a.size;
    p = new T[size];
    for(int i = 0; i < size; i++)
        p[i] = a.p[i];
}

template <class T>
Array<T>::~Array()
{
    delete[] p;
}

template <class T>
int Array<T>::Array::getSize() const
{
    return size;
}
template <class T>

Array<T> &Array<T>::Array::operator=(const Array<T> &a)
{
    size = a.size;
    delete[] p;
    p = new T[size];
    for(int i = 0; i < size; i++)
        p[i] = a.p[i];
    return (*this);
}
template <class T>

Array<T> &Array<T>::Array::operator[](int ind)
{
    return p[ind];
}


