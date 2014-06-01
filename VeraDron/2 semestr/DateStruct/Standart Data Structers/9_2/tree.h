#pragma once

class Tree {
public:

	struct Node {

		Node *left;
		Node *right;
        Node *parent;
        int value;
        int height;

        Node(int x, Node *_parent = nullptr) {
			left = nullptr;
			right = nullptr;
            height = 1;
            parent = _parent;
			value = x;
		}

	};
	Tree();
    virtual ~Tree(){};
	///insert node with value x into tree
	virtual void insert(int x) = 0;
	///insert node with value x from tree
    virtual void remove(Node *p) = 0;

	///
	/// \brief find
	/// \param x
	/// \return if exist return pointer on the node with value X
	/// else return NULL
	///
	Node* find(int x);
	///
	/// \brief minimum
	/// \param p
	/// \return if minimum exist return pointer on the node with min value
	///  if tree is empty return nullptr
	///
	Node* minimum(Node *p);
	///
	/// \brief maximum
	/// \param p
	/// \return  if maximum exist return pointer on the node with min value
	/// if tree is empty return nullptr
	///
	Node* maximum(Node *p);


    Node* predecessor(Node *node);
    Node* successor(Node *node);

    int getHeight(Node *node);
	void in_order_traversal();
	void pre_order_traversal();
	void post_order_traversal();

	void breadth_first_traversal();
	Node *root;

protected:


	Node *find(Node *p, int x);

	void in_order_traversal(Node *p);
	void pre_order_traversal(Node *p);
	void post_order_traversal(Node *p);
    Node *updateHeight(Node *node);

};
