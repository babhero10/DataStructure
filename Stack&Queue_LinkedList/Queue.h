#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define TYPE int // TYPE to change the queue datatype anytime

typedef struct node
{
    TYPE data;
    struct node *next;
} node;

typedef struct  
{
    node *front;
    node *rear;
} Queue;

Queue *initQueue();
void enqueue(Queue *,TYPE );
TYPE dequeue(Queue *);
TYPE peekFront(Queue *);
TYPE peekRear(Queue *);
int isEmpty(Queue *);
void destructQueue(Queue *);

#endif // QUEUE_H_INCLUDED