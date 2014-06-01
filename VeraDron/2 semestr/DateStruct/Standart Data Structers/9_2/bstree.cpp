#include "bstree.h"
#include <iostream>


BSTree::BSTree(): Tree(), countOfElements(0)
{
}

BSTree::~BSTree()
{
    clear();
}
void BSTree::insert(int x)
{
    Node *parent = nullptr, *current = root;

    while (current != nullptr)
    {
        parent = current;
        if (x < current->value)
            current = current->left;
        else
            current = current->right;
    }

    Node *newNode = new Node(x, parent);

    if (parent)
    {
        if (x < parent->value)
            parent->left = newNode;
        else
            parent->right = newNode;
    }
    else{
        root = newNode;
        newNode->height = 1;
    }

    for (Node *it = newNode; it != nullptr; it = it->parent){
        it = updateHeight(it);
    }
    countOfElements++;

}

void BSTree::remove(Tree::Node *node)
{

    if (!node)
        return;

    Node *current = nullptr;
    Node *child = nullptr;

    if (node->right != nullptr)
        current = minimum(node->right);
    else current = node;

    if (current->left != nullptr)
        child = current->left;
    else
        child = current->right;

    if (current == root) {
        delete current;
        root = nullptr;
        return;
    }

    if (child != nullptr)
    {
        if (current->parent == nullptr)
            root = child;
        child->parent = current->parent;
    }

    if (current->parent != nullptr)
    {
        if (current->parent->left == current)
            current->parent->left = child;
        else
            current->parent->right = child;
    }

    node->value = current->value;



    current->left = nullptr;
    current->right = nullptr;

    for (Node *it = current; it != nullptr; it = it->parent){
        it = updateHeight(it);
    }
    delete current;
    countOfElements--;

}

void BSTree::clear()
{
    deleteTree(root);
}

void BSTree::deleteTree(Node *temp)
{
    Node *node = temp;
    if (node != nullptr)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
