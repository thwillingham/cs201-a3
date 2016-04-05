#ifndef QUEUE_H
#define QUEUE_H

#include "listNode.h"
#include "node.h"
#include "linkedList.h"

extern void enqueue(list *l, node *n);
extern node *dequeue(list *l);
extern node *pequeue(list *l);

#endif
