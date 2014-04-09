#include "stringbbc.h"
#include <cstring>

StringBBC::StringBBC(): mySize(0), myCapacity(MinCapacity)
{
	str = new char[MinCapacity];
	str[0] = '\0';
}

StringBBC::StringBBC(StringBBC &a) : mySize(a.mySize)
  , myCapacity(a.myCapacity)
{
	str = new char[myCapacity];
	for(int i = 0; i < mySize; i++)
		str[i] = a.str[i];

}

StringBBC::StringBBC(char *str1): mySize(0), myCapacity(MinCapacity)
{
	int len = strlen(str1);
	myCapacity = getNewCapacity(len);

	str = new char[myCapacity];
	mySize = len;

	for (int i = 0; i < mySize; ++i)
	{
		str[i] = str1[i];
	}
	str[mySize] = '\0';
}

StringBBC::StringBBC(int size, int capacity): mySize(size), myCapacity(capacity)
{
	str = new char[myCapacity];
	for (int i = 0; i < mySize; i++)
		str[i] = '1';
	str[mySize] = '\0';
}

bool StringBBC::empty()
{
	return (mySize == 0);
}

void StringBBC::push_back(char c)
{
	if (myCapacity < mySize + 1) {
		myCapacity = getNewCapacity(1);
		char *newStr = new char[myCapacity];

		for (int i = 0; i < mySize; i++)
			newStr[i] = str[i];

		newStr[mySize] = '\0';

		delete[] str;
		str = newStr;
	}

	str[mySize++] = c;
	str[mySize] = '\0';

}
void StringBBC::insert(int pos, char* str1) {

	int len1 = mySize, len2 = strlen(str1);
	myCapacity = getNewCapacity(len1);

	char *res = new char[myCapacity];

	for (int i = 0; i < pos; ++i)
	{
		res[i] = str[i];
	}
	for (int i = 0; i < len2; ++i)
	{
		res[pos + i] = str1[i];
	}
	for (int i = pos + len2; i < len2 + len1; ++i)
	{
		res[i] = str[i - len2];
	}
	delete[] str;
	res[len1 + len2] = '\0';
	str = res;
	mySize += len2;
}

void StringBBC::erase(int pos, int count)
{
	if (count <= mySize - pos) {

		myCapacity = getNewCapacity(-count);
		char *res = new char[myCapacity];

		for (int i = 0; i < pos; ++i)
		{
			res[i] = str[i];
		}
		for (int i = pos + count; i < mySize; ++i)
		{
			res[i - count] = str[i];
		}
		mySize  -= count;
		res[mySize] = '\0';
		delete[] str;
		str = res;
	}
}

StringBBC &StringBBC::operator +=(StringBBC& b)
{
	insert(mySize, b.str);
	return *this;

}

StringBBC &StringBBC::operator =(StringBBC &str2)
{
	if (this == &str2) return *this;
	clear();
	insert(0, str2.str);

	return *this;
}

char &StringBBC::operator [](int i)
{
	if (i > 0 && i < mySize)
		return str[i];

}


void StringBBC::pop_back()
{
	if (myCapacity >= 2*mySize) {

		myCapacity = getNewCapacity(-1);
		char *newStr = new char[myCapacity];

		for (int i = 0; i < mySize; i++)
			newStr[i] = str[i];
		newStr[mySize] = '\0';

		delete[] str;
		str = newStr;
	}
	mySize--;
	str[mySize] = '\0';
}

int StringBBC::size()
{
	return mySize;
}

int StringBBC::capacity()
{
	return myCapacity;
}

void StringBBC::clear()
{
	delete[] str;
	mySize = 0;
	str = new char[MinCapacity];
	str[0] = '\0';
	myCapacity = MinCapacity;
}


StringBBC &operator +(StringBBC& a, StringBBC& b)
{
	StringBBC c(a);
	c.insert(c.mySize, b.str);
	return c;
}

ostream &operator<<(ostream &stream, const StringBBC &s) {
	int n = s.mySize;
	for (int i = 0; i < n; i++)
	{
		stream << s.str[i];
	}
	return stream;
}

istream &operator>>(istream &stream, StringBBC &s) {
	char str[101];
	stream >> str;
	s.insert(0, str);
	return stream;
}
int StringBBC::getNewCapacity(int n)
{
	int newCapacity = myCapacity;
	if (myCapacity <= mySize + n + 1)
	{
		while (newCapacity - 1 < mySize + n)
			newCapacity *= 2;
	}
	else if (myCapacity >= 2*(mySize + n + 1))
	{
		while (newCapacity >= max(mySize -1 , MinCapacity))
			newCapacity /= 2;
	}
	return max(newCapacity, MinCapacity);
}
