#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{

	Tree *tr = new BSTree;
	tr->insert(5);
	tr->insert(4);
	tr->insert(6);
	tr->insert(14);
	tr->insert(8);
	tr->insert(3);
	//cout << tr->successor(tr->find(6))->value;
	tr->remove(tr->root);
	//tr->remove(tr->root);
	tr->pre_order_traversal();



	return 0;
}

