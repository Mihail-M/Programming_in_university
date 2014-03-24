#pragma once
#include "tree.h"

template <class T>
class MySet: public Tree<T>
{
public:
   // MySet();
    ///intersection this set with another set
    static MySet* intersection(MySet *&set1, MySet *&set2);
    ///merge this set with another set
    static MySet* merge(MySet *&set1, MySet *&set2);

private:



    void intersection(Tree<T>::TreeNode node,MySet *&set2, MySet *&result); // хочу чтобы можно было treenode использовать
    void merge(TreeNode node,MySet *&set2, MySet *&result);

};

template <class T>
MySet<T> *MySet<T>::intersection(MySet<T> *&set1, MySet<T> *&set2)
{
    MySet<T>* result = new MySet<T>();
   // intersection(set1root, set2, result);
    return result;
}

template <class T>
void MySet<T>::intersection(TreeNode<T>::TreeNode, MySet<T> *&set2, MySet<T> *&result)
{
    if(node!= nullptr){
        if (exist(node->value))
            result->add(node->value);
        intersection(node->left, set2, result);
        intersection(node->right, set2, result);
    }
}

MySet<T> *MySet<T>::merge(MySet<T> *&set1, MySet<T> *&set2)
{
    MySet<T>* result = new MySet<T>();
    merge(root, set2, result);
    return result;
}

void MySet<T>::merge(TreeNode<T>::TreeNode node, MySet<T> *&set2, MySet<T> *&result)
{
    if (node != NULL)
    {
        mergerTree->add(node->value);
        merger(node->left, mergerTree);
        merger(node->right, mergerTree);
    }

}




