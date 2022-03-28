#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack *initStack() 
{
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->dq = newSentSGDeque();
    return s;
}

void push(Stack *s, TYPE item)
{
    insSentSGHead(s->dq, item);
}

TYPE peek(Stack *s)
{
    return getSData(getHeadSentSGDQ(s->dq));
}

TYPE pop(Stack *s)
{
    TYPE temp = peek(s);
    delSentSGHead(s->dq);
    return temp;
}

int isEmpty(Stack *s)
{
    return isEmptySentSGDQ(s->dq);
}

void destructStack(Stack *s)
{
    destructSentSGDQ(s->dq);
    free(s);
}
