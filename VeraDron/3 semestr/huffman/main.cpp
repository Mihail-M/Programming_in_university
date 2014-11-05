#include <iostream>
#include <map>
#include <queue>
#include <cmath>

using namespace std;
string ss = "";
map <char, int> count;
struct node {
    node *left;
    node *right;
    int count;
    char value;
    node(char v, int c) {
        left = nullptr;
        right = nullptr;
        count = c;
        value = v;
    }
    node(node *a, node *b){
        left = a;
        right = b;
        count = a->count + b->count;
        value = '0';
    }
};
void delTree(node *t) {
    if(t->left != nullptr) {
        delTree(t->left);
    }
    if(t->right != nullptr) {
        delTree(t->right);
    }
    if (t != nullptr)
        delete t;

}

node* merge(node *a, node *b) {
    node *newRoot = new node(a, b);
    return newRoot;
}

double huffmanCoeff = 0;
void order(node *p)
{
    if (p == nullptr)
        return;
    if (p->left != nullptr)
        ss += "0";
    order(p->left);

    if (p->right == nullptr && p->left == nullptr)
    {
        if (p->value != ' ')
            cout <<  p->value << ": " << ss << endl;
        else
            cout << "space: " << ss << endl;
        huffmanCoeff += ss.size() * p->count;
    }

    if (p->right != nullptr)
        ss += "1";
    order(p->right);

    if (ss.size() != 0)
        ss.erase(ss.size() - 1);
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

