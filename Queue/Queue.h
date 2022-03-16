#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED

#define TYPE int
typedef struct  {

} Queue;

Queue *initQueue(int);
void enqueue(Queue *,TYPE );
TYPE dequeue(Queue *);
TYPE peekFront(Queue *);
TYPE peekRear(Queue *);
TYPE isFull(Queue *);
TYPE isEmpty(Queue *);
void destructQueue(Queue *);

#endif // QUEUE_H_INCLUDED