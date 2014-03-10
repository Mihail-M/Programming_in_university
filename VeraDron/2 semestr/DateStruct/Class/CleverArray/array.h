#pragma once
#include <cstdlib>

template <class T>
class Array
{
public:
    Array();
    Array(int m_size);
    Array(Array &a);
    ~Array();

    int getSize() const;
    bool operator==(Array &b);
    Array &operator=(Array &b);
    T &operator[](int ind);
private:
    int size;
    T *p;
};

template <class T>
bool Array<T>::operator ==(Array<T> &b)
{
    if (size != b.size)
        return 0;
    else
        for(int i = 0; i < size; i++)
            if(p[i] != b[i])
                return 0;

    return 1;
}


template <class T>
Array<T>::Array()
{
}

template <class T> Array<T>::Array(int m_size)
{
    size = m_size;
    p = new T[m_size];
}

template <class T>
Array<T>::Array(Array<T> &a)
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
Array<T> &Array<T>::operator=(Array<T> &a)
{
    //добавить проверку
    if(*this == a) return *this;
    size = a.size;
    delete[] p;
    p = new T[size];
    for(int i = 0; i < size; i++)
        p[i] = a.p[i];

    return (*this);

}
template <class T> T &Array<T>::operator[](int ind)
{
    if(ind >= size)
        exit(EXIT_FAILURE);
    return p[ind];
}





