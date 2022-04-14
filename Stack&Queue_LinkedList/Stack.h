#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#define TYPE int // TYPE to change the stack datatype anytime

typedef struct node
{
    TYPE data;
    struct node *next;
} node;

typedef struct {
    node *top;
} Stack;

Stack *initStack();
void push(Stack *, TYPE);
TYPE pop(Stack *);
TYPE peek(Stack *);
int isEmpty(Stack *);
void destructStack(Stack *);

#endif // STACK_H_INCLUDED
