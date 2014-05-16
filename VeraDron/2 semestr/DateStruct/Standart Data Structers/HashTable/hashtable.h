#pragma once
#include "hashfunction.h"
#include <list>

#define valueType std::string

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
    /// exist
	/// \return false - element exist, true - element - not exist

    bool exist(valueType value);
	///
	/// \brief @function showStatistic
	/// show count of elements, load factor, count of conflicts, max count of list in conflict elements, etc
	void showStatistic();
	void show();

	void setHashFunction(HashFunction *value);

private:
	///count element in hash table
	int countOfElements;
	int arraySize;
    std::list < std::pair<valueType, int> > *array;
    void add(valueType value, int count);

	int *countOfCollision;
	int maxListSize;
	double loadFactor;
	void init(int size);
    bool find(std::list<std::pair<valueType, int> > &lst, valueType s);
    void erase(std::list<std::pair<valueType, int> > &lst, valueType s);

	HashFunction *hashFunc;



};

