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
	}
	AciclicList::pushBack(x);

}

void UniqueList::pushFront(valueType x)
{
	if (find(x)) {
		throw DuplicateValueException("Prost");
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
	}
	AciclicList::erase(x);
}


void UniqueList::erase(int pos)
{
	if (countOfElements == 0){
		throw EmptyListException("Sorry");
	}
	AciclicList::erase(pos);
}

void UniqueList::popBack()
{
	if (countOfElements == 0){
		throw EmptyListException("Sorry");
	}
	AciclicList::popBack();

}

void UniqueList::popFront()
{
	if (countOfElements == 0){
		throw EmptyListException("Sorry");
	}
	AciclicList::popFront();

}



UniqueList::DuplicateValueException::DuplicateValueException(char *msg): Exception(msg)
{
}


UniqueList::EmptyListException::EmptyListException(char *msg): Exception(msg)
{

}
