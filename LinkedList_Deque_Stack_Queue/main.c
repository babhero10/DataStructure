#include <stdio.h>
#include <stdlib.h>
// #include "Queue.h"
#include "Stack.h"

#define SIZE 10

// void showQueue(Queue *q);

// int main()
// {
//     Queue *q = initQueue();
//     int i = 1;
    
//     printf("is empty: %d\n", isEmpty(q));

//     while (i <= 10)
//     {
//         enqueue(q, i);
//         i+=1;
//     }

//     printf("is empty: %d\n", isEmpty(q));
//     printf("front: %d\nrear: %d\n", peekFront(q), peekRear(q));
//     dequeue(q);
//     printf("front: %d\nrear: %d\n", peekFront(q), peekRear(q));

//     printf("Show: ");
//     showQueue(q);
//     printf("is empty: %d\n", isEmpty(q));



   
//     return 0;
// }
// void showQueue(Queue *q)
// {
//     Queue *temp = initQueue();
//     while (!isEmpty(q))
//     {
//         printf("%d ", peekFront(q));
//         enqueue(temp, dequeue(q));
//     }

//     while (!isEmpty(temp))
//     {
//         enqueue(q, dequeue(temp));
//     }

//     printf("\n");

//     destructQueue(temp);
// }
void showStack(Stack *s)
{
    Stack *temp = initStack();
   
    while (!isEmpty(s))
    {
        push(temp, pop(s));
    }
    printf("[ ");
    
    while (!isEmpty(temp))
    {
        printf(" %d ", peek(temp));
        push(s, pop(temp));
    }

    printf(" ]\n");
}

int main()
{
    Stack *s = initStack(10);
    for (int i = 0; i < 10; i++)
    {
        printf("\n-----\nIs Empty: %d\n----\n", isEmpty(s));

        push(s, i);
    
    }
    printf("%d\n", peek(s));
    pop(s);
    printf("%d\n", peek(s));
    showStack(s);
    showStack(s);
    showStack(s);
    showStack(s);
    return 0;
}