#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// int main()
// {
//     DNode *n = NULL;
//     DNode *f = insDGNodeAfter(n, 1);
//     n = f;
//     for (int i = 2; i <= 10; i++)
//     {
//         n = insDGNodeAfter(n, i);        
//     }
//     DNode *n1 = getDGTail(f);
//     DNode *n2 = getDGPreTail(f);
//     for (int i = 0; i <= 12; i++)
//     {       
//         printf("%d %d %d\n", getDData(n1), getDData(n2), getDData(searchDGNode(f, i)));
//     }
    
//     destructDG(n);
// }

int main()
{
    DNode *n = NULL;
    DNode *f = insDCNodeAfter(n, 1);
    n = f;
    for (int i = 1; i <= 10; i++)
    {
        n = insDCNodeAfter(n, i);        
    }
    // delDCCurrentNode(f);
    for (int i = 0; i <= 12; i++)
    {       
        printf("%d %d\n", getDData(getDCPreNode(f)), getDData(searchDCNode(f, i)));
    }
    
    destructDC(n);
}