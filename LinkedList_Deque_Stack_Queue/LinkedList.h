#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED

#define TYPE int
typedef struct SNode {
    TYPE data;
    struct SNode *next;
} SNode;

typedef struct DNode {
    TYPE data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// Singly
SNode *newSNode(TYPE data);
TYPE getSData(SNode *);
// SGLL
SNode *searchSGNode(SNode *,TYPE);        // O(N)
SNode *searchSGRec(SNode *,TYPE) ;        // O(N)
SNode *insSGNodeAfter(SNode *,TYPE) ;     // O(1)
SNode *delSGNodeAfter(SNode *);           // O(1)
SNode *getSGTail(SNode *);                // O(N)
SNode *getSGPreTail(SNode *);             // O(N)
void   destructSG(SNode *);               // O(N)

// SCLL
SNode *searchSCNode(SNode *,TYPE);        // O(N)
SNode *searchSCRec(SNode *,TYPE) ;        // O(N)
SNode *insSCNodeAfter(SNode *,TYPE) ;     // O(1)
SNode *delSCNodeAfter(SNode *);           // O(1)
SNode *getSCPreNode(SNode *) ;            // O(N)
void   destructSC(SNode *);               // O(N)

// Doubly
DNode *newDNode(TYPE data);
DNode *getDNext(DNode *);
DNode *getDPre(DNode *);
TYPE  getDData(DNode *);

// DGLL
DNode *searchDGNode(DNode *,TYPE);        // O(N)
DNode *searchDGRec(DNode *,TYPE) ;        // O(N)
DNode *insDGNodeAfter(DNode *,TYPE) ;     // O(1)
DNode *delDGNodeAfter(DNode *);           // O(1)
DNode *getDGTail(DNode *);                // O(N)
DNode *getDGPreTail(DNode *) ;            // O(N)
DNode *insDGNodeBefore(DNode *,TYPE);      // O(1) -- New         
DNode *delDGCurrentNode(DNode *);         // O(1) -- New 
void   destructDG(DNode *);               // O(N)

// DCLL
DNode *searchDCNode(DNode *,TYPE);        // O(N)
DNode *searchDCRec(DNode *,TYPE) ;        // O(N)
DNode *insDCNodeAfter(DNode *,TYPE) ;     // O(1)
DNode *delDCNodeAfter(DNode *);           // O(1)
DNode *getDCPreNode(DNode *) ;            // O(1)
DNode *insDCNodeBefore(DNode *,TYPE);      // O(1) -- New         
DNode *delDCCurrentNode(DNode *);         // O(1) -- New 
void   destructDC(DNode *);               // O(N)

#endif // LINKEDLIST_H_INCLUDED