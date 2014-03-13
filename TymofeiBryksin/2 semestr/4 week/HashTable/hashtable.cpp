#include "hashtable.h"
#include  <iostream>
#include  <cstring>


HashTable::HashTable():hashFunc(getHashFunction(2))
{
    init(10);
}

HashTable::HashTable(int size):hashFunc(getHashFunction(2))
{
    init(size);

}
HashTable::~HashTable()
{
    for (int i = 0; i < arraySize; i++)
        array[i].clear();
    delete[] array;
    delete[] countOfCollision;

}

void HashTable::add(valueType value)
{
    int key = hashFunc->calculateHashFunction(value, arraySize);

    if (array[key].find(value))
        return;

    array[key].pushBack(value);
    countOfCollision[key]++;

    if (array[key].size() > maxListSize)
        maxListSize = array[key].size();

    countOfElements++;
    loadFactor = countOfElements / arraySize;
    if (loadFactor >= 10)
        rebuild(arraySize * 2);
}

void HashTable::erase(valueType value)
{
    int key = hashFunc->calculateHashFunction(value, arraySize);

    if (array[key].find(value)){
        array[key].erase(value);

        countOfCollision[key]--;
        countOfElements--;
        loadFactor = countOfElements / arraySize;
    }
}

bool HashTable::find(valueType value)
{
    for (int i = 0; i < arraySize; i++)
        if (array[i].find(value))
            return 1;
    return 0;

}

void HashTable::showStatistic()
{
    int collisionSize = 0;
    int countOfClear = 0;
    for (int i = 0; i < arraySize; i++)
        if (countOfCollision[i] == -1) countOfClear++;
        else
            collisionSize += countOfCollision[i];

        std::cout << "Count of element = " << countOfElements << std::endl;
        std::cout << "Count of array = " << arraySize << std::endl;
        std::cout << "Count of clear element in array = " << countOfClear << std::endl;

        std::cout << "Max size of list in hash table = " << maxListSize << std::endl;
        std::cout << "Load factor = " << loadFactor << std::endl;
        std::cout << "Size of collision = " << collisionSize << std::endl;
    }
    void HashTable::show()
    {
        for (int i = 0; i < arraySize; i++)
            if (array[i].size() != 0)
                array[i].show();

    }


    void HashTable::rebuild(int size)
    {
        valueType temp[countOfElements];
        int ind = 0;

        for(int i = 0; i < arraySize; i++)
            for (int j = 0; j < array[i].size(); j++) {
                temp[ind++] = array[i].back();
                array[i].popBack();
            }

        for (int i = 0; i < arraySize; i++)
            array[i].clear();

        delete[] countOfCollision;
        int count = countOfElements;
        init(size);

        for (int i = 0; i < count; i++)
            add(temp[i]);
    }

    void HashTable::init(int size)
    {
        countOfElements = 0;
        countOfCollision = new int[size];
        for(int i = 0; i < size; i++)
            countOfCollision[i] = -1;
        array = new AciclicList[size];
        maxListSize = 0;
        loadFactor = 0;
        arraySize = size;
    }
