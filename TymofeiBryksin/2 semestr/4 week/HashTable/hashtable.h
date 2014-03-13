#pragma once
#include "acicliclist.h"
#include "hashfunction.h"
/**
 * @brief The HashTable class
 */

class HashTable
{
public:
    HashTable();
    HashTable(int size);

    ~HashTable();

    /// \brief add
    /// add element value in hash table
    void add(valueType value);

    /// \brief erase
    /// delete element value in hash table(if this element exist)

    void erase(valueType value);
    ///
    /// \brief find
    /// find
    /// \return false - element exist, true - element - not exist

    bool find(valueType value);
    ///
    /// \brief @function showStatistic
    /// show count of elements, load factor, count of conflicts, max count of list in conflict elements, etc
    void showStatistic();
    void show();
    HashFunction *hashFunc;

private:
    ///count element in hash table
    int countOfElements;
    int arraySize;
    AciclicList *array;
    int *countOfCollision;
    int maxListSize;
    double loadFactor;
    void init(int size);
    void rebuild(int size);


};

