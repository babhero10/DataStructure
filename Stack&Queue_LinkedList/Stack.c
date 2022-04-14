#include <stdlib.h>
#include <stdio.h>

#include "Stack.h"

node *newNode(TYPE data)
{
    node *n = (node *) malloc(sizeof(node));
    n->data = data;
    n->next = NULL;
    return n;
}

Stack *initStack() 
{
    Stack *s = (Stack *) malloc(sizeof(Stack));
    s->top = NULL;
    return s;
}

void push(Stack *s, TYPE item)
{
    node *n = newNode(item);
    if (s->top == NULL)
    {
        s->top = n;
    }
    else
    {
        n->next = s->top;
        s->top = n;
    }
}

TYPE pop(Stack *s)
{
    TYPE data = s->top->data;

    if (s->top->next == NULL)
    {
        free(s->top);
        s->top = NULL;
    }
    else
    {
        node *temp = s->top;
        s->top = s->top->next;
        free(temp);
    }

    return data;
}

TYPE peek(Stack *s)
{
    return s->top->data;
}

int isEmpty(Stack *s)
{
    return (s->top == NULL) ? 1:0; 
}

void destructStack(Stack *s)
{
    while (!isEmpty(s))
    {
        pop(s);
    }
    free(s);
}
    