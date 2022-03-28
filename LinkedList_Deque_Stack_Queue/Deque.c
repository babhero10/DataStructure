#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

///////////////////////// SGLL
SGDeque* newSGDeque()
{
    SGDeque *dq = (SGDeque *) malloc(sizeof(SGDeque));
    dq->Head = NULL;
    dq->Tail = NULL;
}
SNode * getHeadSGDQ(SGDeque *dq)
{
    return dq->Head;
}

SNode * getTailSGDQ(SGDeque *dq)
{
    return dq->Tail;
}

void insSGHead(SGDeque *dq, TYPE data)
{
    SNode *newNode = newSGNode(data);
    newNode->next = dq->Head;
    dq->Head = newNode;
    if (getTailSGDQ(dq) == NULL)
        dq->Tail = dq->Head;
}

void insSGTail(SGDeque *dq, TYPE data)
{
    SNode *newTail = insSGNodeAfter(dq->Tail, data);
    dq->Tail = newTail;

    if (getHeadSGDQ(dq) == NULL)
        dq->Head = dq->Tail;
}  

void delSGHead(SGDeque *dq)
{
    SNode *Head = dq->Head;
    if(Head == NULL)
    {
        return;
    }
    if(Head->next == NULL) // Last element
    {
        dq->Head = NULL;
        dq->Tail = NULL;
    }
    else
    {
        dq->Head = getSNext(dq->Head);   
    }

    free(Head);
} 

void delSGTail(SGDeque *dq)
{
    SNode *Head = getHeadSGDQ(dq);
    if (Head == NULL) 
    {
        return;
    }
    else if (getSNext(Head) == NULL) // Tail == Head
    {
        dq->Head = NULL;
        dq->Tail = NULL;
    } 
    else 
    {
        dq->Tail = delSGNodeAfter(getSGPreTail(Head));
    }
}

SNode *searchSGDQ(SGDeque *dq, TYPE data)
{
    return searchSGNode(dq->Head, data);
}
 
int isEmptySGDQ(SGDeque *dq)
{
    return (dq->Head == NULL) ? 1:0;
}         

///////////////////////// SCLL
SCDeque* newSCDeque()
{
    SCDeque *dq = (SCDeque *) malloc(sizeof(SCDeque));
    dq->Tail = NULL;
}

SNode * getHeadSCDQ(SCDeque *dq)
{
    return getSNext(dq->Tail);
}
SNode * getTailSCDQ(SCDeque *dq)
{
    return dq->Tail;
}

void insSCHead(SCDeque *dq,TYPE data)
{
    SNode *newNode = insSCNodeAfter(dq->Tail, data);
    if (dq->Tail == NULL)
    {
        dq->Tail = newNode;
    }
} 

void insSCTail(SCDeque *dq, TYPE data)
{
    SNode *newNode = insSCNodeAfter(dq->Tail, data);

    if (dq->Tail != NULL)
    {
        dq->Tail = dq->Tail->next;
    }
    else
    {
        dq->Tail = newNode;
    }        
}
void delSCHead(SCDeque * dq)
{
    dq->Tail = delSCNodeAfter(dq->Tail);
} 

void delSCTail(SCDeque *dq)
{
    dq->Tail = delSCNodeAfter(getSCPreNode(dq->Tail));
}

SNode *searchSCDQ(SCDeque *dq, TYPE data)
{
    return searchSCNode(dq->Tail, data);
}

int isEmptySCDQ(SCDeque *dq)
{
    return (dq->Tail == NULL) ? 1:0;
}

///////////////////////// DGLL
DGDeque* newDGDeque()
{
    DGDeque *dq = (DGDeque *) malloc(sizeof(DGDeque));
    dq->Head = NULL;
    dq->Tail = NULL;
}

///////////////////////// DCLL
DCDeque* newDCDeque()
{
    DCDeque *dq = (DCDeque *) malloc(sizeof(DCDeque));
    dq->Tail = NULL;
}