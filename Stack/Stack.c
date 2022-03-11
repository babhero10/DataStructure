#include <stdlib.h>
#include <stdio.h>

#define TYPE int

typedef struct {
    int top;
    TYPE *items;
    int capacity;
} Stack;

void initStack(Stack *s, int capacity) 
{
    s->items = (TYPE *) malloc(capacity * sizeof(TYPE));
    s->top = 0;
    s->capacity = capacity;
}

void push(TYPE item, Stack *s)
{
    s->items[s->top++] = item;
}

void pop(Stack *s)
{
    s->top--;
}

void freePopped(Stack *s)
{
    free(s->items[s->top--]);
}

TYPE peek(Stack *s)
{
    return s->items[s->top-1];
}

TYPE peekPop(Stack *s)
{
    TYPE temp = peek(s);
    pop(s);
    return temp;
}

int isEmpty(Stack *s)
{
    return (s->top == 0) ? 1:0; 
}

int isFull(Stack *s)
{
    return (s->top < s->capacity) ? 0:1; 
}

int length(Stack *s)
{
    return s->top;
}

void showStack(Stack *s)
{
    printf("[ ");
    for (int i = 0; i < s->top; i++)
    {
        printf(" %d ", s->items[i]);
    }
    printf(" ]\n");
}

void destructStack(Stack *s)
{
    free(s->items);
}