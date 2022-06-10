#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

int main()
{
    node *root = NULL;
    root = insert(root, 15);
    insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 12);
    insert(root, 25);
    printf("%d\n", search(root, 12)->value);
    printf("%p\n", search(root, 11));
    inOrder(root);
    printf("\n");
    printf("successor for 20: %d, Predeseccor for 20: %d", inorderSuccessor(root, 20)->value, inorderPredecessor(root, 20)->value);
    printf("\n");
    preOreder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    destructTree(root);
}