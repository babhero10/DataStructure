#ifndef DEQUE_H_INCLUDED
#define DEQUE_H_INCLUDED
#include "LinkedList.h"

#define TYPE int
typedef struct  {
    SNode *Head;
    SNode *Tail;
} SGDeque;

typedef struct  {
    SNode *Tail;
} SCDeque;

typedef struct  {
    DNode *Head;
    DNode *Tail;
} DGDeque;
typedef struct  {
    DNode *Tail;
} DCDeque;

typedef struct  {
    SNode *SentHead;
    SNode *Tail;
} SentSGDeque;

// SGLL
SGDeque *newSGDeque() ;              // O(1)
SNode  *getHeadSGDQ(SGDeque *);      // O(1)
SNode  *getTailSGDQ(SGDeque *);      // O(1)
void insSGHead(SGDeque* ,TYPE );     // O(1)   
void insSGTail(SGDeque* ,TYPE );     // O(1)   
void delSGHead(SGDeque *) ;          // O(1)  
void delSGTail(SGDeque *) ;          // O(N)  
SNode *searchSGDQ(SGDeque* ,TYPE );  // O(N)
int isEmptySGDQ(SGDeque *);          // O(1)   
void destructSGDQ(SGDeque *);        // O(N)       

// SCLL
SCDeque *newSCDeque() ;              // O(1)
SNode  *getHeadSCDQ(SCDeque *);      // O(1)
SNode  *getTailSCDQ(SCDeque *);      // O(1)
void insSCHead(SCDeque* ,TYPE );     // O(1)   
void insSCTail(SCDeque* ,TYPE );     // O(1)   
void delSCHead(SCDeque *) ;          // O(1)  
void delSCTail(SCDeque *) ;          // O(N)  
SNode *searchSCDQ(SCDeque* ,TYPE );  // O(N)
int isEmptySCDQ(SCDeque *);          // O(1)    
void destructSCDQ(SCDeque *);        // O(N)       

// DGLL
DGDeque *newDGDeque() ;              // O(1)
DNode  *getHeadDGDQ(DGDeque *);      // O(1)
DNode  *getTailDGDQ(DGDeque *);      // O(1)
void insDGHead(DGDeque* ,TYPE );     // O(1)   
void insDGTail(DGDeque* ,TYPE );     // O(1)   
void delDGHead(DGDeque *) ;          // O(1)  
void delDGTail(DGDeque *) ;          // O(1)  
DNode *searchDGDQ(DGDeque* ,TYPE );  // O(N)
int isEmptyDGDQ(DGDeque *);          // O(1)        
void destructDGDQ(DGDeque *);        // O(N)   

// DCLL
DCDeque *newDCDeque() ;              // O(1)
DNode  *getHeadDCDQ(DCDeque *);      // O(1)
DNode  *getTailDCDQ(DCDeque *);      // O(1)
void insDCHead(DCDeque* ,TYPE );     // O(1)   
void insDCTail(DCDeque* ,TYPE );     // O(1)   
void delDCHead(DCDeque *) ;          // O(1)  
void delDCTail(DCDeque *) ;          // O(1)  
DNode *searchDCDQ(DCDeque* ,TYPE );  // O(N)
int isEmptyDCDQ(DCDeque *);          // O(1)
void destructDCDQ(DCDeque *);        // O(N)           

// Sentinal SGLL
SentSGDeque *newSentSGDeque() ;                  // O(1)
SNode  *getHeadSentSGDQ(SentSGDeque *);          // O(1)
SNode  *getTailSentSGDQ(SentSGDeque *);          // O(1)
void insSentSGHead(SentSGDeque* ,TYPE );         // O(1)   
void insSentSGTail(SentSGDeque* ,TYPE );         // O(1)   
void delSentSGHead(SentSGDeque *) ;              // O(1)  
void delSentSGTail(SentSGDeque *) ;              // O(N)  
SNode *searchSentSGDQ(SentSGDeque* ,TYPE );      // O(N)
int isEmptySentSGDQ(SentSGDeque *);              // O(1)  
void destructSentSGDQ(SentSGDeque *);            // O(N)       

#endif // DEQUE_H_INCLUDED