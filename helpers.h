#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "heap.h"
#include "rbt.h"
#include "array.h"

extern int compare(int type, node *a, node *b);
extern int importFile(char* fName, rbt *edgeTree, array *edgeArray, rbt *vertTree, array *vertArray);
extern node **getSortedVertexArray(list *l);
extern node **getSortedEdgeArray(list *l);
extern node **nodeListToArray(list *l);
extern int rbtEdgeNodeComparator(void *e1, void *e2);
extern int arrayEdgeNodeComparator(void *e1, void *e2);


#endif
