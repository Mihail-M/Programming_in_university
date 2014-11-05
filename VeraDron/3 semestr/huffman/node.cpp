#include "node.h"


void delTree(node *t) {
    if(t->left != nullptr) {
        delTree(t->left);
    }
    if(t->right != nullptr) {
        delTree(t->right);
    }
    if (t != nullptr)
        delete t;

}

node* merge(node *a, node *b) {
    node *newRoot = new node(a, b);
    return newRoot;
}
