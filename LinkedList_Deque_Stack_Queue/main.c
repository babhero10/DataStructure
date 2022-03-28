#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

#define SIZE 10

void showQueue(Queue *q);

int main()
{
    Queue *q = initQueue();
    int i = 1;
    
    printf("is empty: %d\n", isEmpty(q));

    while (i <= 10)
    {
        enqueue(q, i);
        i+=1;
    }

    printf("is empty: %d\n", isEmpty(q));
    printf("front: %d\nrear: %d\n", peekFront(q), peekRear(q));
    dequeue(q);
    printf("front: %d\nrear: %d\n", peekFront(q), peekRear(q));

    printf("Show: ");
    showQueue(q);
    printf("is empty: %d\n", isEmpty(q));


    destructQueue(q);
    return 0;
}

void showQueue(Queue *q)
{
    Queue *temp = initQueue();
    while (!isEmpty(q))
    {
        printf(" %d ", peekFront(q));
        enqueue(temp, dequeue(q));
    }
    while (!isEmpty(temp))
    {
        enqueue(q, dequeue(temp));
    }

    printf("\n");

    destructQueue(temp);
}