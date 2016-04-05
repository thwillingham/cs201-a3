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

