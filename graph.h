#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "heap.h"
#include "node.h"
#include "linkedList.h"
#include "stack.h"
#include "ds.h"
#include "array.h"

typedef struct graph graph;
struct graph {
    //int size;
    ds *disjointSet;
    array *vertices;
    array *edges;
};

extern graph *newGraph(array *vertices, array *edges);
extern void printGraph(graph *g, int root);
extern void bfsPrint(graph *g, int root);
extern void makeCorrectSets(ds *d);
extern void heapToGraph(graph *g, heap *h);
extern void bfsPrintOld(graph *g, int root);


#endif
