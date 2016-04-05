#include <stdio.h>
#include <stdlib.h>
#include "listNode.h"

listNode *newListNode()
{
    listNode *ln = (listNode *) malloc(sizeof(listNode));
    if (ln==0) { fprintf(stderr,"out of memory"); exit(-1); }
    
    ln->value = NULL; // pointer to tree/heap node
    ln->next = NULL;
    ln->previous = NULL;

    return ln;
}

void setListNodeValue(listNode *ln, node *value)
{
    ln->value = value;
    return;
}

node *getListNodeValue(listNode *ln)
{
    return ln->value;
}

void setListNodeNext(listNode *ln, listNode *lnext)
{
    ln->next = lnext;
    return;
}
listNode *getListNodeNext(listNode *ln)
{
    return ln->next;
}

void setListNodePrevious(listNode *ln, listNode *lprevious)
{
    ln->previous = lprevious;
    return;
}

listNode *getListNodePrevious(listNode *ln)
{
    return ln->previous;
}
