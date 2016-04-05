#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "listNode.h"
#include "queue.h"

void enqueue(list *l, node *n)
{
    listNode *ln = newListNode();
    setListNodeValue(ln, n);
    addToHead(l,ln);

    return;
};

node *dequeue(list *l)
{
    listNode *ln = removeTail(l);
    node *n = ln->value;
    return n;
};

node *pequeue(list *l) //peek at next node to dequeue
{
    listNode *ln = seeTail(l);
    node *n = getListNodeValue(ln);
    return n;
};

