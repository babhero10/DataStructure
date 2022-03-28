#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#include "Deque.h"

#define TYPE int
typedef struct  {
    SentSGDeque *dq;
} Queue;

Queue *initQueue();
void enqueue(Queue *,TYPE );
TYPE dequeue(Queue *);
TYPE peekFront(Queue *);
TYPE peekRear(Queue *);
TYPE isEmpty(Queue *);
void destructQueue(Queue *);

#endif // QUEUE_H_INCLUDED