#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

Queue *initQueue()
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->dq = newSentSGDeque();
    return q;
}

void enqueue(Queue *q,TYPE item)
{
    insSentSGTail(q->dq, item);
}

TYPE dequeue(Queue *q)
{
    TYPE temp = getSData(getHeadSentSGDQ(q->dq));
    delSentSGHead(q->dq);
    return temp;
}

TYPE peekFront(Queue *q)
{
    return getSData(getHeadSentSGDQ(q->dq));
}

TYPE peekRear(Queue *q)
{
    return getSData(getTailSentSGDQ(q->dq));
}

TYPE isEmpty(Queue *q)
{
    return isEmptySentSGDQ(q->dq);
}

void destructQueue(Queue *q)
{
    free(q);
}