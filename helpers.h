#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#include "heap.h"

extern int compare(int type, node *a, node *b);
extern int importFile(char* fName, list *vertList, list *edgeList);
extern node **getSortedVertexArray(list *l);
extern node **getSortedEdgeArray(list *l);
extern node **nodeListToArray(list *l);

#endif
