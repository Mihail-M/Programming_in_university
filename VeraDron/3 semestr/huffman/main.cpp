#include <iostream>
#include <map>
#include <queue>
#include <cmath>

#include "node.h"

using namespace std;
string bincode = "";
double huffmanCoeff = 0;

void order(node *p)
{
    if (p == nullptr)
        return;
    if (p->left != nullptr)
        bincode += "0";
    order(p->left);

    if (p->right != nullptr)
        bincode += "1";
    order(p->right);

    if (p->right == nullptr && p->left == nullptr)
    {
        if (p->value != ' ')
            cout <<  p->value << ": " << bincode << endl;
        else
            cout << "space: " << bincode << endl;
        huffmanCoeff += bincode.size() * p->count;
    }

    if (bincode.size() != 0)
        bincode.erase(bincode.size() - 1);
}

struct LessThanByCount
{
    bool operator()(const node* a, const node* b) const
    {
        return a->count > b->count;
    }
};



int main()
{
    map <char, int> count;
    string pattern;
    getline(cin ,pattern);

    for(int i = 0; i < pattern.size(); i++)
        count[pattern[i]]++;

    priority_queue <pair<char, int> > allsym;

    for(map<char, int>::iterator it = count.begin(); it != count.end(); it++) {
        allsym.push(make_pair((*it).first, (*it).second));
    }

    double patternCoeff = (ceil(log2(allsym.size())));

    int size = allsym.size();

    priority_queue <node*,vector<node*>, LessThanByCount> huffmanTree;
    for (int i = 0; i < size ; i++) {

        pair <char, int> temp = allsym.top();
        node* t = new node(temp.first, temp.second);
        huffmanTree.push(t);
        allsym.pop();
    }

    while (huffmanTree.size() != 1) {
        node *a = huffmanTree.top();
        huffmanTree.pop();
        node *b = huffmanTree.top();
        huffmanTree.pop();

        huffmanTree.push(merge(a, b));
    }


    order(huffmanTree.top());
    cout << "compression coeff: " << pattern.size()*patternCoeff/huffmanCoeff<< endl;
    delTree(huffmanTree.top());
    huffmanTree.pop();

    return 0;
}

