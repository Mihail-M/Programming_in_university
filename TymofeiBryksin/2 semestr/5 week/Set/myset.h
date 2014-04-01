#pragma once
#include "tree.h"

template <class T>
class MySet
{
public:
    MySet();
    ~MySet();
    ///intersection this set with another set
    MySet * intersection(MySet *&set2);
    ///merge this set with another set
    MySet* merge(MySet *&set2);
    /// add in set
    void add(T value) {
        tree->add(value);
    }
    ///
    /// \brief exist
    /// \param value
    /// \return 1 if exist
    /// \return 0 if not exist
    ///
    bool exist(T value) {
        return tree->exist(value);
    }
    /// remove
    void remove(T value){
        tree->remove(value);
    }

    int size() {
        return tree->size();
    }

private:

    void intersection(typename Tree<T>::TreeNode *&node, MySet *&set2, MySet *&result);
    void merge(typename Tree<T>::TreeNode *&node, MySet *&result);

    Tree <T> *tree;

};

template <class T>
MySet<T>::MySet()
{
    tree = new Tree<T>;
}

template <class T>
MySet<T>::~MySet()
{
    delete tree;
}

template <class T>
MySet<T> *MySet<T>::intersection(MySet<T> *&set2)
{
    MySet<T>* result = new MySet<T>();
    intersection(this->tree->root, set2, result);
    return result;
}

template <class T>
void MySet<T>::intersection(typename Tree<T>::TreeNode *&node,
                            MySet<T> *&set2,
                            MySet<T> *&result)
{
    if (node != nullptr){
        if (set2->exist(node->value))
            result->add(node->value);
        intersection(node->left, set2, result);
        intersection(node->right, set2, result);
    }
}

template <class T>
MySet<T> *MySet<T>::merge(MySet<T> *&set2)
{
    MySet *result = new MySet<T>();
    merge(this->tree->root, result);
    merge(set2->tree->root, result);

    return result;
}

template <class T>
void MySet<T>::merge(typename Tree<T>::TreeNode *&node, MySet<T> *&result)
{
    if (node == nullptr)
        return;

    result->add(node->value);
    merge(node->left, result);
    merge(node->right, result);

}




