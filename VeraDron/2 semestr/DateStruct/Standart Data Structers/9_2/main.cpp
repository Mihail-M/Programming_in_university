#include <iostream>
#include "bstree.h"
#include "avltree.h"
using namespace std;

int main()
{
    Tree *tr;
    int choiseTree = 0;

    cin >> choiseTree;
    if (choiseTree == 0)
        tr = new BSTree;
    else tr = new AVLTree;

    string command = "";
    while (cin >> command) {
        int t;
        if (command == "i")
        {
            cin >> t;
            tr->insert(t);
        }
        if (command == "d")
        {
            cin >> t;
            tr->remove(tr->find(t));
        }
        if (command == "ino")
        {
            tr->in_order_traversal();
        }
        if (command == "preo")
        {
            tr->pre_order_traversal();
        }
        if (command == "posto")
        {
            tr->post_order_traversal();
        }
        if (command == "h")
        {
            cout << tr->getHeight(tr->root) ;
        }
        if (command == "bfs")
        {
            tr->breadth_first_traversal();
        }
    }

    delete tr;

    return 0;
}
