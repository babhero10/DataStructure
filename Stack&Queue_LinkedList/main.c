#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void showStack(Stack *q)
{
    Stack *temp = initStack();
    while (!isEmpty(q))
    {
        printf(" %d ", peek(q));
        push(temp, pop(q));
    }
    while (!isEmpty(temp))
    {
        push(q, pop(temp));
    }

    printf("\n");

    destructStack(temp);
    
}
int main()
{
    Stack *s = initStack(10);
    for (int i = 0; i < 10; i++)
    {
        printf("\n-----\nIs Empty: %d\n----\n", isEmpty(s));
      
        push(s, i);
        
    }
    printf("%d\n", pop(s));
    
    printf("%d\n", peek(s));
    showStack(s);
    destructStack(s);
    return 0;
}