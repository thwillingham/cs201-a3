#ifndef LISTNODE_H
#define LISTNODE_H
#include "node.h"

typedef struct listNode listNode;
struct listNode
    {
        struct node *value;
        int val;
        struct listNode *next;
        struct listNode *previous;
        int color;
    };

extern listNode *newListNode(void);
extern void setListNodeValue(listNode *ln, node *value);
extern node *getListNodeValue(listNode *ln);
extern void setListNodeNext(listNode *ln, listNode *lnext);
extern listNode *getListNodeNext(listNode *ln);
extern void setListNodePrevious(listNode *ln, listNode *lprevious);
extern listNode *getListNodePrevious(listNode *ln);

#endif
