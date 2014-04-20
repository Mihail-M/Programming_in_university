#include "tree.h"
#include <iostream>
#include <queue>



Tree::Tree(): root(nullptr)
{

}


int Tree::get_height(Tree::Node *p)
{
	int left = 0;
	int right = 0;

	if (p == nullptr)
		return 0;

	if (p->left != nullptr)
		left = get_height(p->left);
	if (p->right != nullptr)
		right = get_height(p->right);

	int height = std::max(left, right);

	return height + 1;
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

Tree::Node *Tree::predecessor(const Tree::Node *p)
{
	return predecessor(p, root);
}

Tree::Node *Tree::successor(const Tree::Node *p)
{
	return successor(p, root);

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
}

Tree::Node *Tree::predecessor(const Tree::Node *p, Node *current)
{
	if (current == nullptr || p == nullptr)
		return nullptr;
	static Node *max = new Node(-1000);

	if (current->value < p->value) {

		if (max->value < current->value)
			max = current;

		predecessor(p, current->right);
	}
	if (current->value >= p->value) {
		predecessor(p, current->left);
	}
	return max;

}

Tree::Node *Tree::successor(const Tree::Node *p, Tree::Node *current)
{
	if (current == nullptr || p == nullptr)
		return nullptr;
	static Node *min = new Node(1e10);

	if (current->value > p->value) {

		if (min->value > current->value)
			min = current;

		successor(p, current->left);
	}
	if (current->value <= p->value) {
		successor(p, current->right);
	}
	return min;

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
