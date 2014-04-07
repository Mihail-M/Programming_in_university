#pragma once
typedef char valueType;

/// \brief The List class
///first index - 0
class List
{

public:
	List();
	virtual ~List();

	///add x at tail of list
	virtual void pushBack(valueType x) = 0;

	///add x at head of list
	virtual void pushFront(valueType x) = 0;

	///delete first element in list
	virtual void popFront() = 0;

	///delete last element in list
	virtual void popBack() = 0;
	///reverse list
	virtual void reverse() = 0;
	/// delete element with index pos or last(if pos > count of element
	virtual void erase(int pos) = 0;
	/// delete element with key = x
	virtual void erase(valueType x) = 0;
	/// inserts the element after the element with index pos
	virtual void add(int pos, valueType x) = 0;

	/// \brief find
	/// \return true if value exist, false if x not exist
	bool find(valueType x);

	///return value of last element
	valueType &back();

	///return value of head element
	valueType &front();

	///clear list
	void clear();
	///
	/// \brief isEmpty
	/// \return true if list
	///
	bool isEmpty();
	/// show list
	void show();
	///
	/// \brief size
	/// \return count of element
	int size() const;

protected:
	struct ListElement {
		valueType key;
		ListElement *next;
		ListElement *prev;
	};

	ListElement *head;
	ListElement *last;
	int countOfElements;
	///
	/// \brief getNListElem
	/// \param pos
	/// \return pos's element of

	virtual ListElement *getNListElem(int pos) = 0;
	///return index element with key = x
	int getIndListElemWithKey(valueType x);
};

