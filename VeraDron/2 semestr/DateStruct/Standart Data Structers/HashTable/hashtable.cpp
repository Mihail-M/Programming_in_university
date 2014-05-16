#include "hashtable.h"
#include  <iostream>
#include  <cstring>
#include  <list>
#include  <algorithm>
using namespace std;

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
    delete hashFunc;

}

void HashTable::add(valueType value)
{
    int key = hashFunc->calculateHashFunction(value, arraySize);
    if (find(array[key], value)) {
        for(list< pair< valueType, int> >::iterator it = array[key].begin(); it != array[key].end(); it++)
            if((*it).first == value)
                (*it).second++;

        return;
    }

    array[key].push_back(make_pair(value, 1));
    countOfCollision[key]++;

    if (array[key].size() > maxListSize)
        maxListSize = array[key].size();

    countOfElements++;
    loadFactor = countOfElements / arraySize;
}

void HashTable::erase(valueType value)
{
    int key = hashFunc->calculateHashFunction(value, arraySize);

    erase(array[key], value);

    countOfCollision[key]--;
    countOfElements--;
    loadFactor = countOfElements / arraySize;

}

bool HashTable::exist(valueType value)
{
    for (int i = 0; i < arraySize; i++)
        if (find(array[i], value))
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

    cout << "Count of element = " << countOfElements << endl;
    cout << "Count of array = " << arraySize << endl;
    cout << "Count of clear element in array = " << countOfClear << endl;

    cout << "Max size of list in hash table = " << maxListSize << endl;
    cout << "Load factor = " << loadFactor << endl;
    cout << "Size of collision = " << collisionSize << endl;
}
void HashTable::show()
{
    for (int i = 0; i < arraySize; i++)
        if (array[i].size() != 0)
            for(list<pair<valueType, int> >::iterator it = array[i].begin(); it != array[i].end(); it++)
                cout << (*it).first << " " << (*it).second << endl;
}



void HashTable::setHashFunction(HashFunction *value)
{
    delete hashFunc;
    hashFunc = value;
}


void HashTable::init(int size)
{
    countOfElements = 0;
    countOfCollision = new int[size];
    array = new list<pair<valueType, int> >[size];
    for(int i = 0; i < size; i++){
        countOfCollision[i] = -1;
    }
    maxListSize = 0;
    loadFactor = 0;
    arraySize = size;
}

bool HashTable::find(std::list<std::pair<valueType, int> > &lst, valueType s)
{
    for(list< pair< valueType, int> >::iterator it = lst.begin(); it != lst.end(); it++)
        if((*it).first == s)
            return 1;
    return 0;
}

void HashTable::erase(std::list<std::pair<valueType, int> > &lst, valueType s)
{
    if (find(lst, s))
        for(list < pair <valueType, int> >::iterator it = lst.begin(); it != lst.end(); it++)
            if((*it).first == s){
                lst.erase(it);
                return;
            }
}
