#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue *initQueue()
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->dq = newSCDeque();
    return q;
}

void enqueue(Queue *q,TYPE item)
{
    insSCTail(q->dq, item);
}

TYPE dequeue(Queue *q)
{
    TYPE temp = getSData(getHeadSCDQ(q->dq));
    delSCHead(q->dq);
    return temp;
}

TYPE peekFront(Queue *q)
{
    return getSData(getHeadSCDQ(q->dq));
}

TYPE peekRear(Queue *q)
{
    return getSData(getTailSCDQ(q->dq));
}

TYPE isEmpty(Queue *q)
{
    return isEmptySCDQ(q->dq);
}

void destructQueue(Queue *q)
{
    free(q);
}