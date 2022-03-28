#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

/////////////////////////////// Singly
SNode *newSGNode(TYPE data)
{
    SNode *newNode = (SNode *) malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = NULL;
}

SNode *getSNext(SNode *n)
{
    return n?n->next:n;
}

TYPE getSData(SNode *n)
{
    return n ? n->data : -1;
}

/////////////////////////////// Singly Ground LinkedList (SGLL) ///////////////////////////////
SNode *searchSGNode(SNode *n, TYPE data)
{
    SNode *currentNode = n;
    while (currentNode != NULL)
    {
        if (currentNode->data == data)
            return currentNode;
        currentNode = getSNext(currentNode);
    }
    return NULL;
}

SNode *searchSGRec(SNode *n, TYPE data)
{
    if (n == NULL)
        return n;
    
    if (n->data == data)
        return n;

    searchSGRec(getSNext(n), data);
}   

SNode *insSGNodeAfter(SNode *n, TYPE data)
{
    SNode *newNode = newSGNode(data);

    if (n != NULL) // Not First node
    {
        newNode->next = getSNext(n);
        n->next = newNode;
    }
        
    return newNode;
} 

SNode *delSGNodeAfter(SNode *n)
{
    if (n != NULL) // List isn't empty
    {
        SNode *nextNode = getSNext(n);
        if (nextNode != NULL) // Node not last node
        {
            n->next = getSNext(nextNode);
            free(nextNode);
        }
    }

    return n; 
}

SNode *getSGTail(SNode *n)
{
    if (n != NULL) // List not empty
    {
        while (getSNext(n) != NULL)
        {
            n = getSNext(n);
        }
    }

    return n;    
}            

SNode *getSGPreTail(SNode *n)
{
    SNode *prev = NULL;
    if (n != NULL) // List not empty
    {
        while (getSNext(n) != NULL)
        {
            prev = n;
            n = getSNext(n);
        }
    }

    return prev;   
}   

void destructSG(SNode *n)
{
    if (n != NULL) // List not empty
    {
        while (getSNext(n) != NULL) // Delete next until no more to delete
            delSGNodeAfter(n);
        free(n); // Free head
    }
}            

/////////////////////////////// Singly Circular LinkedList (SCLL) ///////////////////////////////
SNode *newSCNode(TYPE data)
{
    SNode *newNode = (SNode *) malloc(sizeof(SNode));
    newNode->data = data;
    newNode->next = newNode;
}

SNode *searchSCNode(SNode *n,TYPE data)
{
    SNode *currentNode = n;
    while (currentNode)
    {
        if (currentNode->data == data)
            return currentNode;

        currentNode = getSNext(currentNode);

        if (currentNode == n)
            break;
    }
    return NULL;
}   

SNode *searchSCRec(SNode *n,TYPE data); // No need hard to make can be done with more parameter SNode *start

SNode *insSCNodeAfter(SNode *n,TYPE data)
{
    SNode *newNode = newSCNode(data);

    if (n != NULL) // Not First node
    {
        newNode->next = getSNext(n);
        n->next = newNode;
    }
        
    return newNode;
}

SNode *delSCNodeAfter(SNode *n)
{
    if (n != NULL) // List isn't empty
    {
        SNode *nextNode = getSNext(n);
        if (nextNode != n) // Node not last node
            n->next = getSNext(nextNode);
        else
            n = NULL;
        free(nextNode);
    }

    return n; 
}   
             
SNode *getSCPreNode(SNode *n)
{
    SNode *prev = NULL;
    SNode *start = n;
    if (n != NULL) // List not empty
    {
        while (start != getSNext(n))
        {
            prev = n;
            n = getSNext(n);
        }
    }

    return prev;   
}   

void   destructSC(SNode *n)
{
    SNode *start = n;
    if (n != NULL) // List not empty
    {
        while (start != getSNext(n)) // Delete next until no more to delete
            delSGNodeAfter(n);
        free(start); // Free last node
    }
}         

/////////////////////////////// Doubly ///////////////////////////////
DNode *newDGNode(TYPE data) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
}

DNode *getDNext(DNode *n)
{
    return n?n->next:n;
}

DNode *getDPre(DNode *n)
{
    return n?n->prev:n;
}

TYPE getDData(DNode *n)
{
    return n ? n->data : -1;
}

/////////////////////////////// Doubly Ground LinkedList (DGLL) ///////////////////////////////
DNode *searchDGNode(DNode *n, TYPE data)
{
    DNode *currentNode = n;
    while (currentNode != NULL)
    {
        if (currentNode->data == data)
            return currentNode;
        currentNode = getDNext(currentNode);
    }
    return NULL;
}   

DNode *searchDGRec(DNode *n, TYPE data)
{
    if (n == NULL)
        return n;
    
    if (n->data == data)
        return n;

    searchDGRec(getDNext(n), data);
}   

DNode *insDGNodeAfter(DNode *n,TYPE data)
{
    DNode *newNode = newDGNode(data);

    if (n != NULL) // Not First node
    {
        newNode->next = getDNext(n);
        newNode->prev = n;
        
        if (n->next) 
            n->next->prev = newNode;
        
        n->next = newNode;
    }
        
    return newNode;
}  

DNode *delDGNodeAfter(DNode *n)
{
    if (n != NULL) // List isn't empty
    {
        DNode *nextNode = getDNext(n);
        if (nextNode != NULL) // Node not last node
        {
            if(nextNode->next) 
                nextNode->next->prev = n;
            
            n->next = getDNext(nextNode);
            free(nextNode);
        }
    }

    return n; 
}   
      
DNode *insDGNodeBefore(DNode *n, TYPE data)
{
    DNode *newNode = newDGNode(data);

    if (n != NULL) // Not First node
    {
        newNode->prev = getDPre(n);
        newNode->next = n;
        
        if (n->prev)
            n->prev->next = newNode;
        
        n->prev = newNode;
    }
        
    return newNode;
}   

DNode *delDGCurrentNode(DNode *n)
{
    DNode *prevNode = NULL;
    if (n != NULL) // List isn't empty
    {
        if (getDNext(n)) 
        {
            n->next->prev = getDPre(n);
            prevNode = getDPre(n);
        }

        if (getDPre(n)) // Not first node
        {
            n->prev->next = getDNext(n);
        }
        else
        {
            prevNode = n->next; // Return the new first node
        }

        free(n);
    }

    return prevNode; 
}   

DNode *getDGTail(DNode *n)
{
    if (n != NULL) // List not empty
    {
        while (getDNext(n) != NULL)
        {
            n = getDNext(n);
        }
    }

    return n;    
}   

DNode *getDGPreTail(DNode *n)
{
    DNode *prev = NULL;
    if (n != NULL) // List not empty
    {
        while (getDNext(n) != NULL)
        {
            prev = n;
            n = getDNext(n);
        }
    }

    return prev;   
}

void   destructDG(DNode *n)
{
    if (n != NULL) // List not empty
    {
        while (getDNext(n) != NULL) // Delete next until no more to delete
            delDGNodeAfter(n);
        free(n); // Free head
    }
}           

/////////////////////////////// Doubly Ground LinkedList (DCLL) ///////////////////////////////
DNode *newDCNode(TYPE data) {
    DNode *newNode = (DNode *) malloc(sizeof(DNode));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
}

DNode *searchDCNode(DNode *n, TYPE data)
{
    DNode *currentNode = n;
    while (currentNode)
    {
        if (currentNode->data == data)
            return currentNode;

        currentNode = getDNext(currentNode);

        if (currentNode == n)
            break;
    }
    return NULL;
}   

DNode *searchDCRec(DNode *n, TYPE data);   // No need hard to make can be done with more parameter DNode *start    

DNode *insDCNodeAfter(DNode *n, TYPE data)
{
    DNode *newNode = newDCNode(data);

    if (n != NULL) // Not First node
    {
        newNode->next = getDNext(n);
        n->next = newNode;
    }
        
    return newNode;
}  

DNode *delDCNodeAfter(DNode *n)
{
    if (n != NULL) // List isn't empty
    {
        DNode *nextNode = getDNext(n);
        if (nextNode != n) // Node not last node
            n->next = getDNext(nextNode);
        else
            n = NULL;
        free(nextNode);
    }

    return n; 
}  

DNode *insDCNodeBefore(DNode *n, TYPE data)
{
    DNode *newNode = newDGNode(data);

    if (n != NULL) // Not First node
    {
        newNode->prev = getDPre(n);
        newNode->next = n;
        
        n->prev->next = newNode;
        
        n->prev = newNode;
    }
        
    return newNode;
}   

DNode *delDCCurrentNode(DNode *n) // return Node before n
{
    DNode *prevNode = NULL;
    if (n != NULL) // List isn't empty
    {
        n->prev->next = getDNext(n);
        if (getDNext(n) != n)
        {
            n->next->prev = getDPre(n);
            prevNode = getDPre(n);   
        } 
        else
        {
            prevNode = NULL;
        }

        free(n);
    }

    return prevNode; 
}

DNode *getDCPreNode(DNode *n)
{
    DNode *prev = NULL;
    DNode *start = n;
    if (n != NULL) // List not empty
    {
        while (start != getDNext(n))
        {
            prev = n;
            n = getDNext(n);
        }
    }

    return prev;  
}   

void   destructDC(DNode *n)
{
    DNode *start = n;
    if (n != NULL) // List not empty
    {
        while (getDNext(n) != start) // Delete next until no more to delete
            delDGNodeAfter(n);
        free(start); // Free head
    }
}              