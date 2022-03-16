#include <stdio.h>
#include <stdlib.h>

#define TYPE int

typedef struct  
{
    TYPE *items;
    int front;
    int rear;
    int capacity;
    int size; // The other solution is to use empty 
} Queue;

Queue *initQueue(int cap)
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->items = (TYPE *) malloc(sizeof(TYPE) * cap);
    q->capacity = cap;
    q->front = 0;
    q->rear = 0;
    q->size = 0;
}

void enqueue(Queue *q,TYPE item)
{
    q->items[q->rear++] = item;
    q->rear %= q->capacity;
    q->size++;
}

TYPE dequeue(Queue *q)
{
    TYPE temp = q->items[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return temp;
}

TYPE peekFront(Queue *q)
{
    return q->items[q->front];
}

TYPE peekRear(Queue *q)
{
    if (q->rear - 1 == -1) // when rear is 0
    {
        return q->items[q->capacity - 1];
    }

    return q->items[q->rear - 1];
}

TYPE isFull(Queue *q)
{
    return q->size == q->capacity;
}

TYPE isEmpty(Queue *q)
{
    return (q->size == 0) ? 1 : 0;
}

void destructQueue(Queue *q)
{
    free(q->items);
    free(q);
}