#include "acicliclist.h"
#include <iostream>
AciclicList::AciclicList(): List()
{
}

AciclicList::~AciclicList()
{
	clear();
}



void AciclicList::pushBack(valueType x)
{
	ListElement *newElem = new ListElement;
	newElem->key = x;
	if (isEmpty()) {
		pushInit(newElem);
	}
	else {
		newElem->prev = last;
		newElem->next = nullptr;
		last->next = newElem;
		last = newElem;
	}
	countOfElements++;
}

void AciclicList::pushFront(valueType x)
{
	ListElement *newElem = new ListElement;
	newElem->key = x;

	if (isEmpty()) {
		pushInit(newElem);

	}
	else {
		newElem->next = head;
		newElem->prev = nullptr;
		head->prev = newElem;
		head = newElem;
	}
	countOfElements++;
}


void AciclicList::popFront()
{
	if(!isEmpty()) {
		ListElement *temp = head;
		if(countOfElements == 1){
			last = nullptr;
			head = nullptr;
		}
		else
		{
			head = head->next;
			head->prev = nullptr;
		}
		delete temp;
		countOfElements--;

	}
}

void AciclicList::popBack()
{
	if(!isEmpty()) {
		ListElement *temp = last;
		if(countOfElements == 1){
			last = nullptr;
			head = nullptr;
		}
		else
		{
			last = last->prev;
			last->next = nullptr;

		}
		delete temp;
		countOfElements--;
	}
}

void AciclicList::reverse()
{
	if(isEmpty()) return;

	pushFront(back());
	popBack();

	for(int i = 0; i < countOfElements; i++)
	{
		add(i, back());
		popBack();
	}
}

void AciclicList::erase(int pos)
{
	if(isEmpty()) return;
	if (pos == 0) popFront();
	else
		if (pos >= countOfElements - 1)
			popBack();
		else
		{
			ListElement *temp = getNListElem(pos);
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			delete temp;
			countOfElements--;
		}
}

void AciclicList::erase(valueType x)
{
	int pos = getIndListElemWithKey(x);
	if(pos != -1)
		erase(pos);
}

void AciclicList::add(int pos, valueType x)
{
	if(pos >= countOfElements - 1 || isEmpty()){
		pushBack(x);
		return;
	}

	ListElement *newElem = new ListElement;
	newElem->key = x;
	ListElement *current = getNListElem(pos);
	newElem->next = current->next;
	current->next->prev = newElem;
	newElem->prev = current;
	current->next = newElem;

	countOfElements++;
}


void AciclicList::pushInit(List::ListElement *newElem)
{
	head = newElem;
	last = newElem;
	head->next = nullptr;
	head->prev = nullptr;
	last->next = nullptr;
	last->next = nullptr;

}

List::ListElement *AciclicList::getNListElem(int pos)
{
	ListElement *temp = head;
	for(int i = 0; i < pos  && i < countOfElements - 1; i++)
	{
		temp = temp->next;
	}

	return temp;
}
