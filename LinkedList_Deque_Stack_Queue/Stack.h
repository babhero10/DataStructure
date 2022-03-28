#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

#include "Deque.h"
#define TYPE int
typedef struct {
    SentSGDeque *dq;
} Stack;

Stack *initStack();
void destructStack(Stack *);
void push(Stack *, TYPE);
TYPE pop(Stack *);
void freePopped(Stack *);
TYPE peek(Stack *);
int isEmpty(Stack *);


#endif // STACK_H_INCLUDED
