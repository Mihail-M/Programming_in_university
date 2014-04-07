#pragma once
#include "acicliclist.h"
#include "exception.h"

typedef char valueType;

class UniqueList : public AciclicList
{
public:
	class DuplicateValueException: public Exception {
	public:
		DuplicateValueException(char* msg);

	};
	class EmptyListException: public Exception {
	public:
		EmptyListException(char* msg);

	};

	UniqueList();
	~UniqueList();
	void pushBack(valueType x);
	void pushFront(valueType x);
	void add(int pos, valueType x);
	void erase(valueType x);
	void erase(int pos);

};

