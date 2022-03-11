#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

int main()
{
    Stack *s;
    initStack(s, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("\n-----\nLength: %d\nIs Empty: %d\nIs Full: %d\n----\n", length(s), isEmpty(s), isFull(s));
        if (!isFull(s)) 
        {
            push(i, s);
        }
    }
    printf("\n-----\nIs Full: %d\n----\n", isFull(s));
    printf("%d\n", peek(s));
    pop(s);
    printf("%d\n", peek(s));
    showStack(s);
    destructStack(s);
    return 0;
}