#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED
#define TYPE int

typedef struct {

} Stack;

void initStack(Stack *, int);
void destructStack(Stack *);
void push(TYPE, Stack *);
void pop(Stack *);
void freePopped(Stack *);
TYPE peek(Stack *);
TYPE peekPop(Stack *);
int isEmpty(Stack *);
int isFull(Stack *);
int length(Stack *);
void showStack(Stack *);

#endif // STACK_H_INCLUDED
