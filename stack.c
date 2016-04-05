#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "listNode.h"
#include "stack.h"

void pushStack(list *l, node *n)
{
    listNode *ln = newListNode();
    setListNodeValue(ln, n);
    addToTail(l,ln);

    return;
};

node *popStack(list *l)
{
    listNode *ln = removeTail(l);
    if (!ln)
    {
        return NULL;
    }else
    {
    node *n = getListNodeValue(ln);
    return n;
    }
};

node *peekStack(list *l) //peek at next node to pop from stack
{
    listNode *ln = seeTail(l);
    if (!ln)
    {
        return NULL;
    }else
    {
        node *n = ln->value;
        return n;
    }
};

