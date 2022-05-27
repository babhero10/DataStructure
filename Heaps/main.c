#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

void showArr(int arr[], int number)
{
    for (int i = 0; i < number; i++)
    {
        printf(" %i ", arr[i]);
    }
    printf("\n");
}

int main()
{
    Heap *h = newHeap();
    int n = 5;
    int arr[] = {1, 3, 5, 4, 2};
    buildHeap(arr, n);

    showArr(arr, n);

    insertHeap(h, 1);
    insertHeap(h, 3);
    insertHeap(h, 5);
    insertHeap(h, 4);
    insertHeap(h, 2);

    showArr(h->array, h->n);

    deleteNode(h, 2);
    showArr(h->array, h->n);

    pop(h);
    showArr(h->array, h->n);

    heapSort(arr, n);
    showArr(arr, n);

}