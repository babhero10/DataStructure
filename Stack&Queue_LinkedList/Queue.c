#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

node *newNode(TYPE data)
{
    node *n = (node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

Queue *initQueue(int cap)
{
    Queue *q = (Queue *) malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(Queue *q,TYPE item)
{
    node *n = newNode(item);
    if (q->rear == NULL)
    {
        q->rear = q->front = n;
    }
    else
    {
        q->rear->next = n;
        q->rear = n;
    }
}

TYPE dequeue(Queue *q)
{
    TYPE item = q->front->data;
    if (q->front->next == NULL)
    {
        free(q->front);
        q->front = q->rear = NULL;;
    }
    else
    {
        node *temp = q->front;
        q->front = q->front->next;
        free(temp);
    }

    return item;
}

TYPE peekFront(Queue *q)
{
    return q->front->data;
}

TYPE peekRear(Queue *q)
{
    return q->rear->data;
}


TYPE isEmpty(Queue *q)
{
    return (q->front == NULL) ? 1 : 0;
}

void destructQueue(Queue *q)
{
    while (!isEmpty(q))
    {
        dequeue(q);
    }

    free(q);
}