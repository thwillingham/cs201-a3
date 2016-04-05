#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"

typedef struct graph graph;
struct graph {
    int size;
    node** edges;
    //node vertices[];
};

extern graph *newGraph(int size);
extern void heapToGraph(graph *g, heap *h);

#endif
