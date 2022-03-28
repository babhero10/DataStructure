#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

/////////////////////////////// SGLL ///////////////////////////////
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
    return (dq->Head == NULL) ? 1 : 0;
}         

/////////////////////////////// SCLL ///////////////////////////////
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
    return (dq->Tail == NULL) ? 1 : 0;
}

/////////////////////////////// DGLL ///////////////////////////////
DGDeque* newDGDeque()
{
    DGDeque *dq = (DGDeque *) malloc(sizeof(DGDeque));
    dq->Head = NULL;
    dq->Tail = NULL;
}

DNode * getHeadDGDQ(DGDeque *dq)
{
    return dq->Head;
}

DNode * getTailDGDQ(DGDeque *dq)
{
    return dq->Tail;
}

void insDGHead(DGDeque *dq, TYPE data)
{
    DNode *newNode = newDGNode(data);
    dq->Head = insDGNodeBefore(dq->Head, data);

    if (dq->Tail == NULL)
        dq->Tail = dq->Head;
} 

void insDGTail(DGDeque *dq, TYPE data)
{
    DNode *newTail = insDGNodeAfter(dq->Tail, data);
    dq->Tail = newTail;

    if (dq->Head == NULL)
        dq->Head = dq->Tail;
}

void delDGHead(DGDeque *dq)
{
    dq->Head = delDGCurrentNode(dq->Head);

    if (dq->Head == NULL)
         dq->Tail=NULL;
}
void delDGTail(DGDeque *dq)
{
    dq->Tail = delDGCurrentNode(dq->Tail);

    if (dq->Tail == NULL)
         dq->Head=NULL;
}

DNode *searchDGDQ(DGDeque *dq,TYPE data)
{
    return searchDGNode(dq->Head, data);
}

int isEmptyDGDQ(DGDeque *dq)
{
    return (dq->Head == NULL) ? 1 : 0;
}

/////////////////////////////// DCLL ///////////////////////////////
DCDeque* newDCDeque()
{
    DCDeque *dq = (DCDeque *) malloc(sizeof(DCDeque));
    dq->Tail = NULL;
}

DNode * getHeadDCDQ(DCDeque *dq)
{
    return dq->Tail->next;
}

DNode * getTailDCDQ(DCDeque *dq)
{
    return dq->Tail;
}

void insDCHead(DCDeque *dq, TYPE data)
{
    DNode *newNode = insDCNodeAfter(dq->Tail, data);
    if (dq->Tail == NULL)
    {
        dq->Tail = newNode;
    }
}

void insDCTail(DCDeque *dq, TYPE data)
{
    DNode *newNode = insDCNodeAfter(dq->Tail, data);
    if (dq->Tail != NULL)
    {
        dq->Tail = dq->Tail->next;
    }
    else
    {
        dq->Tail = newNode;
    }  
}
void delDCHead(DCDeque *dq)
{
    dq->Tail = delDCNodeAfter(dq->Tail);
}

void delDCTail(DCDeque *dq)
{
    dq->Tail = delDCCurrentNode(dq->Tail);
}

DNode *searchDCDQ(DCDeque *dq, TYPE data)
{
    return searchDCNode(dq->Tail, data);
}
int isEmptyDCDQ(DCDeque *dq)
{
    return (dq->Tail == NULL) ? 1 : 0;
}   

/////////////////////////////// Sentinal SGLL ///////////////////////////////
SentSGDeque *newSentSGDeque()
{
    SentSGDeque *dq = (SentSGDeque *) malloc(sizeof(SentSGDeque));
    dq->SentHead = newSGNode(-1);
    dq->Tail = NULL;
    return dq;
}

SNode *getHeadSentSGDQ(SentSGDeque *dq)
{
    return dq->SentHead->next;
}

SNode *getTailSentSGDQ(SentSGDeque *dq)
{
    return dq->Tail;
}

void insSentSGHead(SentSGDeque *dq, TYPE data)
{
    insSGNodeAfter(dq->SentHead, data);
} 

void insSentSGTail(SentSGDeque *dq, TYPE data)
{
    if (dq->Tail != NULL)
    {
        dq->Tail = insSGNodeAfter(dq->Tail, data);
    }
    else
    {
        dq->Tail = insSGNodeAfter(dq->SentHead, data);
    }
    
}  

void delSentSGHead(SentSGDeque *dq)
{
    if (dq->SentHead->next != NULL)
        delSGNodeAfter(dq->SentHead);
    
    if (dq->SentHead->next == NULL) // Deque is empty
        dq->Tail = NULL;
}

void delSentSGTail(SentSGDeque *dq)
{
    if (dq->SentHead->next != NULL)
        dq->Tail = delSGNodeAfter(getSGPreTail(dq->SentHead));
        
    if (dq->SentHead->next == NULL) // Deque is empty
        dq->Tail = NULL;
}

SNode *searchSentSGDQ(SentSGDeque *dq, TYPE data)
{
    return searchSGNode(dq->SentHead, data);
}

int isEmptySentSGDQ(SentSGDeque *dq)
{
    return (getHeadSentSGDQ(dq) == NULL) ? 1 : 0;
}