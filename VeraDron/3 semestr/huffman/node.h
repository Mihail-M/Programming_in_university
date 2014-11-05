#ifndef NODE_H
#define NODE_H

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
void delTree(node *t);
node* merge(node *a, node *b);



#endif // NODE_H
