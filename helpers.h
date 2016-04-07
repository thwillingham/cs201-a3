#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "heap.h"

extern int compare(int type, node *a, node *b);
extern int importFile(heap *h, list *vertList, list *edgeList, char* fName);
extern node **getSortedVertexArray(list *l);
extern node **getSortedEdgeArray(list *l);
extern node **nodeListToArray(list *l);

#endif
