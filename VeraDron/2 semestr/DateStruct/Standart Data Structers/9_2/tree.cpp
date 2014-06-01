#include "tree.h"
#include <iostream>
#include <queue>

using namespace std;

Tree::Tree(): root(nullptr)
{

}


Tree::Node *Tree::find(int x)
{
	return find(root, x);
}

Tree::Node *Tree::minimum(Tree::Node *p)
{
	if (p == nullptr)
		return nullptr;

	while (p->left != nullptr)
		p = p->left;

	return p;
}

Tree::Node *Tree::maximum(Tree::Node *p)
{
	if (p == nullptr)
		return nullptr;

	while (p->right != nullptr)
		p = p->right;

	return p;
}

Tree::Node *Tree::predecessor(Node *node)
{
    if (!node)
        return NULL;
    if (node->left)
        return maximum(node->left);
    else
    {
        Node *parent = node;
        while (parent && parent->value >= node->value)
            parent = parent->parent;
        return parent;
    }
}

Tree::Node *Tree::successor(Tree::Node *node)
{
    if (node == nullptr)
        return nullptr;
    if (node->right != nullptr)
        return minimum(node->right);
    else
    {
        Node *parent = node;
        while (parent && parent->value <= node->value)
            parent = parent->parent;
        return parent;
    }
}

int Tree::getHeight(Tree::Node *node)
{
    if (node != nullptr) {
        return node->height;
    }
    else return -1;
}

void Tree::in_order_traversal()
{
	in_order_traversal(root);
	std::cout << std::endl;
}

void Tree::pre_order_traversal()
{
	pre_order_traversal(root);
	std::cout << std::endl;
}

void Tree::post_order_traversal()
{
	post_order_traversal(root);
	std::cout << std::endl;
}

void Tree::breadth_first_traversal()
{
	if (root == nullptr)
		return;
	std::queue <Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node *to = q.front();
		q.pop();
		std::cout << to->value << " ";
		if (to->left != nullptr)
			q.push(to->left);
		if (to->right != nullptr)
			q.push(to->right);
	}
    cout << endl;
}

Tree::Node *Tree::find(Tree::Node *p, int x)
{
	if (p == nullptr)
		return nullptr;

	if (p->value == x)
		return p;

	if (p->value > x)
		find(p->left, x);
	else
        find(p->right, x);
}


void Tree::in_order_traversal(Tree::Node *p)
{
	if (p == nullptr)
		return;

	in_order_traversal(p->left);
	std::cout << p->value << " ";
	in_order_traversal(p->right);
}

void Tree::pre_order_traversal(Tree::Node *p)
{
	if (p == nullptr)
		return;
	std::cout << p->value << " ";
	pre_order_traversal(p->left);
	pre_order_traversal(p->right);
}

void Tree::post_order_traversal(Tree::Node *p)
{
	if (p == nullptr)
		return;
	pre_order_traversal(p->left);
	pre_order_traversal(p->right);
	std::cout << p->value << " ";
}

Tree::Node *Tree::updateHeight(Tree::Node *node)
{
    if (node)
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    return node;
}
