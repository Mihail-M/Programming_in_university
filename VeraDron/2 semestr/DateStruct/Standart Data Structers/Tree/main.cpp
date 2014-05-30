#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{

	Tree *tr = new BSTree;
    for (int i = 1; i <= 100; i++)
        tr->insert(i);
    for(int i = 1; i < 100; i+=2)
        cout << tr->successor(tr->find(i))->value << " ";

    cout << endl;
    for(int i = 2; i <= 100; i+=2)
        cout << tr->predecessor(tr->find(i))->value << " ";


    for(int i = 3; i < 100; i+=3) {
        tr->remove(tr->find(i));
    }

	tr->pre_order_traversal();
    tr->breadth_first_traversal();
    tr->in_order_traversal();
    tr->post_order_traversal();


    delete tr;
	return 0;
}

