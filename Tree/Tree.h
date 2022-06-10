#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

typedef struct node {
    int value;
    struct node *right, *left;
} node;

node *insert(node* , int);
node *search(node* , int);
void inOrder(node* );
void postOrder(node* );
void preOreder(node* );
node *findMin(node* );
node *findMax(node* );
node *inorderSuccessor(node*, int);
node *inorderPredecessor(node*, int);
void *deleteNode(node*, int);
void destructTree(node* );

#endif // TREE_H_INCLUDED