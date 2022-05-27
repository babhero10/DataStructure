#ifndef HEAP_H_INCLUDED
#define HEAP_H_INCLUDED
#define MAX_LENGTH 100

typedef struct
{
    int n;
    int array[MAX_LENGTH];
} Heap;

Heap *newHeap();

void insertHeap(Heap *, int);
int getMax(Heap *);
void pop(Heap *); // Delete root
void deleteNode(Heap *, int); // Delete node

void siftDown(int *, int, int);
void siftUp(int *, int);

void buildHeap(int *, int);
void heapSort(int *, int);

#endif // HEAP_H_INCLUDED