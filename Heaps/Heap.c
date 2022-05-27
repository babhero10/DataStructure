#include <stdio.h>
#include <stdlib.h>
#include "Heap.h"

Heap *newHeap() 
{
    Heap *h = (Heap *) malloc(sizeof(Heap));
    h->n = 0;
    return h;
}

void insertHeap(Heap *h, int value)
{
    h->array[h->n] = value;
    siftUp(h->array, h->n);
    h->n++;
}

int getMax(Heap *h)
{
    return h->array[0];
} 

void pop(Heap *h)
{
    h->array[0] = h->array[h->n - 1];
    h->n--;
    siftDown(h->array, h->n, 0);
}

void deleteNode(Heap *h, int i)
{
    h->array[i] = h->array[h->n - 1];
    h->n--;
    siftDown(h->array, h->n, i);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void siftDown(int *arr, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])  largest = left;

    if (right < n && arr[right] > arr[largest])   largest = right;
    if (largest != i) 
    { 
        swap(&arr[i], &arr[largest]);
        siftDown(arr, n, largest);
    }
    
}

void siftUp(int *arr, int i)
{
    int parent = (i - 1) / 2;
    if (i != 0 && arr[parent] < arr[i])
    {
        swap(&arr[i], &arr[parent]);
        siftUp(arr, parent);
    }
}

void buildHeap(int *arr, int n)
{
    int last_parent = (n / 2) - 1;
    for (int i = last_parent; i >= 0; i--)
    {
        siftDown(arr, n, i);
    }
    
}

void heapSort(int *arr, int n)
{
    buildHeap(arr, n);
    
    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) 
    {
        swap(&arr[0], &arr[i]); // Move current to end
        siftDown(arr, i, 0);
    }
}