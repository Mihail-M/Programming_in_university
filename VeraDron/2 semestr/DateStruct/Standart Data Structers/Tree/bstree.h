#pragma once
#include "tree.h"

class BSTree : public Tree
{
public:
	BSTree();
	~BSTree();
	void insert(int x);
	void remove(Node *&p);
	void clear();
private:
	int countOfElements;
	void insert(int x, Node *&node);
	void deleteTree(Node *temp);

	Node *getLeftMostNode(Node *&node);

};

