#pragma once

template <class T>
class Tree {
public:
    Tree():root(nullptr), countOfElements(0)
    {};
    /// add node with key value
    void add(T value);

    /// \brief exist
    /// \param value
    /// \return 0 if value exist
    /// \return 1 if value not exist
    bool exist(T value);
    /// delete node with key value
    void remove(T value);
    ///return size
    int size();

protected:
    struct TreeNode{
        TreeNode *left;
        TreeNode *right;
        T value;

        TreeNode (T val) {
            left = nullptr;
            right = nullptr;
            value = val;
        }
    };
    TreeNode* root;
    int countOfElements;

    void add(T value, TreeNode *&node);
    bool exist(T value, TreeNode *&node);
    void remove(T value, TreeNode *&node);
    TreeNode *getLeftMostNode(TreeNode *&node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

};
template <class T>
int Tree<T>::size() {
    return countOfElements;
}

template <class T>
void Tree<T>::add(T value) {
    add(value, root);
    countOfElements++;
}

template <class T>
bool Tree<T>::exist(T value) {
    return exist(value, root);
}

template <class T>
void Tree<T>::remove(T value) {
    if(exist(value)) {
        remove(value, root);
        countOfElements--;
    }
}

template <class T>
void Tree<T>::add(T value, TreeNode *&node) {
    if (node == nullptr) {
        node = new TreeNode(value);
        return;
    }
    if (value < node->value) {
        add(value, node->left);
    }
    else if (value > node->value)
        add(value, node->right);
    else
        countOfElements--;
}

template <class T>
void Tree<T>::remove(T value, TreeNode *&node){

    if (value < node->value)
    {
        remove(value, node->left);
    }
    else if (value > node->value)
    {
        remove(value, node->right);
    }
    else if (node->left == nullptr && node->right == nullptr){
        delete node;
        node = nullptr;
        return;
    }
    else if (node->left != nullptr) {
        TreeNode *temp = node->left;
        delete node;
        node = temp;
    }
    else if (node->right != nullptr) {
        TreeNode *temp = node->right;
        delete node;
        node = temp;
    }
    else {
        TreeNode *temp = getLeftMostNode(node->right);
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
            TreeNode *temp2 = temp->right;
            delete temp;
            temp = temp2;
        }
    }
}

template <class T>
bool Tree<T>::exist(T value, TreeNode *&node) {
    if (node == nullptr)
        return false;
    if (node->value == value)
        return true;
    if (value < node->value)
        return exist(value, node->left);
    else
        return exist(value, node->right);

}

