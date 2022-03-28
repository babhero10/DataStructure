#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue *initQueue()
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->dq = newDCDeque();
    return q;
}

void enqueue(Queue *q,TYPE item)
{
    insDCTail(q->dq, item);
}

TYPE dequeue(Queue *q)
{
    TYPE temp = getDData(getHeadDCDQ(q->dq));
    delDCHead(q->dq);
    return temp;
}

TYPE peekFront(Queue *q)
{
    return getDData(getHeadDCDQ(q->dq));
}

TYPE peekRear(Queue *q)
{
    return getDData(getTailDCDQ(q->dq));
}

TYPE isEmpty(Queue *q)
{
    return isEmptyDCDQ(q->dq);
}

void destructQueue(Queue *q)
{
    free(q);
}