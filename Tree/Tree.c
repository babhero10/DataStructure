#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

node *newNode(int value)
{
    node *n = (node *) malloc(sizeof(node));
    n->value = value;
    n->right = n->left = NULL;
    return n;
}

node *insert(node *root, int value)
{
    if (root == NULL) return newNode(value);
    else if (value < root->value) root->left = insert(root->left, value);
    else if (value > root->value) root->right = insert(root->right, value);
    return root;
}

node *search(node *root, int value)
{
    if (root == NULL) return NULL;
    else if (root->value == value) return root;
    else if (value < root->value) return search(root->left, value);
    else if (value > root->value) return search(root->right, value);
}

void inOrder(node *root)
{
    if (root == NULL) return;
    inOrder(root->left);
    printf(" %d ", root->value);
    inOrder(root->right);
}

void postOrder(node *root)
{
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->value);
}

void preOreder(node *root)
{
    if (root == NULL) return;
    printf(" %d ", root->value);
    preOreder(root->left);
    preOreder(root->right);
}

node *findMin(node *root)
{
    if (root == NULL)
    {
        return NULL;
    } 
    else if (root->left != NULL)
    {
        return findMin(root->left);
    }
    else
    {
        return root; 
    }
}

node *findMax(node *root)
{
    if (root == NULL)
    {
        return NULL;
    } 
    else if (root->right != NULL)
    {
        return findMax(root->right);
    }
    else
    {
        return root; 
    }
}

node *inorderSuccessor(node *root, int value)
{
    node *successor = NULL;
    node *n = root;
    while (n->value != value)
    {
        if (n == NULL) return NULL; // Node not found!
        else if (n->value > value)
        {
            successor = n;
            n = n->left;
        }
        else if (n->value < value)
        {
            n = n->right;
        }
    }

    if (n->right)
    {
        return findMin(n->right);
    }

    return successor;
}

node *inorderPredecessor(node *root, int value)
{
    node *predecessor = NULL;
    node *n = root;
    while (n->value != value)
    {
        if (n == NULL) return NULL; // Node not found!
        else if (n->value > value)
        { 
            n = n->left;
        }
        else if (n->value < value)
        {
            predecessor = n;
            n = n->right;
        }
    }

    if (n->left)
    {
        return findMax(n->left);
    }
    
    return predecessor;
}

void *deleteNode(node *root, int value)
{
    node *temp;
    if (root == NULL) return NULL;
    else if (value < root->value) root->left = deleteNode(root->left, value);
    else if (value > root->value) root->left = deleteNode(root->right, value);
    else
    {
        if (root->left != NULL && root->right != NULL)
        {
            temp = findMin(root->right);
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->value);
        }
        else
        {
            temp = root;
            if (root->left == NULL)
                root = root->right;
            if (root->right == NULL)
                root = root->left;
            free(temp);
        }
    }
    return root;
}

void destructTree(node* root)
{
    if (root == NULL) return;
    destructTree(root->left);
    destructTree(root->right);
    free(root);
}