#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "listNode.h"

typedef struct list list;
struct list
{
    struct listNode *head;
    struct listNode *tail;
    int size;
};

extern void addToHead(list *l, listNode *ln);
extern listNode *seeHead(list *l);
extern listNode *removeHead(list *l);
extern void addToTail(list *l, listNode *ln);
extern listNode *seeTail(list *l);
extern listNode *removeTail(list *l);
extern list *newLList(void);
extern int listIsNotEmpty(list *l);
extern int isInList(list *l, int i);
extern int edgeIsInList(list *l, int f, int t);
extern void addVertInSortedOrder(list *l, listNode *n);
extern node *addNodeInSortedOrder(list *l, listNode *n);

#endif
