#include "avltree.h"

AVLTree::AVLTree()
{
}

AVLTree::~AVLTree()
{
    clear();
}

void AVLTree::insert(int x)
{
    root = insert(root, x);
}


void AVLTree::remove(Tree::Node *x)
{
    root = remove1(root, x->value);

}

int AVLTree::balance_factor(const AVLTree::Node* p)
{
    return getHeight(p->right)-getHeight(p->left);
}

AVLTree::Node* AVLTree::rotate_right(Node* p) // правый поворот вокруг p
{
    Node* q = p->left;
    p->left = q->right;
    q->right = p;
    updateHeight(p);
    updateHeight(q);
    return q;
}

AVLTree::Node* AVLTree::rotate_left(AVLTree::Node* q) // левый поворот вокруг q
{
    AVLTree::Node* p = q->right;
    q->right = p->left;
    p->left = q;
    updateHeight(q);
    updateHeight(p);
    return p;
}

AVLTree::Node* AVLTree::balance(AVLTree::Node* p) // балансировка узла p
{
    updateHeight(p);
    if (balance_factor(p) == 2 )
    {
        if (balance_factor(p->right) < 0 )
            p->right = rotate_right(p->right);
        return rotate_left(p);
    }

    if( balance_factor(p)==-2 )
    {
        if( balance_factor(p->left) > 0  )
            p->left = rotate_left(p->left);
        return rotate_right(p);
    }

    return p;
}

AVLTree::Node* AVLTree::insert(AVLTree::Node* p, int x)
{
    if (p == nullptr)
        return new AVLTree::Node(x);

    if (x < p->value)
        p->left = insert(p->left,x);
    else
        p->right = insert(p->right,x);

    return balance(p);
}

AVLTree::Node* AVLTree::removemin(AVLTree::Node* p) {
    if( p->left==0 )
        return p->right;

    p->left = minimum(p->left);
    return balance(p);
}

AVLTree::Node* AVLTree::remove1(AVLTree::Node* p, int x)
{
    if (p == nullptr)
        return 0;
    if( x < p->value )
        p->left = remove1(p->left, x);
    else
        if( x > p->value )
            p->right = remove1(p->right, x);
        else
        {
            AVLTree::Node* q = p->left;
            AVLTree::Node* r = p->right;
            delete p;
            if (r == nullptr)
                return q;

            AVLTree::Node* min = minimum(r);
            min->right = removemin(r);
            min->left = q;

            return balance(min);
        }

    return balance(p);
}



void AVLTree::clear()
{
    deleteTree(root);
}

void AVLTree::deleteTree(Node *temp)
{
    Node *node = temp;
    if (node != nullptr)
    {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}
