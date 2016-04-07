#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

list *newLList(void)
{
    struct list *l = (list *) malloc(sizeof(list));
    if (l==0) {fprintf(stderr,"out of memory"); exit(-1); }

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void addToHead(list *l, listNode *ln)
{
    if (!listIsNotEmpty(l))
    {
        l->head = ln;
        l->tail = ln;
        l->size++;
    }else
    {
        l->head->previous = ln;
        ln->next = l->head;
        ln->previous = NULL;
        l->head = ln;
        l->size++;
    };
    return;
}

listNode *seeHead(list *l)
{
    return l->head;
}

listNode *removeHead(list *l)
{
    listNode *temp = l->head;
    l->head = temp->next;
    l->head->previous = NULL;
    temp->previous = NULL;
    temp->next = NULL;

    return temp;
}

void addToTail(list *l, listNode *ln)
{
    if (!listIsNotEmpty(l))
    {
        l->head = ln;
        l->tail = ln;
        l->size++;
    }else
    {
        l->tail->next = ln;
        ln->previous = l->tail;
        ln->next = NULL;
        l->tail = ln;
        l->size++;
    };
    return;
}

listNode *seeTail(list *l)
{
    return l->tail;
}

listNode *removeTail(list *l)
{
    if (seeHead(l) == seeTail(l))
    {
    	if (!l->head)
    	{return NULL;}
    	else {
        listNode *ln = seeTail(l);
        l->size = 0;
        l->head = NULL;
        l->tail = NULL;
        return ln;
        }
    }else
    {
        listNode *temp = seeTail(l);
        l->tail = getListNodePrevious(temp);
        //l->tail->next = NULL;
        setListNodeNext(seeTail(l), NULL);
        temp->previous = NULL;
        temp->next = NULL;

        return temp;
    }
}

int listIsNotEmpty(list *l)
{
    return l->size;
}

int isInList(list *l, int i) {
    listNode *n = l->head;
    while (n != NULL) {
    //   printf("i: %d     |", i);
    //   printf("     n->val: %d\n", n->val);
        if (n->val == i) {
        //   printf("Vertex already in list\n");
           return 1;
        }
        n = n->next;
    }
    return 0;
}

int edgeIsInList(list *l, int f, int t) {
    listNode *n = l->head;
    // printf("\nChecking: from=%d, to=%d\n", f, t);
    while (n != NULL) {
        // printf("          from=%d, to=%d\n", n->value->from, n->value->to);
        if (f == n->value->from && t == n->value->to) {
        //   printf("Edge already in list\n");
          return 1;
        }
        if (f == n->value->to && t == n->value->from) {
        //   printf("Edge already in list\n");
          return 1;
        }
        n = n->next;
    }
    return 0;
}

void addVertInSortedOrder(list *l, listNode *n) {
    listNode *cur = l->head;
    listNode *temp = NULL;
    if (cur == NULL) {
        addToTail(l, n);
        return;
    } else if (n->val < cur->val) {
        addToHead(l, n);
        return;
    }
    while (cur != NULL) {
        if (n->val == cur->val) {
            return;
        } else if (n->val > cur->val) {
            if (cur->next == NULL) {
                addToTail(l, n);
                return;
            } else if (n->val < cur->next->val) {
                temp = cur->next;
                cur->next = n;
                n->previous = cur;
                n->next = temp;
                temp->previous = n;
                l->size++;
                return;
            }
        }
        cur = cur->next;
    }
}

void addNodeInSortedOrder(list *l, listNode *n) {
    listNode *cur = l->head;
    listNode *temp = NULL;
    if (cur == NULL) {
        addToTail(l, n);
        return;
    } else if (n->value->value < cur->value->value) {
        addToHead(l, n);
        return;
    }
    while (cur != NULL) {
        if (n->value->value == cur->value->value) {
            return;
        } else if (n->value->value > cur->value->value) {
            if (cur->next == NULL) {
                addToTail(l, n);
                return;
            } else if (n->value->value < cur->next->value->value) {
                temp = cur->next;
                cur->next = n;
                n->previous = cur;
                n->next = temp;
                temp->previous = n;
                l->size++;
                return;
            }
        }
        cur = cur->next;
    }
}
