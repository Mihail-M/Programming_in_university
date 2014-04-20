#include "bstree.h"

Tree::Node *BSTree::getLeftMostNode(Tree::Node *&node) {
	while (node->left != nullptr)
		node = node->left;
	return node;
}

BSTree::BSTree(): Tree(), countOfElements(0)
{
}

BSTree::~BSTree()
{
	clear();
}

void BSTree::insert(int x)
{
	countOfElements++;
	insert(x, root);
}

void BSTree::remove(Tree::Node *&node)
{
	if (node->left == nullptr && node->right == nullptr){
		delete node;
		node = nullptr;
		return;
	}
	else if (node->left != nullptr && node->right ==nullptr) {
		Node *temp = node->left;
		delete node;
		node = temp;
	}
	else if (node->right != nullptr && node->left == nullptr) {
		Node *temp = node->right;
		delete node;
		node = temp;
	}
	else {
		Node *temp = getLeftMostNode(node->right);
		node->value = temp->value;
		node->right = temp->right;

		if (temp->left == nullptr && temp->right == nullptr)
		{
			delete temp;
			temp = nullptr;
			return;
		}
		else
		{
			Node *temp2 = temp->right;
			delete temp;
			temp = temp2;
		}
	}
	countOfElements--;
}

void BSTree::clear()
{
	deleteTree(root);
}

void BSTree::insert(int value, Tree::Node *&node)
{
	if (node == nullptr) {
		node = new Node(value);
		return;
	}
	if (value < node->value) {
		insert(value, node->left);
	}
	else if (value > node->value)
		insert(value, node->right);
	else
		countOfElements--;
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
