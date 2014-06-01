#include <iostream>
#include "bstree.h"

using namespace std;

int main()
{

    BSTree *tr = new BSTree;
    for (int i = 0; i < 19; i++)
    {
        int temp = rand() % 100 + 1;
        tr->insert(temp);
    }

    tr->breadth_first_traversal();
    tr->in_order_traversal();
    tr->post_order_traversal();
    tr->pre_order_traversal();

    cout << endl;

    Tree::Node *current = tr->minimum(tr->root);
    for (;;)
    {
        current= tr->successor(current);
        if (current == nullptr)
            break;
        else
            if (current->value % 2 == 0)
                cout << current->value << " ";
    }

    cout << endl;
    cout << endl;
    current= tr->maximum(tr->root);
    for (;;)
    {
        current = tr->predecessor(current);
        if (current == nullptr)
            break;
        else
            if (current->value % 2 != 0)
                cout << current->value << " ";
    }

    cout << endl;
    current = tr->minimum(tr->root);

    Tree::Node *current2 = tr->successor(current);

    for (;;)
    {
        if (current == nullptr)
            break;
        if (current->value % 3 == 0)
        {
            tr->remove(current2);

            if (current2 == nullptr)
                break;

            current = current2;
            current2 = tr->successor(current);
        }
        else
        {
            if (current2 == nullptr)
                break;
            current = current2;
            current2 = tr->successor(current);

        }
    }

    cout << endl;
    tr->breadth_first_traversal();
    delete tr;
    return 0;
}
