#ifndef STACK_H
#define STACK_H

#include "listNode.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

extern void pushStack(list *l, node *n);
extern node *popStack(list *l);
extern node *peekStack(list *l);

#endif
