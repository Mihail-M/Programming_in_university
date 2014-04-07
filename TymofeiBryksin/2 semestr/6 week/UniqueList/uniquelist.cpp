#include "uniquelist.h"

UniqueList::UniqueList(): AciclicList()
{
}

UniqueList::~UniqueList()
{
}

void UniqueList::pushBack(valueType x)
{
	if (find(x)) {
		throw DuplicateValueException("Prost");
		return;
	}
	AciclicList::pushBack(x);

}

void UniqueList::pushFront(valueType x)
{
	if (find(x)) {
//		throw DuplicateValueException("Prost");
		return;
	}
	AciclicList::pushFront(x);
}

void UniqueList::add(int pos, valueType x)
{
	if (find(x)) {
		throw DuplicateValueException("Prost");
		return;
	}
	AciclicList::add(pos, x);
}

void UniqueList::erase(valueType x)
{
	if (countOfElements == 0){
		throw EmptyListException("Sorry");
		return;
	}
	AciclicList::erase(x);
}


void UniqueList::erase(int pos)
{
	if (countOfElements == 0){
		throw EmptyListException("Sorry");
		return;
	}
	AciclicList::erase(pos);
}



UniqueList::DuplicateValueException::DuplicateValueException(char *msg): Exception(msg)
{
}


UniqueList::EmptyListException::EmptyListException(char *msg): Exception(msg)
{

}
